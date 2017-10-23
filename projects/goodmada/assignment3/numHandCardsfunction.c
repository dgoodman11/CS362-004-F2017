#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"

int numHandCards_t(struct gameState *state) {
	return state->handCount[whoseTurn(state)];
}