//Title: ClueLess.h
//Author: Jon Deyton
//Date: 3/9/2025
//Description: Header file to start and maintain clue-less

#ifndef ClueLess_H //Header Guard
#define ClueLess_H //Header Guard
#include <fstream>
#include "Material.h"
#include "Ship.h"
#include <string>

namespace clue{

class ClueLess {
public:
    /* Name: ClueLess() Default Constructor
    // Desc - Builds a new game by:
    // 1. 
    */
    ClueLess(); //Default Constructor

    // Name: StartGame()
    // Desc - Manages the game itself including win conditions continually
    //         calling the main menu 
    void StartGame();

    // Name: MainMenu()
    // Desc - Displays and manages menu. Also checks win condition (Ship reaches S rank).
    int MainMenu();

private:
    Ship m_myShip; //Player's Ship for the game
    Material m_materials[PROJ2_SIZE]; //All materials in the game (loaded from file)
};
}

#endif //Exit Header Guard
