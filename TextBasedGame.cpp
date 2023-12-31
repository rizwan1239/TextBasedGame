#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

// Global Variables for Stats
int clues = 0;  
int playerStrength = 1;
int treasure = 0;

// Enum for colors
enum Color {
    RED,
    YELLOW,
    CYAN,
    BLUE,
    GREEN,
    PURPLE,
    DEFAULT
};

// Function to set the text color based on the enum value
void SetColor(Color color) {
    switch (color) {
    case RED:
        std::cout << "\x1B[31m";  
        break;
    case YELLOW:
        std::cout << "\x1B[33m";  
        break;
    case CYAN:
        std::cout << "\x1B[36m";  
        break;
    case BLUE:
        std::cout << "\x1B[34m";  
        break;
    case GREEN:
        std::cout << "\x1B[32m";  
        break;
    case PURPLE:
        std::cout << "\x1B[35m";
        break;
    case DEFAULT:
        std::cout << "\x1B[0m";   
        break;
    default:
        std::cout << "\x1B[0m";
        break;
    }
}

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
            SetColor(GREEN);
            std::cout << "You defeat the creature! Well done!" << std::endl;
            playerStrength += 1;
            clues++;
        }
        else {
            SetColor(RED);
            std::cout << "Unfortunately, the creature overpowers you. You lose some health." << std::endl;
            SetColor(DEFAULT);
            dealDamage(2);
        }
    }
    else if (choice == 2) {
        // Choice to Flee
        std::cout << "You decide to flee. The creature disappears into the shadows." << std::endl;
    }
    else {
        SetColor(RED);
        std::cout << "Invalid choice. The creature attacks while you're indecisive!" << std::endl;
        SetColor(DEFAULT);
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
            SetColor(YELLOW);
            std::cout << "Inside the cave, you discover a hidden treasure!" << std::endl;
            SetColor(DEFAULT);
            treasure++;
            break;
        case 2:
            SetColor(PURPLE);
            std::cout << "The magical forest enchants you. You gain magical powers!" << std::endl;
            SetColor(DEFAULT);
            playerStrength++;
            break;
        case 3:
            SetColor(GREEN);
            std::cout << "Approaching the shrine, you feel a mysterious energy. Something has changed." << std::endl;
            SetColor(DEFAULT);
            playerStrength++;
            break;
        case 4:
            SetColor(CYAN);
            std::cout << "Investigating the dark castle, you find clues about the legendary artifact." << std::endl;
            SetColor(DEFAULT);
            clues++;
            break;
        case 5:
            SetColor(CYAN);
            std::cout << "Inside the ancient ruin, you solve a puzzle and gain knowledge about the artifact." << std::endl;
            SetColor(DEFAULT);
            clues++;
            break;
        case 6:
            SetColor(GREEN);
            std::cout << "In the peaceful meadow, you encounter a friendly creature. It joins you on your journey." << std::endl;
            SetColor(DEFAULT);
            playerStrength++;
            break;
        case 7:
            SetColor(CYAN);
            std::cout << "Entering the vortex, you find yourself in a parallel dimension. Discover hidden truths." << std::endl;
            SetColor(DEFAULT);
            clues++;
            break;
        case 8:
            SetColor(YELLOW);
            std::cout << "The hidden village welcomes you. Trade with the villagers for valuable items." << std::endl;
            SetColor(DEFAULT);
            treasure++;
            break;
        case 9:
            SetColor(RED);
            std::cout << "Exploring the spooky graveyard, you uncover a cursed artifact. Beware its damage." << std::endl;
            SetColor(DEFAULT);
            dealDamage(2);
            break;
        case 10:
            SetColor(CYAN);
            std::cout << "At the mountain top, you meditate and gain wisdom. Your mind is now sharper." << std::endl;
            SetColor(DEFAULT);
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

    SetColor(CYAN);
    std::cout << "  __  __    __    ___  ____  ___    __    __        __    ____  _  _  ____  _  _  ____  __  __  ____  ____\n";
    std::cout << " (  \\/  )  /__\\  / __)(_  _)/ __)  /__\\  (  )      /__\\  (  _ \\( \\/ )( ___)( \\( )(_  _)(  )(  )(  _ \\( ___)\n";
    std::cout << "  )    (  /(__)\\( (_-. _)(_( (__  /(__)\\  )(__    /(__)\\  )(_) )\\  /  )__)  )  (   )(   )(__)(  )   / )__)\n";
    std::cout << " (_/\\/\\_)(__)(__)\\___/(____)\\___)(__)(__)(____)  (__)(__)(____/  \\/  (____)(_)\\_) (__) (______)(_)\\_)(____)\n";
    SetColor(DEFAULT);

    std::cout << "Welcome to the Magical Adventure Game!" << std::endl;

    while (true) {
        // Present options to the player
        SetColor(CYAN);
        std::cout << "\nChoose an action:\n";
        SetColor(DEFAULT);

        std::cout << "1. Explore\n";
        std::cout << "2. Rest\n";
        std::cout << "3. Quit\n";

        SetColor(CYAN);
        std::cout << "Stats:";
        SetColor(DEFAULT);

        std::cout << "\nClues: " << clues;
        std::cout << "\nStrength: " << playerStrength;
        std::cout << "\nTreasure: " << treasure;

        SetColor(YELLOW);
        std::cout << "\n\nEnter your choice: ";
        SetColor(DEFAULT);

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            exploreLocation();
            break;
        case 2:
            SetColor(GREEN);
            std::cout << "You take a rest and regain some health." << std::endl;
            SetColor(DEFAULT);
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
            SetColor(YELLOW);
            std::cout << "Congratulations! You have found the legendary artifact!" << std::endl;
            SetColor(DEFAULT);
            return 0;
        }
    }

    return 0;
}
