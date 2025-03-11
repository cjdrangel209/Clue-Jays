//Title: ClueLess.h
//Author: Jon Deyton
//Date: 3/9/2025
//Description: Header file to start and maintain clue-less

#ifndef ClueLess_H //Header Guard
#define ClueLess_H //Header Guard
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>


class ClueLess {
public:
    /* Name: ClueLess() Default Constructor
    // Desc - Builds a new game by:
    // 1. 
    */
    ClueLess(); //Default Constructor

    // Name: StartGame()
    // Desc - Manages the game itself including win conditions continually calling the main menu 
    void StartGame();

    void BuildBoard();

    int GetPlayerNum();

    void WhoIsWho();

    // helper to add rooms and can also use to attach to character
    //void AttachHalls2Room(Hallway h1, Hallway h2, Room r)

    // Name: MainMenu()
    // Desc - Displays and manages menu
    int MainMenu();

    // std::vector<Character> player_list;
    std::vector<int> player_list;
    std::vector<std::string> all_char_list;
    int player_num;

};

#endif //Exit Header Guard
