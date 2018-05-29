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

EWordStatus FBullCowGame::CheckGuessValidity(FString) const
{
	return EWordStatus::OK;
}

// receives a valid guess increments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// increment turn number
	MyCurrentTry++;

	// setup return structure
	FBullCowCount BullCowCount;

	// loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 MWHChar = 0; MWHChar < HiddenWordLength; MWHChar++) {
		// compare letters against the hidden word
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++)
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
