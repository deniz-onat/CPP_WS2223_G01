#include<iostream>
#include <memory>
#include <QDebug>
#include <vector>
#include <set>

#include "gameboard.hpp"
#include "piece.hpp"
#include "king.hpp"
#include "bishop.hpp"
#include "queen.hpp"
#include "knight.hpp"
#include "rook.hpp"
#include "pawn.hpp"
#include "nullpiece.h"

Gameboard::Gameboard(QObject *parent)    : QObject(parent), _turn(w), _kingChecked(false),_gameEnded(false){
    resetThreatGrid();
    resetVirtualGrid();
    connect(this, &Gameboard::getPromotionType, &Gameboard::getPromotion);
}

void Gameboard::initGameboard(){

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            board[i][j] = std::make_shared<NullPiece>(NullPiece());
        }
    }
    board[7][4] = std::make_shared<King>(King(black));
    board[7][3] = std::make_shared<Queen>(Queen(black));
    board[7][0] = std::make_shared<Rook>(Rook(black));
    board[7][7] = std::make_shared<Rook>(Rook(black));
    board[7][2] = std::make_shared<Bishop>(Bishop(black));
    board[7][5] = std::make_shared<Bishop>(Bishop(black));
    board[7][1] = std::make_shared<Knight>(Knight(black));
    board[7][6] = std::make_shared<Knight>(Knight(black));

    for(int i = 0; i < 8; i++){
        board[6][i] = std::make_shared<Pawn>(Pawn(black));
    }

    board[0][4] = std::make_shared<King>(King(white));
    board[0][3] = std::make_shared<Queen>(Queen(white));
    board[0][0] = std::make_shared<Rook>(Rook(white));
    board[0][7] = std::make_shared<Rook>(Rook(white));
    board[0][2] = std::make_shared<Bishop>(Bishop(white));
    board[0][5] = std::make_shared<Bishop>(Bishop(white));
    board[0][1] = std::make_shared<Knight>(Knight(white));
    board[0][6] = std::make_shared<Knight>(Knight(white));

    for(int i = 0; i < 8; i++){
        board[1][i] = std::make_shared<Pawn>(Pawn(white));
    }
}

void Gameboard::setPlayerColor(int color){
    playerColor = color;
}

void Gameboard::networkInput(int fromX, int fromY, int toX, int toY, int promotionType, int consequence){
    if(playerColor != (int)_turn && !(_gameEnded)){


        getLegalMoves(fromX,fromY);
        if(isMoveLegal(toX,toY)){
            move(fromX, fromY, toX, toY);
            emit sendMove(fromX, fromY, toX, toY);
            if(promotionType != 0){
                networkPromotion = true;
                _promX = toX;
                _promY = toY;
                promote(_promX,_promY);
                emit getPromotionType(promotionType);
                //getPromotion(promotionType);

            }
            if(consequence == 4){
                hasCastled(fromY,toX,toY);
            }
            getThreats();
            isKingChecked(); //emit kingChecked
            getKingPosition();
            changeTurn();
            hasGameEnded();
            networkPromotion = false;
        }
    }
}

void Gameboard::getClick(int x, int y){
    if(playerColor == (int)_turn){

        auto myColor = board[x][y]->getColor();
        if((_firstClick)){
            if((int)myColor == playerColor && !(_gameEnded))
            {
                getLegalMoves(x,y);
                _fromX = x;
                _fromY = y;
                emit sendLegalMoves(_legalMoves, _fromX, _fromY); //GUI
                _firstClick = false;
            }
        }
        else{
            if(isMoveLegal(x,y)){
                move(_fromX,_fromY,x,y);
                emit sendMove(_fromX, _fromY, x,y); //GUI

                promote(x,y);
                getThreats();
                isKingChecked();
                getKingPosition();

                changeTurn();
                hasGameEnded();



                if (board[x][y]->getType() == pawn){
                    if(!(x == 0 || x == 7)){
                        if(_captured)
                            emit networkSendMove(3,_fromX, _fromY, x, y, 0, 1, 0);
                        else
                            emit networkSendMove(3,_fromX, _fromY, x, y, 0, 0, 0);
                    }

                }
                else{
                    if(hasCastled(_fromY,x,y)){
                        emit networkSendMove(3,_fromX, _fromY, x, y, 0, 4, 0); //if statements for extra info

                    }
                    else{
                        if(_captured)
                            emit networkSendMove(3,_fromX, _fromY, x, y, 0, 1, 0);
                        else
                            emit networkSendMove(3,_fromX, _fromY, x, y, 0, 0, 0);
                    }
                }
            }
            else{
                emit sendNotLegal(); //GUI
            }
            _firstClick = true;
        }
    }
}

