#include "schach_board.h"
#include "interface.h"
#include "gameboard.hpp"
#include <QApplication>
#include "client.h"
#include "server.h"
#include <QDebug>


int main(int argc, char *argv[])
{
    Gameboard myBoard; //Logic
    myBoard.initGameboard();
    //myBoard.printBoard();


    Client myClient; //Client for Network
    Server  myServer;


    QApplication a(argc, argv);
    Board w; //GUI
    Interface in;

    //Connects between Logic, GUI, Network
    QObject::connect(&w, &Board::Buttonpos, &myBoard, &Gameboard::getClick); //GUI
    QObject::connect(&myBoard, &Gameboard::sendMove, &w, &Board::moveLabel); //GUI
    QObject::connect(&myBoard, &Gameboard::sendLegalMoves, &w, &Board::highLite); //GUI
    QObject::connect(&myBoard, &Gameboard::sendNotLegal, &w, &Board::NoMove); //GUI
    QObject::connect(&myBoard, &Gameboard::sendPromotion, &w, &Board::promptShow);
    QObject::connect(&w, &Board::mustPromote, &myBoard, &Gameboard::getPromotion);
    QObject::connect(&myBoard, &Gameboard::hasPromoted, &w, &Board::Promote);
    QObject::connect(&myBoard, &Gameboard::logicTurn, &w, &Board::gamePrompts);
    QObject::connect(&myBoard, &Gameboard::guiChecked, &w, &Board::checkedPrompt);
    QObject::connect(&myBoard, &Gameboard::endGame, &w, &Board::matePrompt);


    //Network Logic
    QObject::connect(&myClient, &Client::triggerMove, &myBoard, &Gameboard::networkInput);
    QObject::connect(&myServer, &Server::triggerMove, &myBoard, &Gameboard::networkInput);

    QObject::connect(&myClient, &Client::colorSelection, &myBoard, &Gameboard::setPlayerColor);
    QObject::connect(&myServer, &Server::colorSelection, &myBoard, &Gameboard::setPlayerColor);


    QObject::connect(&myBoard, &Gameboard::networkSendMove, &myServer, &Server::sendSignal);
    QObject::connect(&myBoard, &Gameboard::networkSendMove, &myClient, &Client::sendSignal);


    QObject::connect(&in, &Interface::_Adrr, &myClient, &Client::setHostAddres);
    QObject::connect(&in, &Interface::_Port, &myClient, &Client::setPort);
//    if(in.serving){
//        qDebug()<<"Device is Host";
    QObject::connect(in.startBut, &QPushButton::clicked, &myServer, &Server::initServer);
    QObject::connect(in.endBut, &QPushButton::clicked, &myServer, &Server::closeConnection);


    QObject::connect(in.conBut, &QPushButton::clicked, &myClient, &Client::connectToServer);
    QObject::connect(in.disCon, &QPushButton::clicked, &myClient, &Client::disconnectFromServer);

    QObject::connect(&myServer, &Server::startGui, &w, &Board::startBoard);
    QObject::connect(&myClient, &Client::startGui, &w, &Board::startBoard);

    QObject::connect(&myServer, &Server::guiCloseNotification, &in, &Interface::switchButt);
    QObject::connect(&myClient, &Client::guiCloseNotification, &in, &Interface::switchButt);

//    QObject::connect(&myServer, &Server::guiCloseNotification, &w, &Board::reSetted);
//    QObject::connect(&myClient, &Client::guiCloseNotification, &w, &Board::reSetted);

    //QObject::connect(&myClient, &Client::launchGui, &in, [&](){in.conBut->setEnabled(false); in.disCon->setEnabled(true);});
    //QObject::connect(&myClient, &Client::launchGui, &w, [&](){w.show();});
    //QObject::connect(&myClient, &Client::launchGui, &in, [&](){in.conBut->setEnabled(false); in.disCon->setEnabled(true);});
    //QObject::connect(&myServer, &Server::launchGui, &w, [&](){w.show();});


    //w.show();
    in.show();

    return a.exec();
}
