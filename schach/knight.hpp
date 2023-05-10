#ifndef KNIGHT_HPP
#define KNIGHT_HPP
#include "piece.hpp"

class Knight: public Piece{
public:
    Knight(Color colorm, Type type = knight);
    
    void move(int rank, int file);
};

#endif //KNIGHT_HPP