void Gameboard::changeTurn(){
    _turn = (_turn == b) ? w : b;
    emit logicTurn(int(_turn));
}

void Gameboard::promote(int x, int y){

    if(board[x][y]->getType() == pawn){
        if((x == 7) || (x == 0)){
            _promX = x;
            _promY = y;
            emit sendPromotion(x);
        }
    }
}

bool Gameboard::hasCastled(int fromY, int x, int y){
    if(board[x][y]->getType() == king){
        if(board[x][y]->getColor() == white){
            if(fromY == (y - 2)){
                castle(4);
                return true;
            }
            else if(fromY == (y + 2)){
                castle(3);
                return true;
            }
        }
        else if(board[x][y]->getColor() == black){
            if(fromY == (y - 2)){
                castle(2);
                return true;
            }
            else if(fromY == (y + 2)){
                castle(1);
                return true;
            }
        }
    }
    return false;

}

void Gameboard::castle(int type){
    switch (type){

        //black long
        case 1:
            move(7,0,7,3);
            emit sendMove(7,0,7,3);            
            break;

        //black short
        case 2:
            move(7,7,7,5);
            emit sendMove(7,7,7,5);
            break;

        //white long
        case 3:
            move(0,0,0,3);
            emit sendMove(0,0,0,3);
            break;

        //white short
        case 4:
            move(0,7,0,5);
            emit sendMove(0,7,0,5);
            break;

        default:
            break;
    }
    _castleType = 0;
}

void Gameboard::isKingChecked(){
    for(int i = 0; i <8; i++){
        for(int j = 0; j < 8; j++){
            if(_turn == w){
                if(board[i][j]->getColor() == black && board[i][j]->getType() == king && threatGrid[i][j]){

                    qDebug() << _turn << "Black king is in check!";
                    _kingChecked = true;
                    emit guiChecked();
                    return;
                }

            }
            else{
                if(board[i][j]->getColor() == white && board[i][j]->getType() == king && threatGrid[i][j]){

                    qDebug() << "White king is in check!";
                    _kingChecked = true;
                    emit guiChecked();
                    return;
                }

            }
        }
    }
    _kingChecked = false;
}

void Gameboard::hasGameEnded(){
    size_t legalMoveCount = 0;
    int knightCount = 0;
    int bishopCount = 0;
    int pieceCount = 0;

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(board[i][j]->getType() != empty){
                pieceCount++;
                if(board[i][j]->getType() == knight){
                    knightCount++;
                }
                else if(board[i][j]->getType() == bishop){
                    bishopCount++;
                }
            }
        }
    }
    if(pieceCount == 3){
        if(bishopCount == 1 || knightCount == 1){
            qDebug() << "insufficient material";
            emit endGame(3,0);   //insufficient material
            _gameEnded = true;
            return;
        }
    }
    else if(pieceCount == 2){
        qDebug() << "insufficient material";
        emit endGame(3,0);     //insufficient material
        _gameEnded = true;
        return;
    }
    else{
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(board[i][j]->getColor() == white && _turn  == w){
                    legalMoveCount += getLegalMoves(i,j).size();
                    if(legalMoveCount > 0)
                        return;
                }
                else if(board[i][j]->getColor() == black && _turn  == b){
                    legalMoveCount += getLegalMoves(i,j).size();
                    if(legalMoveCount > 0)
                        return;
                }

            }
        }
        qDebug() << legalMoveCount;

        if(_kingChecked){
            qDebug() << "Checkmate! " << _turn << " lost";
            emit endGame(1, (int)_turn); //checkmate
            _gameEnded = true;
            return;

        }
        else{
            qDebug() << "haha stalemate" ;
            emit endGame(2, 0); //stalemate, turn not important while emitting
            _gameEnded = true;
            return;
                    }
    }

}

