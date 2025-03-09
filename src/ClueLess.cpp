/*****************************************
** File:    ClueLess.cpp
** Author:  Jon Deyton
** Date:    3/1/21
**
** This contains the ClueLess functions
*/

# include "ClueLess.h"
namespace ClueLess
ClueLess() {
    char name[MAX_NAME] = ""; // the name of the ship
    // shows the title
    GameTitle();

    // calls the function to load the materials
    LoadMaterials();
    cout << PROJ2_SIZE - ONE << " materials loaded" << endl;

    cout << "What is the name of your ship? (space for default name)" << endl;
    // gets the name of the ship
    cin.getline(name, MAX_NAME);

    if (name[0] == EMPTY) {
        // makes a new ship object
        m_myShip = Ship();
    }
    else {
        // makes a new ship object
        m_myShip = Ship(name);
    }
    // loops through the array
    for (int i = 0; i < PROJ2_SIZE; i++) {
        // adds each material to the ship's array
        m_myShip.AddMaterial(m_materials[i]);
    }

}

void StartGame() {

    int choice = 0; // their current choice
    bool quit = false; // if they choose to quit
    // while they have not made enough uniques
    while (m_myShip.GetRank() != S && quit == false) {
        choice = MainMenu();
        // if they choose 1
        if (choice == ONE) {
            DisplayMaterials();
        }
        // if they choose 2
        else if (choice == TWO) {
            SearchMaterials();
        }
        // if they choose 3
        else if (choice == THREE) {
            CombineMaterials();
        }
        // if they choose 4
        else if (choice == FOUR) {
            CalcScore();
        }
        // if they choose 5
        else {
            quit = true;
        }
        // changes rank if applicable
        m_myShip.IncRank();

    }
    // if they decided to quit
    if (quit == true) {
        cout << "You quit, have a nice day.";
    }
    // otherwise they won
    else {
        cout << "Congratulations, you won!";
    }
}

int MainMenu() {
    int choice = 0;  // the number they enter
    cout << "What would you like to do?" << endl;
    // displays menu
    cout << "1. Display your Ship's Materials\n"
        "2. Search for Raw Materials\n"
        "3. Attempt to Merge Materials\n"
        "4. See Score\n"
        "5. Quit" << endl;
    cin >> choice;

    // if they enter a number outside of bounds
    while (choice < ONE || choice > FIVE) {

        cout << "Invalid choice try again" << endl;

        // displays menu
        cout << "What would you like to do?" << endl;
        cout << "1. Display your Ship's Materials\n"
            "2. Search for Raw Materials\n"
            "3. Attempt to Merge Materials\n"
            "4. See Score\n"
            "5. Quit" << endl;
        cin >> choice;
    }
    return choice;
}

