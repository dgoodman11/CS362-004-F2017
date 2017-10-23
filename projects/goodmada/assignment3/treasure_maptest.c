#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"

void treasure_maptest() {
	printf("Beginning test of Treasure Map card\n");

	int i;
	int card;
	int treasure_mapCount = 0;
	int kingdomCards[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };
	int preDeckCount;
	int preGoldDeckCount = 0; 
	int postGoldDeckCount = 0;
	int preHandCount;
	int preDiscardCount;
	int preEstateCount;
	int preDuchyCount;
	int preProvinceCount;



	//Condition 1 - only 1 treasure map in hand
	printf("Testing condition 1 treasure map in hand\n");
	struct gameState gamestate;
	initializeGame(2, kingdomCards, 5, &gamestate);

	for (i = 0; i < gamestate.handCount[0]; i++) {
		card = gamestate.hand[0][i];
		if (card == treasure_map) {
			treasure_mapCount++;
		}
	}
	printf("Number of treasure maps in starting hand: %d\n", treasure_mapCount);

	printf("Adding 1 treasure map card to hand for testing\n");
	gamestate.hand[0][gamestate.handCount[0]] = treasure_map;//Add adventurer to last (5th) position of player 1's hand
	gamestate.handCount[0]++;

	preDeckCount = gamestate.deckCount[0];
	for (i = 0; i < gamestate.deckCount[0]; i++) {
		if (gamestate.deck[0][i] == gold) {
			preGoldDeckCount++;
		}
	}
	preHandCount = gamestate.handCount[0];
	preDiscardCount = gamestate.discardCount[0];
	preEstateCount = gamestate.supplyCount[estate];
	preDuchyCount = gamestate.supplyCount[duchy];
	preProvinceCount = gamestate.supplyCount[province];


	treasure_mapfunction(5, 0, &gamestate);

	//hand count should be -1
	if (preHandCount - 1 == gamestate.handCount[0]) {
		printf("PASS: Hand count decreased by 1\n");
	}
	else printf("FAIL: Hand count should be %d, but is %d\n", preHandCount - 1, gamestate.handCount[0]);

	//deck count same
	if (preDeckCount == gamestate.deckCount[0]) {
		printf("PASS: Deck count unchanged\n");
	}
	else printf("FAIL: Deck count should be %d, but is %d.\n", preDeckCount, gamestate.deckCount[0]);

	//discard count same
	if (preDiscardCount == gamestate.discardCount[0]) {
		printf("PASS: Discard count unchanged\n");
	}
	else printf("FAIL: Discard count should be %d, but is %d.\n", preDiscardCount, gamestate.discardCount[0]);

	//gold in deck same
	for (i = 0; i < gamestate.deckCount[0]; i++) {
		if (gamestate.deck[0][i] == gold) {
			postGoldDeckCount++;
		}
	}
	if (preGoldDeckCount == postGoldDeckCount) {
		printf("PASS: Gold count in deck unchanged\n");
	}
	else printf("FAIL: Gold count in deck should be %d, but is %d.\n", preGoldDeckCount, postGoldDeckCount);

	//check that victory cards are unchanged
	if (preEstateCount != gamestate.supplyCount[estate] || preDuchyCount != gamestate.supplyCount[duchy] || preProvinceCount != gamestate.supplyCount[province]) {
		printf("FAIL: Victory Cards were changed\n");
	}
	else printf("PASS: Victory Cards unchanged\n");








	//Condition 2 - 2 treasure maps in hand
	printf("Testing condition 2 treasure maps in hand\n");
	treasure_mapCount = 0;
	preGoldDeckCount = 0;
	postGoldDeckCount = 0;

	struct gameState gamestate2;
	initializeGame(2, kingdomCards, 5, &gamestate2);

	for (i = 0; i < gamestate2.handCount[0]; i++) {
		card = gamestate2.hand[0][i];
		if (card == treasure_map) {
			treasure_mapCount++;
		}
	}
	printf("Number of treasure maps in starting hand: %d\n", treasure_mapCount);

	printf("Adding 2 treasure map cards to hand for testing\n");
	gamestate2.hand[0][gamestate2.handCount[0]] = treasure_map;//Add adventurer to last (5th) position of player 1's hand
	gamestate2.handCount[0]++;
	gamestate2.hand[0][gamestate2.handCount[0]] = treasure_map;//Add adventurer to last (6th) position of player 1's hand
	gamestate2.handCount[0]++;


	preDeckCount = gamestate2.deckCount[0];
	for (i = 0; i < gamestate2.deckCount[0]; i++) {
		if (gamestate2.deck[0][i] == gold) {
			preGoldDeckCount++;
		}
	}
	preHandCount = gamestate2.handCount[0];
	preDiscardCount = gamestate2.discardCount[0];
	preEstateCount = gamestate2.supplyCount[estate];
	preDuchyCount = gamestate2.supplyCount[duchy];
	preProvinceCount = gamestate2.supplyCount[province];


	treasure_mapfunction(5, 0, &gamestate2);

	//hand count should be -2
	if (preHandCount - 2 == gamestate2.handCount[0])
		printf("PASS: hand count decreased by 2\n");
	else printf("FAIL: hand count should be %d, but is %d", preHandCount, gamestate2.handCount[0]);

	//deck count should be +4
	if (preDeckCount + 4 == gamestate2.deckCount[0])
		printf("PASS: deck count increased by 4\n");
	else printf("FAIL: deck count should be %d, but is %d", preDeckCount + 4, gamestate2.deckCount[0]);

	//golds in deck +4
	for (i = 0; i < gamestate2.deckCount[0]; i++) {
		if (gamestate2.deck[0][i] == gold) {
			postGoldDeckCount++;
		}
	}
	if (preGoldDeckCount + 4 == postGoldDeckCount)
		printf("PASS: gold count in deck increased by 4\n");
	else printf("FAIL: gold count should be %d, but is %d.\n", preGoldDeckCount + 4, postGoldDeckCount);

	//discard unchanged
	if (preDiscardCount == gamestate2.discardCount[0])
		printf("PASS: no cards were discarded (treasure map card should be trashed\n");
	else printf("FAIL: discard count should be %d, but is %d.\n", preDiscardCount, gamestate2.discardCount[0]);

	//kingdom cards unchanged
	//check that victory cards are unchanged
	if (preEstateCount != gamestate2.supplyCount[estate] || preDuchyCount != gamestate2.supplyCount[duchy] || preProvinceCount != gamestate2.supplyCount[province]) {
		printf("FAIL: Victory Cards were changed\n");
	}
	else printf("PASS: Victory Cards unchanged\n");

	printf("Completed Treasure Map card test\n\n");

}