bool Gameboard::isMoveLegal(int x, int y){
    for(std::pair<int,int> a: _legalMoves){
        if(x == a.first && y == a.second){
            return true;
        }
    }
    return false;
}
void Gameboard::resetThreatGrid(){
    for(int i = 0; i <8; i++){
        for(int j = 0; j < 8; j++){
            threatGrid[i][j] = 0;
        }
    }
}
void Gameboard::resetVirtualGrid(){
    for(int i = 0; i <8; i++){
        for(int j = 0; j < 8; j++){
            virtualGrid[i][j] = 0;
        }
    }
}




std::vector<std::pair<int,int>> Gameboard::getLegalMoves(int x, int y){

    _legalMoves = {};

    switch (board[x][y]->getType()){
        case pawn:
            pawnMoves(x,y);
            break;

        case knight:
            knightMoves(x,y);
            break;

        case bishop:
            bishopMoves(x,y);
            break;

        case rook:
            rookMoves(x,y);
            break;

        case queen:
            queenMoves(x,y);
            break;

        case king:
            kingMoves(x,y);
            break;

        default:
            break;
        }

    return _legalMoves;
}

void Gameboard::getThreats(){
    if(_turn == w){
        resetThreatGrid();
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(board[i][j]->getColor() == white){
                    switch(board[i][j]->getType()){
                    case knight:
                        knightThreatens(i,j, threatGrid);
                        break;
                    case bishop:
                        bishopThreatens(i,j, threatGrid);
                        break;
                    case pawn:
                        pawnThreatens(i,j, threatGrid);
                        break;
                    case rook:
                        rookThreatens(i,j, threatGrid);
                        break;
                    case queen:
                        queenThreatens(i,j, threatGrid);
                        break;
                    case king:
                        kingThreatens(i,j, threatGrid);
                        break;
                    default:
                        break;
                    }
                }
            }
        }
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(threatGrid[i][j]){

                    qDebug() << "White threatens: " << i+1 << j+1 ;
                }

            }
        }
    }
    else if(_turn == b){
        resetThreatGrid();
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(board[i][j]->getColor() == black){
                    switch(board[i][j]->getType()){
                    case knight:
                        knightThreatens(i,j, threatGrid);
                        break;
                    case bishop:
                        bishopThreatens(i,j, threatGrid);
                        break;
                    case pawn:
                        pawnThreatens(i,j, threatGrid);
                        break;
                    case rook:
                        rookThreatens(i,j, threatGrid);
                        break;
                    case queen:
                        queenThreatens(i,j, threatGrid);
                        break;
                    case king:
                        kingThreatens(i,j, threatGrid);
                        break;
                    default:
                        break;
                    }
                }
            }
        }
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(threatGrid[i][j]){

                    qDebug() << "Black threatens: " << i+1 << j+1 ;
                }
            }
        }
    }

}
void Gameboard::getVirtualThreats(){
    if(_turn == w){
        resetVirtualGrid();
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(board[i][j]->getColor() == black){
                    switch(board[i][j]->getType()){
                    case knight:
                        knightThreatens(i,j,virtualGrid);
                        break;
                    case bishop:
                        bishopThreatens(i,j, virtualGrid);
                        break;
                    case pawn:
                        pawnThreatens(i,j, virtualGrid);
                        break;
                    case rook:
                        rookThreatens(i,j, virtualGrid);
                        break;
                    case queen:
                        queenThreatens(i,j, virtualGrid);
                        break;
                    case king:
                        kingThreatens(i,j, virtualGrid);
                        break;
                    default:
                        break;
                    }
                }
            }
        }
    }
    else if(_turn == b){
        resetVirtualGrid();
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(board[i][j]->getColor() == white){
                    switch(board[i][j]->getType()){
                    case knight:
                        knightThreatens(i,j, virtualGrid);
                        break;
                    case bishop:
                        bishopThreatens(i,j,virtualGrid);
                        break;
                    case pawn:
                        pawnThreatens(i,j, virtualGrid);
                        break;
                    case rook:
                        rookThreatens(i,j, virtualGrid);
                        break;
                    case queen:
                        queenThreatens(i,j, virtualGrid);
                        break;
                    case king:
                        kingThreatens(i,j, virtualGrid);
                        break;
                    default:
                        break;
                    }
                }
            }
        }
    }

}

