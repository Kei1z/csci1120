#include "player.h"
#include <iostream>
using namespace std;

Player::Player(string name, Color color) {
    this->name = name;
    this->color = color;
}

string Player::getName() const {
    return name;
}

Color Player::getColor() const {
    return color;
}

int Player::getPieceCount() const {
    // TODO: 
    return pieces.size();
    // Return the size of the pieces vector
}

Piece* Player::getPiece(int i) const {
    // TODO: 
    return pieces.at(i);
    // Get the piece indexed at i from the pieces vector
}

void Player::addPiece(Piece* p) {
    // TODO: 
    pieces.push_back(p);
    // Add p to the pieces vector
}

void Player::delPiece(Piece* p) {
    // TODO: 
    pieces.erase(std::remove(pieces.begin(),pieces.end(),p),pieces.end());
    // Remove p from the pieces vector
}
