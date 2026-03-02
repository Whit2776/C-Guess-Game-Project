C++ Number Guessing Game

This is a console-based Number Guessing Game built in C++ using Object-Oriented Programming principles and modern C++ random number generation.

The player selects a custom number range, and the program generates a random secret number within that range. The player has a limited number of attempts to guess the correct number while receiving feedback hints.

🚀 Features

🔢 Custom user-defined number range

🎲 Random number generation using <random> and std::mt19937

🧠 Hint system (Guess higher / Guess lower)

🛡 Robust input validation using cin.fail() and numeric_limits

🎯 Scoring system based on remaining attempts

🔁 Multiple rounds support

📊 End-of-game statistics (rounds played & final score)

🧱 Fully object-oriented design using a Game class

🛠 Technologies Used

C++

Object-Oriented Programming (OOP)

<random> for secure random number generation

<limits> for input stream handling

Standard Template Library (STL)

🧩 Concepts Demonstrated

Class design with private and public members

Constructor initializer lists

Encapsulation

Random number distributions

Input validation and stream handling

Game loop logic

Score calculation algorithms

🎮 How It Works

User selects a minimum and maximum range.

The system generates a secret number within that range.

The player has 3 attempts to guess correctly.

Score is calculated based on how early the correct guess is made.

The player can choose to play multiple rounds.

Final statistics are displayed when the game ends.

📚 Learning Objective

This project was built to strengthen understanding of:

OOP fundamentals

Clean console interaction

Defensive programming techniques

Random number generation best practices in C++