void Gameboard::getPromotion(int type){

    switch(type){
        //Queen
        case 4:
            if(_promX == 7){
                board[_promX][_promY] = std::make_shared<Queen>(Queen(white));
            }
            else if(_promX == 0){
                board[_promX][_promY] = std::make_shared<Queen>(Queen(black));
            }
            break;

        //Rook
        case 3:
            if(_promX == 7){
                board[_promX][_promY] = std::make_shared<Rook>(Rook(white));
            }
            else if(_promX == 0){
                board[_promX][_promY] = std::make_shared<Rook>(Rook(black));
            }
            break;

        //Knight
        case 2:
            if(_promX == 7){
                board[_promX][_promY] = std::make_shared<Knight>(Knight(white));
            }
            else if(_promX == 0){
                board[_promX][_promY] = std::make_shared<Knight>(Knight(black));
            }
            break;

        //Bishop
        case 1:
            if(_promX == 7){
                board[_promX][_promY] = std::make_shared<Bishop>(Bishop(white));
            }
            else if(_promX == 0){
                board[_promX][_promY] = std::make_shared<Bishop>(Bishop(black));
            }
            break;

        default:
            break;
    }
    emit hasPromoted(_promX,_promY,type);

    if(!(networkPromotion))
        emit networkSendMove(3, _fromX, _fromY,  _promX, _promY, type, 0, 0);

}


void Gameboard::getKingPosition(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if((int)_turn == (int)board[i][j]->getColor() && board[i][j]->getType() == king){
                _kingPosition.first = i;
                _kingPosition.second = j;

                return;
            }


        }
    }
}
void Gameboard::move(int fromX, int fromY, int toX, int toY){

        _captured = false;
        if(board[toX][toY]->getType() != empty)
            _captured = true;

        board[toX][toY] = board[fromX][fromY];
        board[fromX][fromY] = std::make_shared<NullPiece>(NullPiece());
        board[toX][toY]->_hasMoved = true;
}



