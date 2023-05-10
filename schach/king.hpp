#ifndef KING_HPP
#define KING_HPP
#include "piece.hpp"
#include <utility>

class King : public Piece{
public:
    King(Color color, Type type = king);

    bool isValidKingMove(int i, int j);

private:
    //bool isChecked;
    bool _hasMoved;
};

#endif

