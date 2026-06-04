#include <iostream>
#include <cassert> // for assert
#include <random>
#include <chrono>
#include <cstdlib>
#include <limits>
#include "ch9quiz.h"

void ignoreLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// true if extraction failed, false if extraction succeeded
bool clearFailedExtraction() {
    // check for failed extraction
    if (!std::cin) {
        if (std::cin.eof()) { std::exit(0); }

        std::cin.clear(); // clear failure mode, back into normal operation mode
        ignoreLine(); // remove bad input
        return true;
    }
    return false;
}

bool ch9playAgain() {
    while (true) {
        char choice{};
        std::cout << "Would you like to play again (y/n)? ";
        std::cin >> choice;

        if (!clearFailedExtraction()) { ignoreLine(); }
        switch (choice) {
            case 'y':
                return true;
            case 'n':
                return false;
        }
    }
}

int inputGuess(int guessNum, int min, int max) {
    while (true) {
        std::cout << "Guess #" << guessNum << ": ";
        int guessInput {};
        std::cin >> guessInput;

        if (clearFailedExtraction()) {
            std::cout << "invalid input, try again\n";
            continue;
        }

        if (guessInput < min || guessInput > max) {
            std::cout << "guess out of bounds, try again\n";
            continue;
        }

        ignoreLine();
        return guessInput;
    }
}

bool ch9HiLo(int guesses, int min, int max, int solution) {
    std::cout << "Let's play a game. I'm thinking of a number from "<< min << " to " << max << ". You have " << guesses << " tries to guess what it is.\n";
    
    int validGuess {0};

    for (int i{1}; i <= 7; i++) {
        int validGuess { inputGuess(i, min, max) };

        if (validGuess > solution) std::cout << "Too high\n";
        else if (validGuess < solution) std::cout << "Too low\n";
        else if (validGuess == solution) {
            std::cout << "Correct, you win!\n";
            return true;
        }
    }
    std::cout << "Sorry, you lose.  The correct number was " << solution << ".\n";
    return false;
}

void ch9quiz1() {
    std::random_device rd{};
    std::seed_seq ss { rd(), rd(), rd(), rd(), rd(), rd(), rd(), 
        static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count())
    };
    std::mt19937 mt{ss};

    std::uniform_int_distribution die100 {1,100};

    constexpr int guesses {7};
    constexpr int min {1};
    constexpr int max {100};

    do {
        ch9HiLo(guesses, min, max, die100(mt));
    } while (ch9playAgain());

    std::cout << "Thank you for playing.\n";
}

// given solution: 
#include "Random.h"

int getGuess(int count, int min, int max) {
    while (true) {
        std::cout << "Guess #" << count << ": ";

        int guess {};
        std::cin >> guess;

        bool success { std::cin };
        std::cin.clear(); // put us back in 'normal' operation mode (if needed)
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // remove any extra input

        // if we didn't extract anything, or if guess is out of bounds, try again
        if (!success || guess < min || guess > max)
            continue;

        return guess;
    }
}

bool playAgain2() {
    // keep asking user until they pick y or n
    while (true) {
        char ch{};
        std::cout << "Would you like to play again (y/n)? ";
        std::cin >> ch;

        // clear any extra input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (ch)
        {
        case 'y': return true;
        case 'n': return false;
        }
    }
}