void Gameboard::pawnMoves(int x, int y){

    //Goes up the board
    if(board[x][y]->getColor() == white)
    {
        if(board[x+1][y]->getType() == empty)
        {
            //auto a = board[x][y];
            board[x+1][y] = board[x][y];
            board[x][y] = std::make_shared<NullPiece>(NullPiece());
            getKingPosition();
            getVirtualThreats();
            if(!(virtualGrid[_kingPosition.first][_kingPosition.second])){

                _legalMoves.push_back(std::pair<int,int>(x+1,y));
                //resetVirtualGrid();
            }

            //reverse mock move
            board[x][y] = board[x+1][y];
            board[x+1][y] = std::make_shared<NullPiece>(NullPiece());

            if(board[x][y]->_hasMoved == false && board[x+2][y]->getType() == empty){


                board[x+2][y] = board[x][y];
                board[x][y] = std::make_shared<NullPiece>(NullPiece());
                getKingPosition();
                getVirtualThreats();
                if(!(virtualGrid[_kingPosition.first][_kingPosition.second])){

                    _legalMoves.push_back(std::pair<int,int>(x+2,y));
                    //resetVirtualGrid();
                }

                //reverse mock move
                board[x][y] = board[x+2][y];
                board[x+2][y] = std::make_shared<NullPiece>(NullPiece());
            }
        }
        if(x-1 >= 0 && x+1 < 8)
        {
            if(y+1 < 8){

                if(board[x+1][y+1]->getColor() == black){

                    auto a = board[x+1][y+1];
                    board[x+1][y+1] = board[x][y];
                    board[x][y] = std::make_shared<NullPiece>(NullPiece());
                    getKingPosition();
                    getVirtualThreats();
                    if(!(virtualGrid[_kingPosition.first][_kingPosition.second])){

                        _legalMoves.push_back(std::pair<int,int>(x+1,y+1));
                        //resetVirtualGrid();
                    }

                    //reverse mock move
                    board[x][y] = board[x+1][y+1];
                    board[x+1][y+1] = a;
                }
            }
            if(y-1 >= 0){
                if(board[x+1][y-1]->getColor() == black){

                    auto a = board[x+1][y-1];
                    board[x+1][y-1] = board[x][y];
                    board[x][y] = std::make_shared<NullPiece>(NullPiece());
                    getKingPosition();
                    getVirtualThreats();
                    if(!(virtualGrid[_kingPosition.first][_kingPosition.second])){

                        _legalMoves.push_back(std::pair<int,int>(x+1,y-1));
                        //resetVirtualGrid();
                    }

                    //reverse mock move
                    board[x][y] = board[x+1][y-1];
                    board[x+1][y-1] = a;
                }
            }
        }
    }
    //Goes down
    else
    {
        if(board[x-1][y]->getType() == empty)
        {
            board[x-1][y] = board[x][y];
            board[x][y] = std::make_shared<NullPiece>(NullPiece());
            getKingPosition();
            getVirtualThreats();
            if(!(virtualGrid[_kingPosition.first][_kingPosition.second])){

                _legalMoves.push_back(std::pair<int,int>(x-1,y));
                //resetVirtualGrid();
            }

            //reverse mock move
            board[x][y] = board[x-1][y];
            board[x-1][y] = std::make_shared<NullPiece>(NullPiece());

            if(board[x][y]->_hasMoved == false && board[x-2][y]->getType() == empty){


                board[x-2][y] = board[x][y];
                board[x][y] = std::make_shared<NullPiece>(NullPiece());
                getKingPosition();
                getVirtualThreats();
                if(!(virtualGrid[_kingPosition.first][_kingPosition.second])){

                    _legalMoves.push_back(std::pair<int,int>(x-2,y));
                    //resetVirtualGrid();
                }

                //reverse mock move
                board[x][y] = board[x-2][y];
                board[x-2][y] = std::make_shared<NullPiece>(NullPiece());
            }


        }
        if(x-1>= 0 && x+1 < 8)
        {
            if(y+1 < 8){
                if(board[x-1][y+1]->getColor() == white){
                    auto a = board[x-1][y+1];
                    board[x-1][y+1] = board[x][y];
                    board[x][y] = std::make_shared<NullPiece>(NullPiece());
                    getKingPosition();
                    getVirtualThreats();
                    if(!(virtualGrid[_kingPosition.first][_kingPosition.second])){

                        _legalMoves.push_back(std::pair<int,int>(x-1,y+1));
                        //resetVirtualGrid();
                    }

                    //reverse mock move
                    board[x][y] = board[x-1][y+1];
                    board[x-1][y+1] = a;
                }
            }
            if(y-1 >= 0){
                if(board[x-1][y-1]->getColor() == white){

                    auto a = board[x-1][y-1];
                    board[x-1][y-1] = board[x][y];
                    board[x][y] = std::make_shared<NullPiece>(NullPiece());
                    getKingPosition();
                    getVirtualThreats();
                    if(!(virtualGrid[_kingPosition.first][_kingPosition.second])){

                        _legalMoves.push_back(std::pair<int,int>(x-1,y-1));
                        //resetVirtualGrid();
                    }

                    //reverse mock move
                    board[x][y] = board[x-1][y-1];
                    board[x-1][y-1] = a;
                }
            }
        }

    }
}

void Gameboard::knightMoves(int x, int y){

    int knightX[8] = { 2, 1, -1, -2, -2, -1, 1, 2}; //for knight
    int knightY[8] = { 1, 2, 2, 1, -1, -2, -2, -1}; //for knight

    int tmpX = x;
    int tmpY = y;
    auto myColor = board[tmpX][tmpY]->getColor();


    for(int i = 0; i < 8; i++){
        x = tmpX + knightX[i];
        y = tmpY + knightY[i];

        if(x >= 0 && y >= 0 && x < 8 && y < 8)
        {
            if(myColor != board[x][y]->getColor()){

                auto a = board[x][y];
                board[x][y] = board[tmpX][tmpY];
                board[tmpX][tmpY] = std::make_shared<NullPiece>(NullPiece());
                getKingPosition();
                getVirtualThreats();
                if(!(virtualGrid[_kingPosition.first][_kingPosition.second])){

                    _legalMoves.push_back(std::pair<int,int>(x,y));
                    //resetVirtualGrid();
                }

                //reverse mock move
                board[tmpX][tmpY] = board[x][y];
                board[x][y] = a;
            }

        }
    }
}




