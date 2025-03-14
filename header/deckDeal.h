#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

// Class representing a card in the Clue board game
class Cards {
public:
    enum class CardType { CHARACTER, WEAPON, ROOM };

private:
    std::string name;
    CardType type;

public:
    // Default constructor (needed for uninitialized cards)
    Cards() : name("Unknown"), type(CardType::CHARACTER) {}

    // Constructor to initialize a card with a name and type
    Cards(const std::string& cardName, CardType cardType) : name(cardName), type(cardType) {}

    // Get the name of the card
    std::string getName() const {
        return name;
    }

    // Get the type of the card
    CardType getType() const {
        return type;
    }
};

// Class representing a deck of cards for the Clue board game
class ClueDeck {
private:
    std::vector<Cards> cards;
    Cards murderCharacter;
    Cards murderWeapon;
    Cards murderRoom;

public:
    // Constructor to initialize the deck (including murder cards)
    ClueDeck() {
        resetDeck();
    }

    // Reset the deck to its original state and choose the murder cards
    void resetDeck() {
        cards.clear();

        // Prepare character cards
        std::vector<Cards> characters = {
            {"Miss Scarlet", Cards::CardType::CHARACTER},
            {"Professor Plum", Cards::CardType::CHARACTER},
            {"Mrs. Peacock", Cards::CardType::CHARACTER},
            {"Mr. Green", Cards::CardType::CHARACTER},
            {"Mrs. White", Cards::CardType::CHARACTER},
            {"Colonel Mustard", Cards::CardType::CHARACTER}
        };

        // Prepare weapon cards
        std::vector<Cards> weapons = {
            {"Candlestick", Cards::CardType::WEAPON},
            {"Dagger", Cards::CardType::WEAPON},
            {"Lead Pipe", Cards::CardType::WEAPON},
            {"Revolver", Cards::CardType::WEAPON},
            {"Rope", Cards::CardType::WEAPON},
            {"Wrench", Cards::CardType::WEAPON}
        };

        // Prepare room cards
        std::vector<Cards> rooms = {
            {"Kitchen", Cards::CardType::ROOM},
            {"Ballroom", Cards::CardType::ROOM},
            {"Conservatory", Cards::CardType::ROOM},
            {"Dining Room", Cards::CardType::ROOM},
            {"Lounge", Cards::CardType::ROOM},
            {"Hall", Cards::CardType::ROOM},
            {"Study", Cards::CardType::ROOM},
            {"Library", Cards::CardType::ROOM},
            {"Billiard Room", Cards::CardType::ROOM}
        };

        // Use random generators for selecting murder cards
        static std::random_device rd;
        static std::mt19937 rng(rd());

        std::shuffle(characters.begin(), characters.end(), rng);
        std::shuffle(weapons.begin(), weapons.end(), rng);
        std::shuffle(rooms.begin(), rooms.end(), rng);

        // Select one card from each category for the murder scenario
        murderCharacter = characters.back();
        characters.pop_back();

        murderWeapon = weapons.back();
        weapons.pop_back();

        murderRoom = rooms.back();
        rooms.pop_back();

        // Combine the remaining cards into the deck
        cards.insert(cards.end(), characters.begin(), characters.end());
        cards.insert(cards.end(), weapons.begin(), weapons.end());
        cards.insert(cards.end(), rooms.begin(), rooms.end());
    }

    // Shuffle the deck of remaining cards
    void shuffleDeck() {
        static std::random_device rd;
        static std::mt19937 rng(rd());
        std::shuffle(cards.begin(), cards.end(), rng);
    }

    // Draw a card from the deck
    Cards drawCard() {
        if (cards.empty()) {
            throw std::out_of_range("No cards left in the deck.");
        }
        Cards drawnCard = cards.back();
        cards.pop_back();
        return drawnCard;
    }

    // Get the number of cards left in the deck
    size_t cardsLeft() const {
        return cards.size();
    }

    // Function to return the murder cards as a vector
    std::vector<Card> getMurderCards() const {
        return {Card(murderCharacter.getName(), static_cast<int>(murderCharacter.getType())), Card(murderWeapon.getName(), static_cast<int>(murderWeapon.getType())), Card(murderRoom.getName(), static_cast<int>(murderRoom.getType()))};
    }

    void DealCards(std::vector<Player>& players) {
        size_t playerIndex = 0;
        while (cardsLeft() > 0) {
            try {
                Cards card = drawCard();
                Card c = Card(card.getName(), static_cast<int>(card.getType()));
                players[playerIndex].addCard(c);
                playerIndex = (playerIndex + 1) % players.size();
            }
            catch (const std::out_of_range& e) {
                std::cout << e.what() << "\n";
                break;
            }
        }
    }

