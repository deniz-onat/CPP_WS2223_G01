#ifndef BISHOP_HPP
#define BISHOP_HPP
#include "piece.hpp"
#include <utility>
#include <memory>

class Bishop : public Piece{
public:

    Bishop(Color color, Type type = bishop);
    //void move(std::shared_ptr<Piece> from,int file, int rank);

private:
};


#endif