void Gameboard::bishopMoves(int x, int y){

    int dirX[8] = { -1, 1, 0, 0, -1, 1, -1, 1};  //for other pieces
    int dirY[8] = { 0, 0, -1, 1, 1, -1, -1, 1};  //for other pieces

    int tmpX = x;
    int tmpY = y;
    auto myColor = board[tmpX][tmpY]->getColor();

    for(int i = 4; i < 8; i++){
        for(int j = 1; j < 8; j++){
            x = tmpX + j * dirX[i];
            y = tmpY + j * dirY[i];
            if(x >= 0 && y >= 0 && x < 8 && y < 8)
            {
                if(board[x][y]->getColor() == none){
                    auto a = board[x][y];
                    board[x][y] = board[tmpX][tmpY];
                    board[tmpX][tmpY] = std::make_shared<NullPiece>(NullPiece());
                    getKingPosition();
                    getVirtualThreats();
                    if(!(virtualGrid[_kingPosition.first][_kingPosition.second])){

                        _legalMoves.push_back(std::pair<int,int>(x,y));
                        //resetVirtualGrid();
                    }

                    //reverse mock move
                    board[tmpX][tmpY] = board[x][y];
                    board[x][y] = a;
                }
                else if(myColor == board[x][y]->getColor()){
                    break;
                }
                else{
                    auto a = board[x][y];
                    board[x][y] = board[tmpX][tmpY];
                    board[tmpX][tmpY] = std::make_shared<NullPiece>(NullPiece());
                    getKingPosition();
                    getVirtualThreats();
                    if(!(virtualGrid[_kingPosition.first][_kingPosition.second])){

                        _legalMoves.push_back(std::pair<int,int>(x,y));
                        //resetVirtualGrid();
                    }

                    //reverse mock move
                    board[tmpX][tmpY] = board[x][y];
                    board[x][y] = a;
                    break;
                }
            }
        }
    }
}

void Gameboard::rookMoves(int x,int y){
    int tmpX = x;
    int tmpY = y;
    auto myColor = board[tmpX][tmpY]->getColor();

    int dirX[8] = { -1, 1, 0, 0, -1, 1, -1, 1};  //for other pieces
    int dirY[8] = { 0, 0, -1, 1, 1, -1, -1, 1};  //for other pieces

    for(int i = 0; i < 4; i++){
        for(int j = 1; j < 8; j++){
            x = tmpX + j * dirX[i];
            y = tmpY + j * dirY[i];
            if(x >= 0 && y >= 0 && x < 8 && y < 8)
            {
                if(board[x][y]->getColor() == none){
                    auto a = board[x][y];
                    board[x][y] = board[tmpX][tmpY];
                    board[tmpX][tmpY] = std::make_shared<NullPiece>(NullPiece());
                    getKingPosition();
                    getVirtualThreats();
                    if(!(virtualGrid[_kingPosition.first][_kingPosition.second])){

                        _legalMoves.push_back(std::pair<int,int>(x,y));
                        //resetVirtualGrid();
                    }

                    //reverse mock move
                    board[tmpX][tmpY] = board[x][y];
                    board[x][y] = a;
                }
                else if(myColor == board[x][y]->getColor()){
                    break;
                }
                else{
                    auto a = board[x][y];
                    board[x][y] = board[tmpX][tmpY];
                    board[tmpX][tmpY] = std::make_shared<NullPiece>(NullPiece());
                    getKingPosition();
                    getVirtualThreats();
                    if(!(virtualGrid[_kingPosition.first][_kingPosition.second])){

                        _legalMoves.push_back(std::pair<int,int>(x,y));
                        //resetVirtualGrid();
                    }

                    //reverse mock move
                    board[tmpX][tmpY] = board[x][y];
                    board[x][y] = a;
                    break;
                }
            }
        }
    }
}

