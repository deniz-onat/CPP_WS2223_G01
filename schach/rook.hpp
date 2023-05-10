#ifndef ROOK_HPP
#define ROOK_HPP
#include "piece.hpp"
#include <utility>

class Rook : public Piece{
public:
    Rook(Color color, Type type = rook);
    void move(int rank, int file);

private:
    bool _hasMoved;

};

#endif

