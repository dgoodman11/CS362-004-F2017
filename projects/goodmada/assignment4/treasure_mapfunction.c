#include <stdio.h>
#include "dominion.h"

int treasure_mapfunction(int handPos, int currentPlayer, struct gameState *state) {
	//search hand for another treasure_map
	int index = -1;
	int i;
	for (i = 0; i < state->handCount[currentPlayer]; i++)
	{
		if (state->hand[currentPlayer][i] == treasure_map && i != handPos)
		{
			index = i;
			break;
		}
	}
	if (index > -1)
	{
		//trash both treasure cards
		discardCard(handPos, currentPlayer, state, 1);
		discardCard(index, currentPlayer, state, 1);

		//gain 4 Gold cards
		for (i = 0; i < 4; i++)
		{
			gainCard(gold, state, 1, currentPlayer); //add to deck
		}

		//return success
		return 1;
	}

	//no second treasure_map found in hand
	return -1;

}