#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
public:
    // Default constructor that initializes the card with a null name and 0 for the category
    Card();
    
    // Parameterized constructor that initializes the card with a name and category
    // category 1: person, 2: weapon, 3: room
    Card(std::string name, int category);

    // Getter for the card's name
    std::string getName() const;

    // Setter for the card's name
    void setName(std::string name);

    // Getter for the card's category
    int getCategory() const;

    // Setter for the card's category
    void setCategory(int category);

private:
    std::string name; // The name of the card (e.g., "Candlestick")
    int category;     // The category of the card (1: person, 2: weapon, 3: room)
};

#endif // CARD_H
