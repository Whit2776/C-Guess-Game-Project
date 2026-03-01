// A guessing game in which the user tries to guess a number
#include <iostream>
#include <random>
#include <limits>

class Game{
  private: // Can be accessed only in the class
    int min;
    int max;
    int secret;
    int max_attempts;
    int attempt_count;
    int rounds_played;
    int score;
    bool success;

    std::mt19937 gen;

  public: // Can be accessed outside the class
    Game()
      :min(1),
      max(10),
      max_attempts(3),
      attempt_count(0),
      rounds_played(0),
      score(0),
      success(false),
      gen(std::random_device{}())
    {};

    void select_range(){
      do {
        std::cout << "Select the min range \n";
        std::cin >> min;
      
        while(std::cin.fail()){
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "Select the min range \n";
          std::cin >> min;
        };
      
        std::cout << "Select the max range \n";
        std::cin >> max;
      
        while(std::cin.fail()){
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "Select the max range \n";
          std::cin >> max;
        };

        if (max < min){
          std::cout << "Max cannot be less than the min \n";
        }
    
      }while (max < min);
    }

    void generate_secret(){
      std::uniform_int_distribution<> dist(min, max);
      secret = dist(gen);
    }

    void play_round(){
      attempt_count = 0;
      success = false;
      rounds_played++;
      generate_secret();

      int guess;
    

      while(attempt_count < max_attempts && !success){
        std::cout << "\nEnter a number between " << min << " and " << max << ": \n ";
        std::cin >> guess;

        while (std::cin.fail()) {
          std::cout << "Retry, but type an integer this time 🥲 \n ";
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cin >> guess;
          continue;
        };

        attempt_count++;

        if(secret == guess){
          success = true;
          score+=(max_attempts - attempt_count + 1) * 10;
          std::cout << "Congrats, you had it 👏👏 \n";
        }
        else if (secret > guess){
          std::cout << "Guess higher 😁 \n";
          
        } else if (secret < guess){
          std::cout << "Guess lower 😁 \n";
          
        } else {
          std::cout << "None of the win/loss sequence conditions were met";//debug
        }
        std::cout << "You have " << max_attempts-attempt_count << " tries left \n";
      
        if (attempt_count == max_attempts && !success){
          std::cout << "You have tried "<< max_attempts << " times 🖐🏻 \n " << "The number was \n" << secret << "\n";
        } else if(attempt_count == max_attempts && success){
          std::cout << "You lucky mangle 🤣🤣, got it on your last try";
        }
      }
    }

    void start(){
      select_range();
      char choice;
      char changeRangeCOnfirmation;

      do{
        play_round();
        std::cout << "Play again? (y/n)";
        std::cin >> choice;
        std::cout << "Use the same range as before? \n (y/n) \n";
        std::cin >> changeRangeCOnfirmation;
        if (changeRangeCOnfirmation == 'n'){
          select_range();
        }

      } while(choice == 'y');

      std::cout << "\n Game Over \n";
      std::cout << "Rounds played: " << rounds_played << "\n";
      std::cout << "Final score: " << score << "\n";
    }

    void changeRangeAndPlay(){

    }
  };

int main(){
  Game game;
  game.start();
}