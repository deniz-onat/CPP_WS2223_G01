#include"rook.hpp"
#include "piece.hpp"

Rook::Rook(Color color, Type type)
    : Piece::Piece(color,type), _hasMoved(false){}
