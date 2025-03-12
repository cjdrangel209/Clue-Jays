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
    void MainMenu();

    void HallChoice(int choice);

    void RoomChoice(int choice, int option);
    //void RoomChoice(int choice, int option, std::vector<Hallway> halls);

    void Accusation();

    //void CheckPick(int character, int weapon, Room room)

    // std::vector<Character> player_list;
    std::vector<int> player_list;
    std::vector<std::string> all_char_list;
    std::vector<std::string> all_weapons_list;
    //std::vector<Card> answers;
    int player_num;
    int turn;
    bool win;
    //Halway h0;
    //Halway h1;
    //Halway h2;
    //Halway h3;
    //Halway h4;
    //Halway h5;
    //Halway h6;
    //Halway h7;
    //Halway h8;
    //Halway h9;
    //Halway h10;
    //Halway h11;

    //Room r0;
    //Room r1;
    //Room r2;
    //Room r3;
    //Room r4;
    //Room r5;
    //Room r6;
    //Room r7;
    //Room r8;
 

};

#endif //Exit Header Guard
