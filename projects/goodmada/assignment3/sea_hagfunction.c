#include "dominion.h"

int sea_hagfunction(int currentPlayer, struct gameState *state) {

	int i;
	for (i = 0; i < state->numPlayers; i++) {
		if (i == currentPlayer) {
			state->discard[i][state->discardCount[i]] = state->deck[i][state->deckCount[i]--];			    
			state->deckCount[i]--;
			state->discardCount[i]++;
			state->deck[i][state->deckCount[i]--] = curse;//Top card now a curse
		}
	}
	return 0;
}