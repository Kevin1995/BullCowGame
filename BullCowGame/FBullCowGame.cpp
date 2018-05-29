#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "donkey";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false) // if the guess isnt an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false) // if the guess isnt lowercase
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) // if the guess is wrong
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

// receives a valid guess increments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length(); // assuming same length as guess

	for (int32 MWHChar = 0; MWHChar < WordLength; MWHChar++) {
		// compare letters against the guess
		for (int32 GChar = 0; GChar < WordLength; GChar++)
		{	//if they match then
			if (Guess[GChar] == MyHiddenWord[MWHChar])
			{	// if their in the same place
				if (MWHChar == GChar) {
					BullCowCount.Bulls++; // increment bulls
				} 
				else {
					BullCowCount.Cows++; // must be a cow;
				}
			}
		}
	}

	return BullCowCount;
}
