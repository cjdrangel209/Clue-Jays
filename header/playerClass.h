#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Card.h"  // Assuming you already have the Card class header file

class Player {
public:
    // Default constructor
    Player();

    // Parameterized constructor
    Player(std::string name, Hallway* hallway);

    // Getters and setters
    std::string getName() const;
    void setName(const std::string& name);

    Hallway* getHallway() const;
    void setHallway(Hallway* hallway);

    Room* getRoom() const;
    void setRoom(Room* room);

    // Cards in hand (clue tracker)
    std::vector<Card> getCards() const;
    void setCards(const std::vector<Card>& cards);

private:
    std::string name;       // Name of the player
    Room* currentRoom;     // Player's current room (can be null)
    Hallway* currentHallway; // Player's current hallway (can be null)
    std::vector<Card> cardsInHand; // List of cards the player has
};

#endif // PLAYER_H
