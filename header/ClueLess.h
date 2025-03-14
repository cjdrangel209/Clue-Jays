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
#include "../header/cardClass.h"
#include "../header/playerClass.h"
#include "../header/view.h"
#include "../header/deckDeal.h"

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

    void AttachHalls2Room(Hallway* h1, Room* rl, Room* rr);

    // Name: MainMenu()
    // Desc - Displays and manages menu
    void MainMenu();

    void HallChoice(int choice);

    void RoomChoice(int choice, int option, std::vector<Hallway*> halls, Room* secret);

    void Accusation();

    void CheckPick(int character, int weapon, Room* room);

    std::vector<Player> player_list;
    std::vector<std::string> all_char_list;
    std::vector<std::string> all_weapons_list;
    std::vector<Card> answers;
    int player_num;
    int turn;
    bool win;
    Hallway h0;
    Hallway h1;
    Hallway h2;
    Hallway h3;
    Hallway h4;
    Hallway h5;
    Hallway h6;
    Hallway h7;
    Hallway h8;
    Hallway h9;
    Hallway h10;
    Hallway h11;

    Room r0;
    Room r1;
    Room r2;
    Room r3;
    Room r4;
    Room r5;
    Room r6;
    Room r7;
    Room r8;
 

};

#endif //Exit Header Guard