void Gameboard::queenMoves(int x,int y){
    int tmpX = x;
    int tmpY = y;
    auto myColor = board[tmpX][tmpY]->getColor();

    int dirX[8] = { -1, 1, 0, 0, -1, 1, -1, 1};  //for other pieces
    int dirY[8] = { 0, 0, -1, 1, 1, -1, -1, 1};  //for other pieces

    for(int i = 0; i < 8; i++){
        for(int j = 1; j < 8; j++){
            x = tmpX + j * dirX[i];
            y = tmpY + j * dirY[i];
            if(x >= 0 && y >= 0 && x < 8 && y < 8)
            {
                if(board[x][y]->getColor() == none){
                    auto a = board[x][y];
                    board[x][y] = board[tmpX][tmpY];
                    board[tmpX][tmpY] = std::make_shared<NullPiece>(NullPiece());
                    getKingPosition();
                    getVirtualThreats();
                    if(!(virtualGrid[_kingPosition.first][_kingPosition.second])){

                        _legalMoves.push_back(std::pair<int,int>(x,y));
                        //resetVirtualGrid();
                    }

                    //reverse mock move
                    board[tmpX][tmpY] = board[x][y];
                    board[x][y] = a;
                }
                else if(myColor == board[x][y]->getColor()){
                    break;
                }
                else{
                    auto a = board[x][y];
                    board[x][y] = board[tmpX][tmpY];
                    board[tmpX][tmpY] = std::make_shared<NullPiece>(NullPiece());
                    getKingPosition();
                    getVirtualThreats();
                    if(!(virtualGrid[_kingPosition.first][_kingPosition.second])){

                        _legalMoves.push_back(std::pair<int,int>(x,y));
                        //resetVirtualGrid();
                    }

                    //reverse mock move
                    board[tmpX][tmpY] = board[x][y];
                    board[x][y] = a;
                    break;
                }
            }
        }
    }
}

void Gameboard::kingMoves(int x,int y){
    int tmpX = x;
    int tmpY = y;
    auto myColor = board[tmpX][tmpY]->getColor();

    int dirX[8] = { -1, 1, 0, 0, -1, 1, -1, 1};  //for other pieces
    int dirY[8] = { 0, 0, -1, 1, 1, -1, -1, 1};  //for other pieces

    for(int i = 0; i < 8; i++){
        x = tmpX + dirX[i];
        y = tmpY + dirY[i];

        if(x >= 0 && y >= 0 && x < 8 && y < 8)
        {
            if((board[x][y]->getColor() != myColor)){ //(threatGrid[x][y] == false &&

                auto a = board[x][y];
                board[x][y] = board[tmpX][tmpY];
                board[tmpX][tmpY] = std::make_shared<NullPiece>(NullPiece());
                getKingPosition();
                getVirtualThreats();
                if(!(virtualGrid[_kingPosition.first][_kingPosition.second])){

                    _legalMoves.push_back(std::pair<int,int>(x,y));
                    //resetVirtualGrid();
                }

                //reverse mock move
                board[tmpX][tmpY] = board[x][y];
                board[x][y] = a;
            }
        }
    }
    //Check for castling and add to legalmoves
    if(board[tmpX][tmpY]->_hasMoved == false &&
        !(_kingChecked) &&   board[tmpX][tmpY+3]->_hasMoved == false &&
            threatGrid[tmpX][tmpY+1] == false && threatGrid[tmpX][tmpY+2] == false &&
            board[tmpX][tmpY+1]->getType() == empty && board[tmpX][tmpY+2]->getType() == empty){

        _legalMoves.push_back(std::pair<int,int>(tmpX,tmpY+2));
    }
    if(board[tmpX][tmpY]->_hasMoved == false &&
            !(_kingChecked) &&   board[tmpX][tmpY-4]->_hasMoved == false &&
                threatGrid[tmpX][tmpY-1] == false && threatGrid[tmpX][tmpY-2] == false &&
                board[tmpX][tmpY-1]->getType() == empty && board[tmpX][tmpY-2]->getType() == empty){
         _legalMoves.push_back(std::pair<int,int>(tmpX,tmpY-2));

    }

}


