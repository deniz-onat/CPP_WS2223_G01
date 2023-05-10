#include"pawn.hpp"
#include "piece.hpp"
#include <iostream>
#include <memory>

Pawn::Pawn(Color color, Type type)
    : Piece::Piece(color,type), _hasMoved(false) {}
