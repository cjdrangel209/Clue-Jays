#include "../header/playerClass.h"

Player::Player() {
	this->name = "";
	this->currentHallway = nullptr;
	this->currentRoom = nullptr;
	this->hand = {};
}

// Parameterized constructor that accepts a player's name and their starting hallway
Player::Player(std::string name, Hallway* startingHallway) {
	this->name = name;
	this->currentHallway = startingHallway;
	this->currentRoom = nullptr;
	this->hand = {};
}

// Getter for the player's name
std::string Player::getName() const {
	return this->name;
}

// Setter for the player's name
void Player::setName(std::string name) {
	this->name = name;
}

// Getter for the current room position of the player
Room* Player::getCurrentRoom() const {
	return this->currentRoom;
}

// Setter for the current room position
void Player::setCurrentRoom(Room* room) {
	this->currentRoom = room;
}

// Getter for the current hallway position of the player
Hallway* Player::getCurrentHallway() const {
	return this->currentHallway;
}

// Setter for the current hallway position
void Player::setCurrentHallway(Hallway* hallway) {
	this->currentHallway = hallway;
}

// Adds a card to the player's hand
void Player::addCard(Card card) {
	this->hand.push_back(card);
}

// Gets the list of cards in the player's hand
std::vector<Card> Player::getCards() const {
	return this->hand;
}