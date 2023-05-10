#include "server.h"
#include <random>
#include<iostream>
#include<QDebug>



Server::Server(QObject *parent)    : QObject(parent), tcpServer(nullptr),socket(nullptr){}

void Server::initServer(){

    tcpServer = new QTcpServer(this);

    quint16 port = 1234;


    tcpServer->setMaxPendingConnections(1);
    connect(tcpServer,SIGNAL(newConnection()),this,SLOT(setSocket()));
    tcpServer->listen(QHostAddress::Any,port);
    if(tcpServer->isListening())
     qDebug()<<"server is listening on port: 1234";
    else
        qDebug()<<"server isn't listening";





}




void Server::sendStartSignal(){


    //generating a random int in range(0,1)
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribution(0,1);
    firstoGo = quint8(distribution(gen));
    quint8 cmd = 1;
    quint8 length = 2;
    quint8 groupNum = 1;

    if(firstoGo == 0){
        std::cout<<"server starts"<<std::endl;
        emit colorSelection(1);
    }
    else if(firstoGo==1){
        std::cout<<"client starts"<<std::endl;
        emit colorSelection(0);
    }
    else{
        std::cout<<"error at numbber generating"<<std::endl;
        return;
    }
    emit startingSide(firstoGo);
    qDebug()<<"server sent: "<< cmd << length  <<  firstoGo << groupNum ;
    _InOutStream << cmd << length  <<  firstoGo << groupNum ;
}



void Server::recieveSignal(){
    quint8 cmd,length,gruppennummer,startRow,startColumn,targetRow,targetColumn,extraInfo,status;

    _InOutStream>>cmd;
    switch(cmd){
    case 2:
        _InOutStream>>length>>gruppennummer;
        qDebug()<<"server recieved:"<<cmd <<length << gruppennummer;
        emit startGui(int(firstoGo));
        //emit launchGui();
        break;
    case 3:
    {
        _InOutStream>>length>>startColumn>>startRow>>targetColumn>>targetRow>>extraInfo;
        qDebug()<<"server recieved: "<<cmd << length << startColumn << startRow << targetColumn << targetRow << extraInfo ;
        quint8 promotionType = (extraInfo & 0xf0) >> 4;
        quint8 consequence = (extraInfo & 0x0f);
//        int type = 0;
//        if(promotionType > 5){
//            type = 0;
//        }
//        else if(promotionType == 1){//((15 <  extraInfo)&&(extraInfo < 21)){
//           type=1; //bishop
//        }
//        else if(promotionType == 2){//((31 < extraInfo)&&(extraInfo   < 37)){
//            type = 2; //knight
//        }
//        else if(promotionType ==3){//((47 < extraInfo)&&(extraInfo  < 53)){
//            type =3; //rook
//        }
//        else if(promotionType ==4){//((63 < extraInfo)&&(extraInfo  < 69)){
//            type = 4; //queen
//        }
        emit triggerMove(int(startRow),int(startColumn),int(targetRow),int(targetColumn), promotionType, consequence );

        break;

    }
    case 4:
    {
        _InOutStream>>length>>status;
        if(status<3)
            emit turnFinished();
        break;
    }
    default:{
        break;
    }
}


}


void Server::sendSignal(quint8 cmd,quint8 startRow ,
                          quint8 startColumn,quint8 targetRow,quint8 targetColumn,quint8 promotionType,quint8 concequense,quint8 status ){


    switch (cmd) {
    quint8 length;
    case 3:
    {
        length = 5;
        quint8 extraInfo = ((promotionType<<4)&0xf0) | (concequense & 0x0f);

        _InOutStream << cmd << length << startColumn << startRow << targetColumn << targetRow << extraInfo;
        qDebug()<<"server sent: "<<cmd << length << startColumn << startRow << targetColumn << targetRow << extraInfo ;
        break;
    }
    case 4:
    {
        length = 1;
        _InOutStream << cmd << length << status ;
        break;
    }
    default:
    {
        break;
    }
    }
  }





void Server::setSocket(){
    socket = tcpServer->nextPendingConnection();
    _InOutStream.setDevice(socket);
    connect(socket,SIGNAL(readyRead()),this,SLOT(recieveSignal()));
    connect(socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(socketError()));
    connect(socket,SIGNAL(destroyed()),this,SLOT(closeConnection()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(closeConnection()));
    sendStartSignal();
    tcpServer->close();
    }



void Server::closeConnection() {
    qDebug()<<"closing connection";
    //dynamic_cast<QTcpSocket*>(_InOutStream.device())->disconnectFromHost();
    _InOutStream.setDevice(nullptr);
    socket->deleteLater();
    tcpServer->deleteLater();
    emit guiCloseNotification();

}

void Server::socketError(){
    qDebug()<<"connection failed or closed by the client";
    _InOutStream.setDevice(nullptr);
    socket->deleteLater();
    tcpServer->deleteLater();
    emit guiCloseNotification();
}
