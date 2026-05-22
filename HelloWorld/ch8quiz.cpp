#include <iostream>
#include <cassert> // for assert
#include <random>
#include <chrono>
#include "ch8quiz.h"

namespace Constants {
    constexpr double gravity { 9.8 };
}

// Gets tower height from user and returns it
double getTowerHeight() {
	std::cout << "Enter the height of the tower in meters: ";
	double towerHeight{};
	std::cin >> towerHeight;
	return towerHeight;
}

// Returns the current ball height after "seconds" seconds
double calculateBallHeight(double towerHeight, int seconds) {
	// Using formula: s = (u * t) + (a * t^2) / 2
	// here u (initial velocity) = 0, so (u * t) = 0
	const double fallDistance { Constants::gravity * (seconds * seconds) / 2.0 };
	const double ballHeight { towerHeight - fallDistance };

	// If the ball would be under the ground, place it on the ground
	if (ballHeight < 0.0)
		return 0.0;

	return ballHeight;
}

// Prints ball height above ground
void printBallHeight(double ballHeight, int seconds) {
	if (ballHeight > 0.0)
		std::cout << "At " << seconds << " seconds, the ball is at height: " << ballHeight << " meters\n";
	else
		std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
}

// Calculates the current ball height and then prints it
// This is a helper function to make it easier to do this
double calculateAndPrintBallHeight(double towerHeight, int seconds) {
	const double ballHeight{ calculateBallHeight(towerHeight, seconds) };
	printBallHeight(ballHeight, seconds);
    return ballHeight;
}

void ch8quiz1() {
	const double towerHeight{ getTowerHeight() };

    int seconds { 0 };

    while(calculateAndPrintBallHeight(towerHeight, seconds) > 0.0) {
        seconds++;
    }
}

bool isPrime(int x) {
    std::cout << "calculating isPrime(" << x << ")\n";
    if (x <= 1) return false;
    if (x <= 3) return true;
    if ((x % 2) == 0) return false;
    for(int i {3}; i*i <= x; i+=2) {
        if (x % i == 0) return false;
    }
    std::cout << x << " is prime\n";
    return true;
}

void ch8quiz2() {
    assert(!isPrime(0)); // terminate program if isPrime(0) is true
    assert(!isPrime(1));
    assert(isPrime(2));  // terminate program if isPrime(2) is false
    assert(isPrime(3));
    assert(!isPrime(4));
    assert(isPrime(5));
    assert(isPrime(7));
    assert(!isPrime(9));
    assert(isPrime(11));
    assert(isPrime(13));
    assert(!isPrime(15));
    assert(!isPrime(16));
    assert(isPrime(17));
    assert(isPrime(19));
    assert(isPrime(97));
    assert(!isPrime(99));
    assert(isPrime(13417));

    std::cout << "Success!\n";
}

bool playAgain() {
    while (true) {
        char choice{};
        std::cout << "Would you like to play again (y/n)? ";
        std::cin >> choice;
        switch (choice) {
            case 'y':
                return true;
            case 'n':
                return false;
        }
    }
}

bool playHiLo(int guesses, int min, int max, int solution) {
    std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is.\n";
    
    int guess {0};

    for (int i{1}; i <= 7; i++) {
        std::cout << "Guess #" << i << ": ";
        int guess {};
        std::cin >> guess;

        if (guess > solution) std::cout << "Too high\n";
        else if (guess < solution) std::cout << "Too low\n";
        else if (guess == solution) {
            std::cout << "Correct, you win!\n";
            return true;
        }
    }
    std::cout << "Sorry, you lose.  The correct number was " << solution << ".\n";
    return false;
}

void ch8quiz3() {
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
        playHiLo(guesses, min, max, die100(mt));
    } while (playAgain());

    std::cout << "Thank you for playing.\n";
}