void Gameboard::knightThreatens(int x, int y,bool grid[8][8]){
    int knightX[8] = { 2, 1, -1, -2, -2, -1, 1, 2}; //for knight
    int knightY[8] = { 1, 2, 2, 1, -1, -2, -2, -1}; //for knight

    int tmpX = x;
    int tmpY = y;

    for(int i = 0; i < 8; i++){
        x = tmpX + knightX[i];
        y = tmpY + knightY[i];

        if(x >= 0 && y >= 0 && x < 8 && y < 8)
        {
            grid[x][y] = 1;
        }
    }
}

void Gameboard::bishopThreatens(int x, int y, bool grid[8][8]){

    int dirX[8] = { -1, 1, 0, 0, -1, 1, -1, 1};  //for other pieces
    int dirY[8] = { 0, 0, -1, 1, 1, -1, -1, 1};  //for other pieces

    int tmpX = x;
    int tmpY = y;

    for(int i = 4; i < 8; i++){
        for(int j = 1; j < 8; j++){
            x = tmpX + j * dirX[i];
            y = tmpY + j * dirY[i];
            if(x >= 0 && y >= 0 && x < 8 && y < 8)
            {
                if(board[x][y]->getColor() == none){
                    grid[x][y] = 1;
                }
                else{
                    grid[x][y] = 1;
                    break;
                }
            }
        }
    }
}

void Gameboard::rookThreatens(int x, int y, bool grid[8][8]){
    int tmpX = x;
    int tmpY = y;


    int dirX[8] = { -1, 1, 0, 0, -1, 1, -1, 1};  //for other pieces
    int dirY[8] = { 0, 0, -1, 1, 1, -1, -1, 1};  //for other pieces

    for(int i = 0; i < 4; i++){
        for(int j = 1; j < 8; j++){
            x = tmpX + j * dirX[i];
            y = tmpY + j * dirY[i];
            if(x >= 0 && y >= 0 && x < 8 && y < 8)
            {
                if(board[x][y]->getColor() == none)
                    grid[x][y] = 1;

                else{
                    grid[x][y] = 1;
                    break;
                }


            }
        }
    }
}

void Gameboard::queenThreatens(int x, int y, bool grid[8][8]){
    int tmpX = x;
    int tmpY = y;


    int dirX[8] = { -1, 1, 0, 0, -1, 1, -1, 1};  //for other pieces
    int dirY[8] = { 0, 0, -1, 1, 1, -1, -1, 1};  //for other pieces

    for(int i = 0; i < 8; i++){
        for(int j = 1; j < 8; j++){
            x = tmpX + j * dirX[i];
            y = tmpY + j * dirY[i];
            if(x >= 0 && y >= 0 && x < 8 && y < 8)
            {
                if(board[x][y]->getColor() == none)
                    grid[x][y] = 1;


                else{
                    grid[x][y] = 1;
                    break;
                }

            }
        }
    }
}

void Gameboard::kingThreatens(int x, int y, bool grid[8][8]){
    int tmpX = x;
    int tmpY = y;


    int dirX[8] = { -1, 1, 0, 0, -1, 1, -1, 1};  //for other pieces
    int dirY[8] = { 0, 0, -1, 1, 1, -1, -1, 1};  //for other pieces

    for(int i = 0; i < 8; i++){
        x = tmpX + dirX[i];
        y = tmpY + dirY[i];

        if(x >= 0 && y >= 0 && x < 8 && y < 8)
        {
            grid[x][y] = 1;
        }
    }
}

void Gameboard::pawnThreatens(int x, int y, bool grid[8][8]){

    auto myColor = board[x][y]->getColor();

    if(myColor == white){
        if(x-1 >= 0 && x+1 < 8){
            if(y-1 >= 0)
                grid[x+1][y-1] = 1;

            if(y+1 < 8)
                grid[x+1][y+1] = 1;
        }
    }
    else if(myColor == black){
        if(x-1 >= 0 && x+1 < 8){
            if(y-1 >= 0)
                grid[x-1][y-1] = 1;

            if(y+1 < 8)
               grid[x-1][y+1] = 1;

        }
    }
}




