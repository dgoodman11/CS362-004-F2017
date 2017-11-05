#include "dominion.h"

int smithyfunction(int currentPlayer, int handPos, struct gameState *state) {
	//+3 Cards
	int i;
	for (i = 0; i < 3; i++)
	{
		drawCard(currentPlayer, state);
	}

	//discard card from hand
	discardCard(handPos, currentPlayer, state, 1);
	return 0;
}