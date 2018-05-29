#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// same as a class but all properties are set to public by default
struct FBullCowCount 
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame 
{
public:
	FBullCowGame(); // constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;

	bool CheckGuessValidity(FString) const; // TODO make a more rich return value.
	bool IsGameWon() const;

	void Reset(); // TODO make a more rich return value.
	FBullCowCount SubmitGuess(FString);

private:
	// see constructor for initialisation
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};