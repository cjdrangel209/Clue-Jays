/*****************************************
** File:    ClueLess.cpp
** Author:  Jon Deyton
** Date:    3/9/25
**
** This contains the ClueLess functions
*/

#include "../header/ClueLess.h"

ClueLess::ClueLess(){
    this->all_char_list = { "Miss Scarlet", "Col. Mustard", "Mrs. White", "Prof. Plum", "Mrs. Peacock", "Mr. Green" };
    this->StartGame();
        

}

void ClueLess::StartGame() {
    // print out list of players and then who is who
    // need a list of character objects
    // need to create all rooms and hallways and connect them
    // give the characters the hallway (should be set from their)
    // initialize deck for players (give them the character objects so they can give them the cards)
    // game loops through players and gives them options
    
    // TODO: make all halways and room and implement AttachHalls2Room,
    // call deck, and implement main menu, make win condition

    this->player_num = GetPlayerNum();
    this->WhoIsWho();
    

    std::cout << this->player_num << std::endl;
        
       
}

void ClueLess::BuildBoard() {

}

int ClueLess::GetPlayerNum() {
    std::cout << "Welcome to CLUE-LESS!" << std::endl;
    std::cout << "Please enter the number of players (2-6)? " << std::endl;
    std::string num_player_str = "";
    int num_player = 0;

    bool not_int = true;
    while (not_int)
    {
        try {
            std::cin >> num_player_str;
            num_player = std::stoi(num_player_str);
            if (num_player <= 6 && num_player >= 2)
            {
                not_int = false;
            }
            else
            {
                std::cout << "Please enter a number between 2 and 6" << std::endl;
            }

        }
        catch (const std::invalid_argument& e) {
            std::cerr << "Error: Invalid input. Please enter a valid integer." << std::endl;
        }
    }
    return num_player;
}

void ClueLess::WhoIsWho() {
    // for as many players as there are have them select a character
    for (int i = 0; i < this->player_num; i++)
    {
        std::cout << "Player " << i + 1 << " please choose a character by entering the number " << std::endl;
        // print all available players
        for (int j = 0; j < this->all_char_list.size(); j++)
        {
            std::cout << j << ": " << this->all_char_list.at(j) << std::endl;
        }
        std::string choice_str = "";
        int choice = 0;

        bool not_int = true;
        while (not_int)
        {
            try {
                std::cin >> choice_str;
                choice = std::stoi(choice_str);
                if (choice < this->all_char_list.size() && choice >= 0)
                {
                    not_int = false;
                    
                    // create a character and add it to the vector
                    // Character character = Character(this->all_char_list.at(choice), nullptr);
                    // this->player_list.push_back(character);
                    this->player_list.push_back(choice);
                    this->all_char_list.erase(this->all_char_list.begin() + choice);

                }
                else
                {
                    std::cout << "Please enter a number between " << 0 << " and " << this->all_char_list.size() - 1 << std::endl;
                }

            }
            catch (const std::invalid_argument& e) {
                std::cerr << "Error: Invalid input. Please enter a valid integer." << std::endl;
            }
        }
    }
    
}

//void ClueLess::AttachHalls2Room(Hallway h1, Hallway h2, Room r) {

//}

int ClueLess::MainMenu() {
    int choice = 0;  // the number they enter

    return choice;
}


