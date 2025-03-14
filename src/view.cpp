/* File: view.h
 * Name: Sergio Diaz
 * Date: 3/12/25
 * Email: sdiaz1@umbc.edu
 * Description: This file contains the implementation for the Room and Hallway classes
*/

#include "../header/view.h"

Room::Room() 
    : name(""), left(nullptr), right(nullptr), up(nullptr), down(nullptr), secretPassage(nullptr) {}

Room::Room(const std::string& name, Hallway* left, Hallway* right, Hallway* up, Hallway* down, Room* secretPassage)
    : name(name), left(left), right(right), up(up), down(down), secretPassage(secretPassage) {}

std::string Room::getName() const {
    return name;
}

Hallway* Room::getLeft() const {
    return left;
}

Hallway* Room::getRight() const {
    return right;
}

Hallway* Room::getUp() const {
    return up;
}

Hallway* Room::getDown() const {
    return down;
}

Room* Room::getSecretPassage() const {
    return secretPassage;
}

void Room::setName(const std::string& name) {
    this->name = name;
}

void Room::setLeft(Hallway* left) {
    this->left = left;
}

void Room::setRight(Hallway* right) {
    this->right = right;
}

void Room::setUp(Hallway* up) {
    this->up = up;
}

void Room::setDown(Hallway* down) {
    this->down = down;
}

void Room::setSecretPassage(Room* secretPassage) {
    this->secretPassage = secretPassage;
}

Hallway::Hallway() 
    : left(nullptr), right(nullptr), occupied(false) {}

Hallway::Hallway(Room* left, Room* right, bool occupied)
    : left(left), right(right), occupied(occupied) {}

Room* Hallway::getLeft() const {
    return left;
}

Room* Hallway::getRight() const {
    return right;
}

bool Hallway::getOccupied() const {
    return occupied;
}

void Hallway::setLeft(Room* left) {
    this->left = left;
}

void Hallway::setRight(Room* right) {
    this->right = right;
}

void Hallway::setOccupied(bool occupied) {
    this->occupied = occupied;
}
