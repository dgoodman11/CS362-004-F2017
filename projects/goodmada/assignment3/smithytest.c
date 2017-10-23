#include <stdio.h>
#include <stdlib.h>

#include "dominion.h"
#include "dominion_helpers.h"

//repeat with more values - standard case, min and max


void smithytest() {
	printf("Beginning test of Smithy card\n");

	int i;

	int preKingdomCards[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };


	struct gameState gamestate;
	int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy};

	initializeGame(2, kingdomCards, 5, &gamestate);
	//now whoseturn, 0, current player, should have 5 cards in hand, while the other player has none in hand

	//note values after initialization to compare to values after running smithy function
	int preHandCount1 = gamestate.handCount[0];
	int preHandCount2 = gamestate.handCount[1];
	int preDeckCount1 = gamestate.deckCount[0];
	int preDeckCount2 = gamestate.deckCount[1];
	int preDiscardCount1 = gamestate.discardCount[0];
	int preDiscardCount2 = gamestate.discardCount[1];
	//get count of victory cards
	int preEstateCount = gamestate.supplyCount[estate];
	int preDuchyCount = gamestate.supplyCount[duchy];
	int preProvinceCount = gamestate.supplyCount[province];

	
	//run smithy function for testing
	int testvalue = smithyfunction(0, 1, &gamestate);


	//compare values after running smithy function

	//check that current player has 2 more in hand (3 were drawn during turn, but smithy card was discarded
	if (preHandCount1 + 2 == gamestate.handCount[0]) {
		printf("PASS: hand count for current player correct\n");
	}
	else printf("FAIL: hand count for current player incorrect\n");


	//check that other player's hand is unchanged
	if (preHandCount2 == gamestate.handCount[1]) {
		printf("PASS: hand count for other player correct\n");
	}
	else printf("FAIL: hand count for other player incorrect\n");

	//check that current player's deck has 3 less cards
	if (preDeckCount1 - 3 == gamestate.deckCount[0]) {
		printf("PASS: deck count for current player correct\n");
	}
	else printf("FAIL: deck count for current player incorrect");

	//check that other player's deck is unchanged
	if (preDeckCount2 == gamestate.deckCount[1]) {
		printf("PASS: deck count for other player correct\n");
	}
	else printf("FAIL: deck count for other player incorrect\n");

	//check that current players discard count increased by 1 (discarded played smithy card)
	if (preDiscardCount1 + 1 == gamestate.discardCount[0]) {
		printf("PASS: discard count for current player correct\n");
	}
	else printf("FAIL: discard count for current player incorrect. Discard count should be %d, but is %d\n", preDiscardCount1+1, gamestate.discardCount[0]);

	//check that other player's discard count is unchanged
	if (preDiscardCount2 == gamestate.discardCount[1]) {
		printf("PASS: discard count for other player correct\n");
	}
	else printf("FAIL: discard count for other player incorrect\n");

	//check that victory cards are unchanged
	if (preEstateCount != gamestate.supplyCount[estate] || preDuchyCount != gamestate.supplyCount[duchy] || preProvinceCount != gamestate.supplyCount[province]) {
		printf("FAIL: Victory Cards were changed\n");
	}
	else printf("PASS: Victory Cards unchanged\n");


	//check that kingdom cards are unchanged
	for (i = 0; i < 10; i++) {
		if (preKingdomCards[i] != kingdomCards[i]) {
			printf("FAIL: Kingdom Cards changed\n");
			break;
		}
	}
	printf("PASS: Kingdom Cards unchanged\n");

	if (testvalue == 0) {
		printf("PASS: smithy function return value correct\n");
	}
	else printf("FAIL: smithy function return value incorrect\n");
	
	printf("Completed test of Smithy Card\n\n");
}

