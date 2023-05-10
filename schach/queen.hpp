#ifndef QUEEN_HPP
#define QUEEN_HPP
#include "piece.hpp"

class Queen: public Piece{
public:
    Queen(Color color, Type type = queen);
    
    void move(int rank, int file);
};

#endif //QUEEN_HPP
