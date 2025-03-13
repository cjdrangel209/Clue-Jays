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
    turn = 0;
    this->StartGame();
        

}

void ClueLess::StartGame() {

    this->player_num = GetPlayerNum();
    this->WhoIsWho();
    this->BuildBoard();
    
    
    //Deal d = Deal();
    //d->deal(player_list);
    // this->answers = d.getAnswers();

    this->turn = 0;
    // reset for accusations
    this->all_char_list = { "Miss Scarlet", "Col. Mustard", "Mrs. White", "Prof. Plum", "Mrs. Peacock", "Mr. Green" };
    this->all_weapons_list = {"Candlestick", "Dagger", "Lead pipe", "Revolver", "Rope", "Wrench" };

    this->MainMenu();
    
    

    std::cout << this->player_num << std::endl;
        
       
}

void ClueLess::BuildBoard() {
    //h0 = Halway();
    //h1 = Halway();
    //h2 = Halway();
    //h3 = Halway();
    //h4 = Halway();
    //h5 = Halway();
    //h6 = Halway();
    //h7 = Halway();
    //h8 = Halway();
    //h9 = Halway();
    //h10 = Halway();
    //h11 = Halway();
    //
    // // build out the board
    //r0 = Room("Study", nullptr, h0, nullptr, h2, nullptr);
    //r1 = Room("Hall", h0, h1, nullptr, h3, nullptr);
    //r2 = Room("Lounge", h1, nullptr, nullptr, h4, nullptr);
    //r3 = Room("Library", nullptr, h5, h2, h7, nullptr);
    //r4 = Room("Billiard Room", h5, h6, h3, h8, nullptr);
    //r5 = Room("Dining Room", h6, nullptr, h4, h9, nullptr);
    //r6 = Room("Conservatory", nullptr, h10, h7, nullptr, nullptr);
    //r7 = Room("Ballroom", h10, h11, h8, nullptr, nullptr);
    //r8 = Room("Kitchen", h11, nullptr, h9, nullptr, nullptr);
    //
    //// set up hallways and set secret entrance
    //// note that left is up if they are verticle
    //AttachHalls2Room(h0, r0, r1);
    //AttachHalls2Room(h1, r1, r2);
    //AttachHalls2Room(h2, r0, r3);
    //AttachHalls2Room(h3, r1, r4);
    //AttachHalls2Room(h4, r2, r5);
    //AttachHalls2Room(h5, r3, r4);
    //AttachHalls2Room(h6, r4, r5);
    //AttachHalls2Room(h7, r3, r6);
    //AttachHalls2Room(h8, r4, r7);
    //AttachHalls2Room(h9, r5, r8);
    //AttachHalls2Room(h10, r6, r7);
    //AttachHalls2Room(h11, r7, r8);
    //
    //r0.setSecretPassage(r8);
    //r2.setSecretPassage(r6);
    //r6.setSecretPassage(r2);
    //r8.setSecretPassage(r0);

    // // Go through all used characters and place them in their hallway
    /*for (int i = 0; i < this->player_list.size(); i++) {
        if(this->player_list.at(i).getName == "Miss Scarlet"){
            this->player_list.at(i).setPosition(h1)
        }
        else if (this->player_list.at(i).getName == "Col. Mustard") {
            this->player_list.at(i).setPosition(h4)
        }
        else if (this->player_list.at(i).getName == "Mrs. White") {
            this->player_list.at(i).setPosition(h11)
        }
        else if (this->player_list.at(i).getName == "Prof. Plum") {
            this->player_list.at(i).setPosition(h2)
        }
        else if (this->player_list.at(i).getName == "Mrs. Peacock") {
            this->player_list.at(i).setPosition(h7)
        }
        else if (this->player_list.at(i).getName == "Mr. Green") {
            this->player_list.at(i).setPosition(h10)
        }
    }*/


}

