// This program simulates a dice roll competition between two players.
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Generate a random number between 1 and 20
int rollD20() {
    return (rand() % 20) + 1;
}

// Determine if a roll is a critical success or failure
std::string getRollResult(int roll) {
    if (roll == 20) {
        return "\033[32mCritical Success!\033[0m";
    } else if (roll == 1) {
        return "\033[31mCritical Failure!\033[0m";
    } else {
        return "";
    }
}

int main() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(0)));

    std::string player1_name;
    std::string player2_name;

    // Get names from the users
    std::cout << "Enter the name for Player 1: ";
    std::getline(std::cin, player1_name);
    
    std::cout << "Enter the name for Player 2: ";
    std::getline(std::cin, player2_name);

    // Roll the die for each player
    int player1_roll = rollD20();
    int player2_roll = rollD20();

    // Get the special results
    std::string player1_result = getRollResult(player1_roll);
    std::string player2_result = getRollResult(player2_roll);

    // Display the results
    std::cout << "\n--- Roll Results ---\n";
    std::cout << player1_name << " rolled a " << player1_roll;
    if (!player1_result.empty()) {
        std::cout << " (" << player1_result << ")";
    }
    std::cout << "\n";
    
    std::cout << player2_name << " rolled a " << player2_roll;
    if (!player2_result.empty()) {
        std::cout << " (" << player2_result << ")";
    }
    std::cout << "\n\n";

    // Compare the rolls and declare a winner
    if (player1_roll > player2_roll) {
        std::cout << player1_name << " wins!\n";
    } else if (player2_roll > player1_roll) {
        std::cout << player2_name << " wins!\n";
    } else {
        std::cout << "The players were Evenly Matched!\n";
    }

    return 0;
}
