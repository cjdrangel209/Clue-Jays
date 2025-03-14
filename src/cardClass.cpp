#include "../header/cardClass.h"

// Default constructor that initializes the card with a null name and 0 for the category
Card::Card() {
	name = "";
	category = 0;
}

// Parameterized constructor that initializes the card with a name and category
// category 1: person, 2: weapon, 3: room
Card::Card(std::string name, int category) {
	this->name = name;
	this->category = category;
}

// Getter for the card's name
std::string Card::getName() const {
	return this->name;
}

// Setter for the card's name
void Card::setName(std::string name) {
	this->name = name;
}

// Getter for the card's category
int Card::getCategory() const {
	return this->category;
}

// Setter for the card's category
void Card::setCategory(int category) {
	this->category = category;
}