int ClueLess::GetPlayerNum() {
    std::cout << "Welcome to CLUE-LESS!" << std::endl;
    std::cout << "Please enter the number of players (2-6)? " << std::endl;
    std::string num_player_str = "";
    int num_player = 0;

    bool not_int = true;
    // input validation
    while (not_int)
    {
        try {
            std::cin >> num_player_str;
            num_player = std::stoi(num_player_str);
            // min of 2 and max of 6 players
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
        // input validation
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

//void ClueLess::AttachHalls2Room(Hallway h1, Room rl, Room rr) {
    // h1->setLeft(rl);
    // h1->setRight(rr);
    // check if I need to return the object or not
//}

void ClueLess::MainMenu() {
    win = false;

    while (!win) {
        //std::cout << "Player " << std::to_string(turn + 1) << " (" << this->player_list.at(turn).getName() << ") turn" << std::endl;
       
        //std::cout << "Please enter the number of players (2-6)? " << std::endl;
        std::string choice_str = "";
        int choice = 0;
        
        // in a hallway
        /*if (this->player_list.at(turn).getHallway())
        {
            bool not_int = true;
            // input validation
            while (not_int)
            {
                
                std::cout << "0: Move to the " << this->player_list.at(turn).getHallway().getLeft().getName() << std::endl;
                std::cout << "1: Move to the " << this->player_list.at(turn).getHallway().getRight().getName() << std::endl;
                std::cout << "2: View cards << std::endl;
                std::cout << "3: View location << std::endl;

                try {
                    std::cin >> choice_str;
                    choice = std::stoi(choice_str);
                    if (choice <= 3 && choice >= 0)
                    {
                        // if they view cards or location go again
                        if (choice == 2 || choice == 3){
                            this->HallChoice(choice);
                        }
                        else{
                            not_int = false;
                            this->HallChoice(choice);
                        }
                    }
                    else
                    {
                        std::cout << "Please enter a number between 0 and 3" << std::endl;
                    }

                }
                catch (const std::invalid_argument& e) {
                    std::cerr << "Error: Invalid input. Please enter a valid integer." << std::endl;
                }
            }*/

            //add in if statement for which one they picked?

        //}
        // in a room
        //else
        //{
        // // used to keep track of total amount of options given
        //    int option = 0;
        

        //    bool not_int = true;
        // // input validation
        //    while (not_int)
        //    {
        //    std::vector<Hallway> room_options;
        //    // check which hallways are available
        //    if (this->player_list.at(turn).getRoom().getLeft() && !this->player_list.at(turn).getRoom().getLeft().getOccupied()){
        //      std::cout << std::to_string(option) << ": Move left " << std::endl;
        //      option ++;
        //      room_options.push_back(this->player_list.at(turn).getRoom().getLeft());
        //    }
        //    if (this->player_list.at(turn).getRoom().getRight() && !this->player_list.at(turn).getRoom().getRight().getOccupied()){
        //      std::cout << std::to_string(option) << ": Move right " << std::endl;
        //      option ++;
        //      room_options.push_back(this->player_list.at(turn).getRoom().getRight());
        //    }
        //    if (this->player_list.at(turn).getRoom().getUp() && !this->player_list.at(turn).getRoom().getUp().getOccupied()){
        //      std::cout << std::to_string(option) << ": Move up " << std::endl;
        //      option ++;
        //      room_options.push_back(this->player_list.at(turn).getRoom().getUp());
        //    }
        //    if (this->player_list.at(turn).getRoom().getDown() && !this->player_list.at(turn).getRoom().getDown().getOccupied()){
        //      std::cout << std::to_string(option) << ": Move down " << std::endl;
        //      option ++;
        //      room_options.push_back(this->player_list.at(turn).getRoom().getDown());
        //    }
        //    if (this->player_list.at(turn).getRoom().getSecretPassage()){
        //      std::cout << std::to_string(option) << ": Move to the " << this->player_list.at(turn).getRoom().getSectretPassage().getName() << std::endl;
        //      option ++;
        //      room_options.push_back(this->player_list.at(turn).getRoom().getSectretPassage());
        //    }
        // 
        //    std::cout << option << ": View cards << std::endl;
        //    option ++;
        // 
        //    std::cout << option << ": View location << std::endl;
        //    option ++;
        // 
        //    std::cout << option << ": Make accusation " << std::endl;
        //    option ++;
        // 
        //        try {
        //            std::cin >> choice_str;
        //            choice = std::stoi(choice_str);
        //            if (choice <= option && choice >= 0)
        //            {
        //                // if they view cards or location get it again
                          /*if (choice == option - 1 || choice == option - 2) {
                            this->RoomChoice(int choice, int option); 
                          }
                          else {*/
        //                  not_int = false;
        //                  this->RoomChoice(int choice, int option);
        //                }
        //            }
        //            else
        //            {
        //                std::cout << "Please enter a number between 0 and " << std::to_string(option)s << std::endl;
        //            }

        //        }
        //        catch (const std::invalid_argument& e) {
        //            std::cerr << "Error: Invalid input. Please enter a valid integer." << std::endl;
        //        }
        //    }
        //}

        this->turn = (this->turn + 1) % this->player_num;

        

        
    }

    std::cout << "Player " << std::to_string(turn + 1) << " won!" << std::endl;

}

void ClueLess::HallChoice(int choice) {
    /*// move left/up
    if (choice == 0) {
        this->player_list.at(turn).setHallway(nullptr);
        this->player_list.at(turn).setRoom(this->player_list.at(turn).getHallway().getLeft());

    }
    // move right/down
    else if (choice == 1) {
        this->player_list.at(turn).setHallway(nullptr);
        this->player_list.at(turn).setRoom(this->player_list.at(turn).getHallway().getRight());

    }
    // get cards
    else if (choice == 2){
        for (int i = 0; i < this->player_list.at(turn).getCards().size(); i++)
        {
            std::cout << this->player_list.at(turn).getCards().at(i).getName() << std::endl;
        }
    }
    // get location
    else{
        if (this->player_list.at(turn).getHallway()){
            std::cout << "Between " << this->player_list.at(turn).getHallway().getLeft().getName << " and " << this->player_list.at(turn).getHallway().getRight().getName << std::endl;
        }
        else{
            std::cout << this->player_list.at(turn).getRoom().getName() << std::endl;
        }
    }
    */
}

void ClueLess::RoomChoice(int choice, int option) {
// void ClueLess::RoomChoice(int choice, int option, std::vector<Hallway> halls) {
    /*int rooms = halls.size();
    // get cards
    if (choice == rooms + 1){
        for (int i = 0; i < this->player_list.at(turn).getCards().size(); i++)
        {
            std::cout << this->player_list.at(turn).getCards().at(i).getName() << std::endl;
        }
    }
    get location
    else if (choice == rooms + 2){
        if (this->player_list.at(turn).getHallway()){
            std::cout << "Between " << this->player_list.at(turn).getHallway().getLeft().getName << " and " << this->player_list.at(turn).getHallway().getRight().getName << std::endl;
        }
        else{
            std::cout << this->player_list.at(turn).getRoom().getName() << std::endl;
        }
    }
    // accusation
    else if (choice == rooms + 3){
        Accusation();
    }
    // look through available rooms and move to the coresponding option's associated room
    else{
        int which_room = 0;
        while (which_room != choice){
            which_room ++;
        }
        this->player_list.at(turn).setHallway(halls.at(which_room));
        this->player_list.at(turn).setRoom(nullptr);

     
    }*/
}

void ClueLess::Accusation() {
    /*
    int num_prints = this->all_char_list.size();
    std::string choice_str = "";
    int choice = 0;

    std::cout << "Please enter a 2 digit number, the first for the character you want to accuse and the second for the weapon they used" << std::endl;
    for(int i = 0; i < num_prints; i++){
        std::cout << i + 1 << ": " << this->all_char_list.at(i) << "\t" << this->all_weapons_list.at(i) << std::endl;
    }

    bool not_int = true;
    // input validation
    while (not_int)
    {
        try {
            std::cin >> choice_str;
            choice = std::stoi(choice_str);
            if (choice <= 66 && choice >= 11)
            {
                not_int = false;
                int character = choice / num_prints;
                int weapon = choice % num_prints;
                this->CheckPick(character, weapon, this->player_list.at(turn).getRoom());
            }
            else
            {
                std::cout << "Please enter a number between 10 and 99" << std::endl;
            }

        }
        catch (const std::invalid_argument& e) {
            std::cerr << "Error: Invalid input. Please enter a valid integer." << std::endl;
        }
    }*/
}

//void ClueLess::CheckPick(int character, int weapon, Room room) {
// // move character into the room if they are in play
//  for(Character &i : this->player_list){
//      if (i.getName() == this->all_char_list.at(character)){
//          i.setRoom = this->player_list.at(turn).getRoom();
//          i.setHallway = nullptr;
//      }
//  }
//  // see if anyone can disprove you
//  for(const Character &i : this->player_list){
//      for(Cards &j : i.getCards){
//          if (j.getName == this->all_char_list.at(character)){
//              std::cout << "Incorrect " << this->all_char_list.at(character) << " was not the killer" << std::endl;
//              return;
//          }
//          else if (j.getName == this->all_weapons_list.at(character)){
//              std::cout << "Incorrect " << this->all_weapons_list.at(character) << " was not the weapon" << std::endl;
//              return;
//          }
//          else if (j.getName == this->player_list.at(turn).getRoom().getName()){
//              std::cout << "Incorrect " << this->player_list.at(turn).getRoom().getName() << " was not the room" << std::endl;
//              return;
//          }
//      }
//  }
//  if (this->all_char_list.at(character) == answers.at(0).getName()){
//      std::cout << "Correct " << answers.at(0).getName() << " was the killer" << std::endl;
//  }
// else{
//      std::cout << "Incorrect " << this->all_char_list.at(character) << " was not the killer" << std::endl;
//      return;
//  }
//  if (this->all_weapons_list.at(character) == answers.at(1).getName()){
//      std::cout << "Correct " << answers.at(1).getName() << " was the weapon" << std::endl;
//  }
// else{
//      std::cout << "Incorrect " << this->all_weapons_list.at(character) << " was not the weapon" << std::endl;
//      return;
//  }
//  if (this->this->player_list.at(turn).getRoom().getName() == answers.at(2).getName()){
//      std::cout << "Correct " << answers.at(2).getName() << " was the room" << std::endl;
//      this.win = true;
//  }
// else{
//      std::cout << "Incorrect " << this->player_list.at(turn).getRoom().getName() << " was not the room" << std::endl;
//      return;
//  }
//}


