#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"

void fullDeckCounttest() {
	printf("Beginning test of fullDeckCount function\n");

	//initialize game
	struct gameState gamestate;
	int kingdomCards[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };

	initializeGame(2, kingdomCards, 5, &gamestate);


	//deck consists of hand, discard, and deck - get pre values of these variables to compare to values after function call
	//get count of cards in hand for player 0
	int preHandCount1 = gamestate.handCount[0];
	//get count of cards in hand for player 1
	int preHandCount2 = gamestate.handCount[1];
	//get count of cards in deck for player 0
	int preDeckCount1 = gamestate.deckCount[0];
	//get count of cards in deck for player 1
	int preDeckCount2 = gamestate.deckCount[1];
	//get count of cards in discard for player 0
	int preDiscardCount1 = gamestate.discardCount[0];
	//get count of cards in discard for player 1
	int preDiscardCount2 = gamestate.discardCount[1];

	int totalPreCardCount1 = preHandCount1 + preDeckCount1 + preDiscardCount1;
	int totalPreCardCount2 = preHandCount2 + preDeckCount2 + preDiscardCount2;
	//get count of victory cards
	int preEstateCount = gamestate.supplyCount[estate];
	int preDuchyCount = gamestate.supplyCount[duchy];
	int preProvinceCount = gamestate.supplyCount[province];



	int testValue = fullDeckCount_t(0, NULL, &gamestate);
	printf("TESTING CONDITION: NULL VALUE USED AS CARD ARGUMENT, VALUE 0, PLAYER 1, USED AS PLAYER ARGUMENT\n");
	if (totalPreCardCount1 == testValue)
		printf("PASS: Deck count calculated correctly for player 1. Deck count should be %d, and is %d.\n", totalPreCardCount1, testValue);
	else printf("FAIL: Deck count not calculated correctly for player 1. Deck count should be %d, but is %d.\n\n", totalPreCardCount1, testValue);


	testValue = fullDeckCount_t(0, 4, &gamestate);
	printf("TESTING CONDITION: VALUE 4, COPPER, USED AS CARD ARGUMENT, VALUE 0, PLAYER 1, USED AS PLAYER ARGUMENT\n");
	if (totalPreCardCount1 == testValue)
		printf("PASS: Deck count calculated correctly for player 1. Deck count should be %d, and is %d.\n", totalPreCardCount1, testValue);
	else printf("FAIL: Deck count not calculated correctly for player 1. Deck count should be %d, but is %d.\n\n", totalPreCardCount1, testValue);


	testValue = fullDeckCount_t(0, 0, &gamestate);
	printf("TESTING CONDITION: VALUE 0, CURSE, USED AS CARD ARGUMENT, VALUE 0, PLAYER 1, USED AS PLAYER ARGUMENT\n");
	if (totalPreCardCount1 == testValue)
		printf("PASS: Deck count calculated correctly for player 1. Deck count should be %d, and is %d.\n", totalPreCardCount1, testValue);
	else printf("FAIL: Deck count not calculated correctly for player 1. Deck count should be %d, but is %d.\n\n", totalPreCardCount1, testValue);


	testValue = fullDeckCount_t(1, 4, &gamestate);
	printf("TESTING CONDITION: VALUE 4, COPPER, USED AS CARD ARGUMENT, VALUE 1, PLAYER 2, USED AS PLAYER ARGUMENT\n");
	if (totalPreCardCount2 == testValue)
		printf("PASS: Deck count calculated correctly for player 2. Deck count should be %d, and is %d.\n", totalPreCardCount2, testValue);
	else printf("FAIL: Deck count not calculated correctly for player 2. Deck count should be %d, but is %d.\n\n", totalPreCardCount2, testValue);


	testValue = fullDeckCount_t(1, 0, &gamestate);
	printf("TESTING CONDITION: VALUE 0, CURSE, USED AS CARD ARGUMENT, VALUE 1, PLAYER 2, USED AS PLAYER ARGUMENT\n");
	if (totalPreCardCount2 == testValue)
		printf("PASS: Deck count calculated correctly for player 2. Deck count should be %d, and is %d.\n", totalPreCardCount2, testValue);
	else printf("FAIL: Deck count not calculated correctly for player 2. Deck count should be %d, but is %d.\n\n", totalPreCardCount2, testValue);

	


	printf("Completed fullDeckCount function test\n\n\n");



}