    // Reveal the murder cards (the secret solution)
    void revealMurderCards() const {
        std::cout << "Murder Scenario:\n";
        std::cout << "  Suspect: " << murderCharacter.getName() << "\n";
        std::cout << "  Weapon: " << murderWeapon.getName() << "\n";
        std::cout << "  Room: " << murderRoom.getName() << "\n";
    }
};

// Class representing a player in the game
class Players {
private:
    std::string name;
    std::vector<Card> hand;

public:
    // Default constructor
    Players() : name("Unnamed Player") {}

    // Constructor that takes in a player name
    Players(const std::string& playerName) : name(playerName) {}

    // Function to add a card to the player's hand
    void addCard(const Card& card) {
        hand.push_back(card);
    }

    // Function to set the player's hand from a vector of cards
    void setHand(const std::vector<Card>& cards) {
        hand = cards;
    }

    // Print the player's cards
    void printHand() const {
        std::cout << name << "'s cards: ";
        for (const auto& card : hand) {
            std::cout << card.getName() << "  ";
        }
        std::cout << "\n";
    }
};

/*int main() {
    // We'll run the simulation 3 times to show different deals.
    for (int run = 1; run <= 3; ++run) {
        std::cout << "=== Run " << run << " ===\n";

        // Initialize the deck and reveal the murder cards
        ClueDeck deck;
        deck.revealMurderCards();
        deck.shuffleDeck();

        // Create 6 players
        std::vector<Players> players;
        for (int i = 1; i <= 6; ++i) {
            players.emplace_back("Player " + std::to_string(i));
        }

        // Deal the remaining cards round-robin until the deck is empty
        size_t playerIndex = 0;
        while (deck.cardsLeft() > 0) {
            try {
                Card card = deck.drawCard();
                players[playerIndex].addCard(card);
                playerIndex = (playerIndex + 1) % players.size();
            }
            catch (const std::out_of_range& e) {
                std::cout << e.what() << "\n";
                break;
            }
        }

        // Print each player's hand
        for (const auto& player : players) {
            player.printHand();
        }

        std::cout << "Cards left in the deck: " << deck.cardsLeft() << "\n\n";
    }

    return 0;
}*/






