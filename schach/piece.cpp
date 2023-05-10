#include"piece.hpp"


Piece::Piece(Color color,Type type, bool _hasMoved)
: _color(color),_type(type), _hasMoved(_hasMoved){}

Color Piece::getColor(){
    return _color;
}

Type Piece::getType(){
    return _type;
}
