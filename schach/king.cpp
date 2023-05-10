#include <iostream>
#include "king.hpp"
#include "piece.hpp"


King::King(Color color, Type type)
    : Piece::Piece(color,type), _hasMoved(false){}

