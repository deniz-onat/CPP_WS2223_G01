#ifndef NULLPIECE_H
#define NULLPIECE_H
#include "piece.hpp"

class NullPiece : public Piece
{
public:
    NullPiece(Color color = none, Type type = empty);
};

#endif // NULLPIECE_H
