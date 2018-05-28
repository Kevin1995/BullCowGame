#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuessAndPrintBack();

// entry point for application
int main() 
{ 
	PrintIntro();

	// loop for the number of guesses
	constexpr int NUMBER_OF_TURN = 5;
	for (int count = 1; count <= NUMBER_OF_TURN; count++)
	{
		GetGuessAndPrintBack();
		cout << endl;
	}

	return 0;
}

// Introduce Game
void PrintIntro()
{
	// Constant Expression
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?\n";
	cout << endl;
	return;
}

// get guest from the player
string GetGuessAndPrintBack() 
{
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);

	//print the guess back to them
	cout << "Your guess was: " << Guess << endl;
	return Guess;
}