#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"

void numHandCardstest() {
	printf("Beginning test of numHandCards function\n");

	struct gameState gamestate;
	int kingdomCards[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };

	initializeGame(2, kingdomCards, 5, &gamestate);



	int whoseTurn = gamestate.whoseTurn;
	int resultNumCardsInHand = numHandCards_t(&gamestate);
	int actualNumCardsInHand = gamestate.handCount[whoseTurn];
	int player2HandCount = gamestate.handCount[1];

	if (resultNumCardsInHand == actualNumCardsInHand)
		printf("PASS: function returned correct number of cards\n\n");
	else printf("FAIL: function did not return correct hand count\n\n");


	//add card to hand
	printf("Adding one card to current player's hand\n");
	gainCard_t(curse, &gamestate, 2, 0);

	resultNumCardsInHand = numHandCards_t(&gamestate);

	if (resultNumCardsInHand == actualNumCardsInHand + 1)
		printf("PASS: function returned correct hand count after adding card to hand\n\n");
	else printf("FAIL: function did not return correct hand count after adding card to hand\n\n");

	printf("Player 2 has %d cards in hand. Testing that function returns hand count for correct player\n", player2HandCount);
	resultNumCardsInHand = numHandCards_t(&gamestate);
	if (player2HandCount != resultNumCardsInHand)
		printf("PASS: function returns hand count for correct player. Player 1 (current player) has %d cards in hand, Player 2 has %d cards, and the function returned %d.\n\n", actualNumCardsInHand + 1, player2HandCount, resultNumCardsInHand);

}