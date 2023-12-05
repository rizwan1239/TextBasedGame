#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

// Global Variables for Stats
int clues = 0;  
int playerStrength = 1;
int treasure = 0;

// Get random number in certain min, max range
int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function that handles logic when damage is dealt
void dealDamage(int damage)
{
    int newStrength = playerStrength - 2;
    if (newStrength < 0) playerStrength = 0;
    else playerStrength = newStrength;
}

// Called when player encounters a creature
void handleCreatureEncounter() {
    std::cout << "You encounter a mysterious creature!" << std::endl;
    int creatureStrength = getRandomNumber(1, 10);

    std::cout << "Creature's Strength: " << creatureStrength << std::endl;

    // Choice to fight creature or flee, fighting may lose strength if creature overpowers you
    std::cout << "Do you want to (1) Fight or (2) Flee? ";
    int choice;
    std::cin >> choice;

    if (choice == 1) {
        // Choice of Fighting
        std::cout << "Your Strength: " << playerStrength << std::endl;

        if (playerStrength > creatureStrength) {
            std::cout << "You defeat the creature! Well done!" << std::endl;
            playerStrength += 1;
            clues++;
        }
        else {
            std::cout << "Unfortunately, the creature overpowers you. You lose some health." << std::endl;
            dealDamage(2);
        }
    }
    else if (choice == 2) {
        // Choice to Flee
        std::cout << "You decide to flee. The creature disappears into the shadows." << std::endl;
    }
    else {
        std::cout << "Invalid choice. The creature attacks while you're indecisive!" << std::endl;
        dealDamage(2);
    }
}

// Function to handle exploring different locations
void exploreLocation() {
    int location = getRandomNumber(1, 10);

    switch (location) {
    case 1:
        std::cout << "You find a hidden cave. Enter? (yes/no): ";
        break;
    case 2:
        std::cout << "You come across a magical forest. Explore? (yes/no): ";
        break;
    case 3:
        std::cout << "You see a mysterious shrine. Approach? (yes/no): ";
        break;
    case 4:
        std::cout << "A dark castle looms in the distance. Investigate? (yes/no): ";
        break;
    case 5:
        std::cout << "You stumble upon an ancient ruin. Enter? (yes/no): ";
        break;
    case 6:
        std::cout << "A peaceful meadow stretches before you. Relax? (yes/no): ";
        break;
    case 7:
        std::cout << "A swirling vortex appears. Enter it? (yes/no): ";
        break;
    case 8:
        std::cout << "You find a hidden village. Explore? (yes/no): ";
        break;
    case 9:
        std::cout << "A spooky graveyard lies ahead. Enter cautiously? (yes/no): ";
        break;
    case 10:
        std::cout << "You reach the top of a mountain. Enjoy the view? (yes/no): ";
        break;
    }

    std::string choice;
    std::cin >> choice;
    int newStrength = playerStrength;

    if (choice == "yes") {
        // Switch through locations based on choice
        switch (location) {
        case 1:
            std::cout << "Inside the cave, you discover a hidden treasure!" << std::endl;
            treasure++;
            break;
        case 2:
            std::cout << "The magical forest enchants you. You gain magical powers!" << std::endl;
            playerStrength++;
            break;
        case 3:
            std::cout << "Approaching the shrine, you feel a mysterious energy. Something has changed." << std::endl;
            playerStrength++;
            break;
        case 4:
            std::cout << "Investigating the dark castle, you find clues about the legendary artifact." << std::endl;
            clues++;
            break;
        case 5:
            std::cout << "Inside the ancient ruin, you solve a puzzle and gain knowledge about the artifact." << std::endl;
            clues++;
            break;
        case 6:
            std::cout << "In the peaceful meadow, you encounter a friendly creature. It joins you on your journey." << std::endl;
            playerStrength++;
            break;
        case 7:
            std::cout << "Entering the vortex, you find yourself in a parallel dimension. Discover hidden truths." << std::endl;
            clues++;
            break;
        case 8:
            std::cout << "The hidden village welcomes you. Trade with the villagers for valuable items." << std::endl;
            treasure++;
            break;
        case 9:
            std::cout << "Exploring the spooky graveyard, you uncover a cursed artifact. Beware its damage." << std::endl;
            dealDamage(2);
            break;
        case 10:
            std::cout << "At the mountain top, you meditate and gain wisdom. Your mind is now sharper." << std::endl;
            clues++;
            break;
        }
    }
    else {
        std::cout << "You decide not to explore. Onward to new adventures!" << std::endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    std::cout << "Welcome to the Magical Adventure Game!" << std::endl;

    while (true) {
        // Present options to the player
        std::cout << "\nChoose an action:\n";
        std::cout << "1. Explore\n";
        std::cout << "2. Rest\n";
        std::cout << "3. Quit\n";
        std::cout << "Stats:";
        std::cout << "\nClues: " << clues;
        std::cout << "\nStrength: " << playerStrength;
        std::cout << "\nTreasure: " << treasure;

        std::cout << "\n\nEnter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            exploreLocation();
            break;
        case 2:
            std::cout << "You take a rest and regain some health." << std::endl;
            playerStrength++;
            break;
        case 3:
            std::cout << "Thanks for playing! Goodbye." << std::endl;
            return 0;
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
            break;
        }

        // Randomly trigger a creature encounter
        if (getRandomNumber(1, 100) <= 20) {
            handleCreatureEncounter();
        }

        // End the game if player has found artifact
        if (clues >= 10) {
            std::cout << "Congratulations! You have found the legendary artifact!" << std::endl;
            return 0;
        }
    }

    return 0;
}
