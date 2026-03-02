// A guessing game in which the user tries to guess a number
#include <iostream>
#include <random>
#include <limits>
using namespace std;
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

    mt19937 gen;

  public: // Can be accessed outside the class
    Game()
      :min(1),
      max(10),
      max_attempts(3),
      attempt_count(0),
      rounds_played(0),
      score(0),
      success(false),
      gen(random_device{}())
    {};

    void select_range(){
      do {
        cout << "*************************Guessing Game*************************" << endl;
        cout << "Try your luck today" << endl;
        cout << "Guess a random number between a range of your choice" << endl;
        cout << "Select the min number \n";
        cin >> min;

        while(cin.fail()){
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Please select a number" << endl;
          cout << "Select the min number \n";
          cin >> min;
        };

        cout << "Select the max number \n";
        cin >> max;

        while(cin.fail()){
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Select the max number \n";
          cin >> max;
        };

        if (max < min){
          cout << "Max cannot be less than the min \n";
        }

      }while (max < min);
    }

    void generate_secret(){
      uniform_int_distribution<> dist(min, max);
      secret = dist(gen);
    }

    void play_round(){
      attempt_count = 0;
      success = false;
      rounds_played++;
      generate_secret();

      int guess;


      while(attempt_count < max_attempts && !success){
        cout << "\nEnter a number from " << min << " to " << max << ": \n ";
        cin >> guess;

        while (cin.fail()) {
          cout << "Retry, but type an integer this time 🥲 \n ";
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cin >> guess;
          continue;
        };

        attempt_count++;

        if(secret == guess){
          success = true;
          score+=(max_attempts - attempt_count + 1) * 10;
          cout << "Congrats, you had it 👏👏 \n";
        }
        else if (secret > guess){
          cout << "Guess higher 😁 \n";

        } else if (secret < guess){
          cout << "Guess lower 😁 \n";

        } else {
          cout << "None of the win/loss sequence conditions were met";//debug
        }
        cout << "You have " << max_attempts-attempt_count << " tries left \n";

        if (attempt_count == max_attempts && !success){
          cout << "You have tried "<< max_attempts << " times 🖐🏻 \n " << "The number was \n" << secret << "\n";
        } else if(attempt_count == max_attempts && success){
          cout << "You lucky mangle 🤣🤣, got it on your last try";
        }
      }
    }

    void start(){
      select_range();
      char choice;

      do{
        play_round();
        cout << "Play again? (y/n)";
        cin >> choice;

      } while(choice == 'y');

      cout << "\n Game Over \n";
      cout << "Rounds played: " << rounds_played << "\n";
      cout << "Final score: " << score << "\n";
    }
  };

int main(){
  Game game;
  game.start();
}
