#include "client.h"
#include<iostream>
#include<QDebug>

Client::Client(QObject *parent):QObject(parent),_port(0),_hostAddres(QString::fromStdString("0"))
{}


void Client::connectToServer(){
    //quint16 port =_ui->portField->text().toShort();   will be implemented in the gui first

    auto socket = new QTcpSocket(this);
    qDebug()<<"Connecting to "<<_hostAddres <<":"<<_port;
    socket->connectToHost(_hostAddres,_port);

    connect(socket,SIGNAL(connected()),this,SLOT(enableConnection()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()));
    connect(socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(socketError()));
    connect(socket,SIGNAL(destroyed()),this,SLOT(closeConnection()));
    connect(socket,SIGNAL(readyRead()),this,SLOT(recieveSignal()));

}

void Client::disconnectFromServer(){
    dynamic_cast<QTcpSocket*>(_InOutStream.device())->disconnectFromHost();
}

void Client::enableConnection(){
    assert(QObject::sender() != nullptr);

    qDebug()<<"connected";

    _InOutStream.setDevice(dynamic_cast<QTcpSocket*>(QObject::sender()));
    /*some connect statements that connect:
     *
     *
*/

}

void Client::disconnected(){

    qDebug()<<"disconnecting and deleting socket"; // for debugging
    _InOutStream.device()->deleteLater();
    emit guiCloseNotification();
}

void Client::closeConnection(){
    _InOutStream.setDevice(nullptr);

}

void Client::socketError(){
    std::cout<<"connection closed or failed"<<std::endl;
    _InOutStream.device()->deleteLater();
    emit guiCloseNotification();
}

void Client::setHostAddres(QString addres){
    _hostAddres = addres;
}

void Client::setPort(QString port){
    _port = port.toShort();
}

void Client::recieveSignal(){
    quint8 cmd,length,firstToGo,gruppennummer,startRow,startColumn,targetRow,targetColumn,extraInfo,status;
    _InOutStream>>cmd;
    switch(cmd){
    case 1:
       {
        _InOutStream>>length>>firstToGo>>gruppennummer;
        sendSignal(2);
        emit startingSide(firstToGo);
        if(firstToGo==0){
            emit startGui(1);
            emit colorSelection(0);
        }
        else{
            emit startGui(0);
            emit colorSelection(1);
        }
        emit launchGui();
        qDebug()<< "client recieved: "<<cmd<<length<<firstToGo<<gruppennummer;
        break;
    }
    case 3:
       {
        _InOutStream>>length>>startColumn>>startRow>>targetColumn>>targetRow>>extraInfo;
        qDebug()<<"client recieved: "<<cmd << length << startColumn << startRow << targetColumn << targetRow << extraInfo ;
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
    default:
    {
        break;
    }
}

}

void Client::sendSignal(quint8 cmd,quint8 startRow ,
                        quint8 startColumn ,quint8 targetRow ,quint8 targetColumn,quint8 promotionType,quint8 concequense ,quint8 status){
    quint8 groupNum  = 1;
    quint8 length;
    switch (cmd) {

    case 2:
    {
        length = 1;

        _InOutStream << cmd << length << groupNum;
        qDebug()<<"client sent 2 1 1";
        break;
    }
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