//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <random>
//#include "cardClass.h"
//
//// Class representing a card in the Clue board game
////class Card {
////public:
////    enum class CardType { CHARACTER, WEAPON, ROOM };
////
////private:
////    std::string name;
////    CardType type;
////
////public:
////    // Default constructor (needed for uninitialized cards)
////    Card() : name("Unknown"), type(CardType::CHARACTER) {}
////
////    // Constructor to initialize a card with a name and type
////    Card(const std::string& cardName, CardType cardType) : name(cardName), type(cardType) {}
////
////    // Get the name of the card
////    std::string getName() const {
////        return name;
////    }
////
////    // Get the type of the card
////    CardType getType() const {
////        return type;
////    }
////};
//
//// Class representing a deck of cards for the Clue board game
//class ClueDeck {
//private:
//    std::vector<Card*> cards;
//    Card* murderCharacter;
//    Card* murderWeapon;
//    Card* murderRoom;
//
//public:
//    // Constructor to initialize the deck (including murder cards)
//    ClueDeck() {
//        resetDeck();
//    }
//
//    enum CardType { CHARACTER, WEAPON, ROOM };
//
//    // Reset the deck to its original state and choose the murder cards
//    void resetDeck() {
//        cards.clear();
//
//        // Prepare character cards
//        std::vector<Card*> characters = { &Card("Miss Scarlet", 0),
//            &Card("Professor Plum", 0),
//            &Card("Mrs. Peacock", 0),
//            &Card("Mr. Green", 0),
//            &Card("Mrs. White", 0),
//            &Card("Colonel Mustard", 0) };
//        
//
//        // Prepare weapon cards
//        std::vector<Card*> weapons = { &Card("Candlestick", 1),
//            &Card("Dagger", 1),
//            &Card("Lead Pipe", 1),
//            &Card("Revolver", 1),
//            &Card("Rope", 1),
//            &Card("Wrench", 1) };
//            
//
//        // Prepare room cards
//        std::vector<Card*> rooms = { &Card("Kitchen", 2),
//            &Card("Ballroom", 2),
//            &Card("Conservatory", 2),
//            &Card("Dining Room", 2),
//            &Card("Lounge", 2),
//            &Card("Hall", 2),
//            &Card("Study", 2),
//            &Card("Library", 2),
//            &Card("Billiard Room", 2) };
//
//        // Use random generators for selecting murder cards
//        static std::random_device rd;
//        static std::mt19937 rng(rd());
//
//        std::shuffle(characters.begin(), characters.end(), rng);
//        std::shuffle(weapons.begin(), weapons.end(), rng);
//        std::shuffle(rooms.begin(), rooms.end(), rng);
//
//        // Select one card from each category for the murder scenario
//        murderCharacter = characters.back();
//        characters.pop_back();
//
//        murderWeapon = weapons.back();
//        weapons.pop_back();
//
//        murderRoom = rooms.back();
//        rooms.pop_back();
//
//        // Combine the remaining cards into the deck
//        cards.insert(cards.end(), characters.begin(), characters.end());
//        cards.insert(cards.end(), weapons.begin(), weapons.end());
//        cards.insert(cards.end(), rooms.begin(), rooms.end());
//    }
//
//    // Shuffle the deck of remaining cards
//    void shuffleDeck() {
//        static std::random_device rd;
//        static std::mt19937 rng(rd());
//        std::shuffle(cards.begin(), cards.end(), rng);
//    }
//
//    // Draw a card from the deck
//    Card* drawCard() {
//        if (cards.empty()) {
//            throw std::out_of_range("No cards left in the deck.");
//        }
//        Card* drawnCard = cards.back();
//        cards.pop_back();
//        return drawnCard;
//    }
//
//    // Get the number of cards left in the deck
//    size_t cardsLeft() const {
//        for (int i = 0; i < cards.size(); i++)
//        {
//            std::cout << cards.at(i)->getName() << std::endl;
//        }
//        return cards.size();
//    }
//    
//    // Function to return the murder cards as a vector
//    std::vector<Card*> getMurderCards() const {
//      return {murderCharacter, murderWeapon, murderRoom};
//    }
//
//    // Reveal the murder cards (the secret solution)
//    void revealMurderCards() const {
//        std::cout << "Murder Scenario:\n";
//        std::cout << "  Suspect: " << murderCharacter->getName() << "\n";
//        std::cout << "  Weapon: " << murderWeapon->getName() << "\n";
//        std::cout << "  Room: " << murderRoom->getName() << "\n";
//    }
//
//    void DealCards(std::vector<Player> player) {
//        int playerIndex = 0;
//        while (cardsLeft() > 0) {
//            try {
//                Card* card = drawCard();
//                player.at(playerIndex).addCard(*card);
//                playerIndex = (playerIndex + 1) % player.size();
//            }
//            catch (const std::out_of_range& e) {
//                std::cout << e.what() << "\n";
//                break;
//            }
//        }
//    }
//};
//
//// Class representing a player in the game
////class Player {
////private:
////    std::string name;
////    std::vector<Card> hand;
////
////public:
////    // Default constructor
////    Player() : name("Unnamed Player") {}
////
////    // Constructor that takes in a player name
////    Player(const std::string& playerName) : name(playerName) {}
////
////    // Function to add a card to the player's hand
////    void addCard(const Card& card) {
////        hand.push_back(card);
////    }
////
////    // Function to set the player's hand from a vector of cards
////    void setHand(const std::vector<Card>& cards) {
////        hand = cards;
////    }
////
////    // Print the player's cards
////    void printHand() const {
////        std::cout << name << "'s cards: ";
////        for (const auto& card : hand) {
////            std::cout << card.getName() << "  ";
////        }
////        std::cout << "\n";
////    }
////};
//
////int main() {
////    // We'll run the simulation 3 times to show different deals.
////    for (int run = 1; run <= 3; ++run) {
////        std::cout << "=== Run " << run << " ===\n";
////
////        // Initialize the deck and reveal the murder cards
////        ClueDeck deck;
////        deck.revealMurderCards();
////        deck.shuffleDeck();
////
////        // Create 6 players
////        std::vector<Player> players;
////        for (int i = 1; i <= 6; ++i) {
////            players.emplace_back("Player " + std::to_string(i));
////        }
////
////        // Deal the remaining cards round-robin until the deck is empty
////        size_t playerIndex = 0;
////        while (deck.cardsLeft() > 0) {
////            try {
////                Card* card = deck.drawCard();
////                players[playerIndex].addCard(card);
////                playerIndex = (playerIndex + 1) % players.size();
////            } catch (const std::out_of_range& e) {
////                std::cout << e.what() << "\n";
////                break;
////            }
////        }
////
////        // Print each player's hand
////        for (const auto& player : players) {
////            player.printHand();
////        }
////
////        std::cout << "Cards left in the deck: " << deck.cardsLeft() << "\n\n";
////    }
////
////    return 0;
////}
