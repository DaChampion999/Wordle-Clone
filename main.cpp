#include <iostream>;
#include <fstream>;
#include <cstdlib>;
#include <time.h>;
using namespace std;
string wordle;
string pGuess;
int attempts = 0;
bool win;

void genRandWord(){
ifstream words ("possibleWords.txt");
//ifstream words ("troubleshoot.txt"); //for troubleshooting
if(!words){
  return;
}
int r = rand() % 2315;// Assuming 10,000 words in the file
//int r = rand() % 3; //for troubleshooting
do{
  words >> wordle;
}
while (--r >= 0);

return wordle;
}

void guess(){
  cin >> pGuess;
  cout << "\033[A";
  cout << "\b";
  for(int i = 0; i <=4; i++){
    int found = wordle.find(pGuess[i]);
    if(pGuess[i] == wordle[i]){
      cout <<  "\x1b[32m" << pGuess[i] << "\x1b[0m";
    }
    else if(wordle.find(pGuess[i]) != string::npos){
      cout <<  "\x1b[33m" << pGuess[i] << "\x1b[0m";
    }
    else{
      cout << "\x1b[31m" <<pGuess[i] << "\x1b[0m";
    }
  }
}
void winCheck(){
  if(pGuess == wordle){
    cout << "\nYou win!";
    win = true;
  }
}
int main(){
  cout << "Welcome to Wordle!\nType a word and press 'enter' to start!\n";
  srand((unsigned)time(NULL));
  genRandWord();
//  cout << wordle << "\n"; //troubleshooting
  while(attempts <= 5){
    guess();
    winCheck();
    cout << "\n";
    attempts++;
//    cout << "\n" << attempts;
  }
  if(!win){
  cout << "Thats 6 tries! You lose! The word was: " << wordle;
  }
}