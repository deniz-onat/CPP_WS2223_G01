#ifndef PIECE_HPP
#define PIECE_HPP
#pragma once
#include <utility>

enum Color{black = 0,white = 1, none = 2};
enum Type {
    empty = 0,
    pawn = 1,
    knight = 2,
    bishop = 3,
    rook = 4,
    queen = 5,
    king = 6
};

class Piece{
    const Color _color;
    const Type _type;
    //bool _canMove;
public:
    Piece(Color color, Type type, bool _hasMoved = false);
    Type getType();
    Color getColor();
    ~Piece() = default;
    bool _hasMoved;

};
#endif 
