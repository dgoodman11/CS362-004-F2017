#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "unittestheader.h"

void sea_hagtest() {
	printf("Beginning test of Sea Hag card\n");

	int i;

	//initialize game
	struct gameState gamestate;
	int kingdomCards[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };

	initializeGame(2, kingdomCards, 5, &gamestate);



	int preKingdomCards[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };
	//get supply count of curse cards
	int preCurseCards = gamestate.supplyCount[curse];
	//get P1 deck count
	int preDeckCount1 = gamestate.deckCount[0];
	//get P2 deck count
	int preDeckCount2 = gamestate.deckCount[1];
	//get P1 hand count
	int preHandCount1 = gamestate.handCount[0];
	//get P2 hand count
	int preHandCount2 = gamestate.handCount[1];
	//get P1 discard count
	int preDiscardCount1 = gamestate.discardCount[0];
	//get P2 discard count
	int preDiscardCount2 = gamestate.discardCount[1];
	//get count of kingdom cards
	int preEstateCount = gamestate.supplyCount[estate];
	int preDuchyCount = gamestate.supplyCount[duchy];
	int preProvinceCount = gamestate.supplyCount[province];


	
	sea_hagfunction(0, &gamestate);



	//Player 2 top card is curse
	if (gamestate.deck[1][gamestate.deckCount[1] - 1] == curse) {
		printf("PASS: Player 2's top card is a curse card\n");
	}
	else printf("FAIL: Player 2's top card not a curse card\n");

	//Player 2 deck = deck + 1
	if (preDeckCount2 == gamestate.deckCount[1] + 1) {
		printf("PASS: Player 2 had one card added to deck\n");
	}
	else printf("FAIL: Player 2 did not have card added to deck\n");

	//Player 1 deck the same
	if (preDeckCount1 == gamestate.deckCount[0]) {
		printf("PASS: Player 1's deck count unchanged\n");
	}
	else printf("FAIL: Player 1's deck count changed. Start count was %d, now is %d\n", preDeckCount1, gamestate.deckCount[0]);

	
	//Player 1 discard + 1
	if (preDiscardCount1 + 1 == gamestate.discardCount[0]) {
		printf("PASS: One card added to Player 1's discard pile\n");
	}
	else printf("FAIL: No cards added to Player 1's discard pile. Sea Hag should have been added\n");

	//is discarded card the sea hag
	if (gamestate.discard[0][0] == sea_hag) {
		printf("PASS: discarded card is the sea hag\n");
	}
	else printf("FAIL: discarded card is not the sea hag\n");

	//Player 2 discard unchanged
	if (preDiscardCount2 == gamestate.discardCount[1]) {
		printf("PASS: No cards added to Player 2's discard pile\n");
	}
	else printf("FAIL: Cards added to Player 2's discard pile\n");

	//Player 1 hand - 1 (sea hag discarded)
	if (preHandCount1 - 1 == gamestate.handCount[0]) {
		printf("PASS: Player 1 now has one less card in hand\n");
	}
	else printf("FAIL: Player 1 has wrong number of cards in hand. Has %d cards, but should have %d\n", gamestate.handCount[0], preHandCount1 - 1);


	//Player 2 hand unchanged
	if (preHandCount2 == gamestate.handCount[1]) {
		printf("PASS: Player 2's hand count unchanged\n");
	}
	else printf("FAIL: Player 2's hand count changed\n");

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

	//supply count of curse cards -1
	if (preCurseCards - 1 == gamestate.supplyCount[curse]) {
		printf("PASS: Supply count of curse cards went down by 1\n");
	}
	else printf("FAIL: Supply count of curse cards should have decreased by 1. Start count was %d, current count is %d\n", preCurseCards, gamestate.supplyCount[curse]);


	printf("Completed sea hag card test\n\n");

}
