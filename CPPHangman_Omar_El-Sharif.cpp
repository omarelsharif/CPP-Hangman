
// Omar El-Sharif 
// 4/14/2023


#include <iostream>
#include <string>
#include <ctime>
#include <vector>
using namespace std;

// pass by reference used here for the `secret` variable
// it's a pointer to a string, so I'm passing a reference to the pointer
void playHangman(const string& answer, string* secret);

int main() {
  cout << "Welcome to hangman... Guess a country name" << endl;
  cout << "" << endl; 
  cout << "Each letter is represented by a star" << endl;
  cout << "" << endl; 
  cout << "You have to type only one letter in one try" << endl;
  cout << "" << endl; 
  cout << "You have 5 strikes to try and guess the word" << endl;
  cout << "" << endl; 
  cout << "**********************************************" << endl;
  cout << "" << endl; 

  // initialize list of words
  string words[] = {
    "japan",
    "turkey",
    "nepal",
    "malaysia",
    "philippines",
    "australia",
    "america",
    "ethiopia",
    "oman",
    "indonesia"
  };

  srand(time(NULL));
  int n = rand() % 10;
  string answer = words[n];

  // pass by reference used here for the `secret` variable
  // passing a pointer to the string, which is then modified in the `playHangman` function
  string secret(answer.length(), '*');
  playHangman(answer, &secret);

  return 0;
}

// used pass by reference used here for  the `answer` and `secret` variables
// `answer` is passed by const reference to avoid accidentally modifying it
// `secret` is passed by pointer to allow modification of the string
void playHangman(const string& answer, string* secret) {

  for (int i = 0; i < secret->length(); i++) {
    cout << "*";
  }
  cout << endl;
  cout << endl; 

  int strikes = 0;
  vector<char> guessedLetters;
  bool messagePrinted = false;

  while (strikes < 5 && *secret != answer) {
    cout << "Guess a letter: ";
    char letter;
    cin >> letter;

    // checking if letter has already been guessed
    bool alreadyGuessed = false;
    for (int i = 0; i < guessedLetters.size(); i++) {
      if (guessedLetters[i] == letter) {
        alreadyGuessed = true;
        strikes++;
        cout << "Whoops! You already guessed that letter. You have " << 5 - strikes << " guesses left.\n";
        cout << "" << endl; 
        break;
      }
    }

    if (alreadyGuessed) {
      continue;
    } else {
      guessedLetters.push_back(letter);
    }

    // checking if letter is in answer
   
    bool found = false;
for (int i = 0; i < answer.length(); i++) {
  if (answer[i] == letter) {
    (*secret)[i] = letter; // dereferencing the pointer to access the string, then modify the character at index `i`
    found = true;
  }
}
if (found) {
  cout<< "You found a letter! Isn't that exciting!   ";
}


    if (!found) {
      strikes++;
      cout << "Whoops! That letter isn't there! You have " << 5 - strikes << " guesses left.\n";
    }

    cout << *secret << "\n"; // dereferencing the pointer to print the modified string

  }

  if (*secret == answer) {
    cout << "Yeah! You got it!.\n";
  } else {
    cout << "Sorry, you lost. The word was " << answer << ".\n";
  }
}
