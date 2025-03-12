/* File: view.h
 * Name: Sergio Diaz
 * Date: 3/12/25
 * Email: sdiaz1@umbc.edu
 * Description: This file has the class declarations for the Room and Hallway classes
*/

#ifndef VIEW_H
#define VIEW_H

#include <string>

// Forward declaration
class Hallway;

class Room {
public:
    // Constructors
    Room();
    Room(const std::string& name, Hallway* left, Hallway* right, Hallway* up, Hallway* down, Room* secretPassage);

    // Getters
    std::string getName() const;
    Hallway* getLeft() const;
    Hallway* getRight() const;
    Hallway* getUp() const;
    Hallway* getDown() const;
    Room* getSecretPassage() const;

    // Setters
    void setName(const std::string& name);
    void setLeft(Hallway* left);
    void setRight(Hallway* right);
    void setUp(Hallway* up);
    void setDown(Hallway* down);
    void setSecretPassage(Room* secretPassage);

private:
    std::string name;
    Hallway* left;
    Hallway* right;
    Hallway* up;
    Hallway* down;
    Room* secretPassage;
};

class Hallway {
public:
    // Constructors
    Hallway();
    Hallway(Room* left, Room* right, bool occupied);

    // Getters
    Room* getLeft() const;
    Room* getRight() const;
    bool getOccupied() const;

    // Setters
    void setLeft(Room* left);
    void setRight(Room* right);
    void setOccupied(bool occupied);

private:
    // Each hallway connects two rooms.
    class Room* left;
    class Room* right;
    bool occupied;
};

#endif // ROOM_HALLWAY_H
