#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "../header/view.h" 
#include "../header/cardClass.h"    // Including Card class to manage player's hand

class Player {
public:
    // Default constructor that sets the player's name to null and positions to nullptr
    Player();
    
    // Parameterized constructor that accepts a player's name and their starting hallway
    Player(std::string name, Hallway* startingHallway);

    // Getter for the player's name
    std::string getName() const;

    // Setter for the player's name
    void setName(std::string name);

    // Getter for the current room position of the player
    Room* getCurrentRoom() const;

    // Setter for the current room position
    void setCurrentRoom(Room* room);

    // Getter for the current hallway position of the player
    Hallway* getCurrentHallway() const;

    // Setter for the current hallway position
    void setCurrentHallway(Hallway* hallway);

    // Adds a card to the player's hand
    void addCard(Card card);

    // Gets the list of cards in the player's hand
    std::vector<Card> getCards() const;

private:
    std::string name; // The name of the player
    Room* currentRoom; // The room where the player is located
    Hallway* currentHallway; // The hallway where the player is located
    std::vector<Card> hand; // The list of cards the player has
};

#endif // PLAYER_H

