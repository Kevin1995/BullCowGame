#include <iostream>
#include <string>

using namespace std;

void PrintIntro() 
{
	// Introduce Game
	// Constant Expression
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?\n";
	cout << endl;
	return;
}

int main() 
{ 
	PrintIntro();

	// get guest from the player
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin,Guess);
	// repeat the guess back to them
	cout << "Your guess was: " << Guess << endl;

	// get guest from the player
	cout << "Enter your guess: ";
	getline(cin, Guess);
	// repeat the guess back to them
	cout << "Your guess was: " << Guess << endl;

	cout << endl;

	return 0;
}