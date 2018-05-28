#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();

// entry point for application
int main() 
{ 
	PrintIntro();
	PlayGame();

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

void PlayGame()
{
	// loop for the number of guesses
	constexpr int NUMBER_OF_TURN = 5;
	for (int count = 1; count <= NUMBER_OF_TURN; count++)
	{
		string Guess = GetGuess();
		cout << "Your guess was: " << Guess << endl;
		cout << endl;
	}
}

// get guest from the player
string GetGuess() 
{
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);
	return Guess;
}