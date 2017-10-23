#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"


void adventurertest() {
	printf("Beginning test of Adventurer card\n");

	int i;

	int preKingdomCards[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };


	struct gameState gamestate;
	int kingdomCards[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };

	initializeGame(2, kingdomCards, 5, &gamestate);

	gamestate.hand[0][gamestate.handCount[0]] = adventurer;//Add adventurer to last (5th) position of player 1's hand
	gamestate.handCount[0]++;


	//get count of treasure cards in hand for player 1
	int card;
	int preTreasureCount1 = 0;
	int preTreasureCount2 = 0;

	for (i = 0; i < gamestate.handCount[0]; i++) {
		card = gamestate.hand[0][i];
		if (card == copper || card == silver || card == gold) {
			preTreasureCount1++;
		}
	}
 

	//get count of treasure cards in hand for player 2
	for (i = 0; i < gamestate.handCount[1]; i++) {
		card = gamestate.hand[1][i];
		if (card == copper || card == silver || card == gold) {
			preTreasureCount2++;
		}
	}





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
	



	adventurerfunction(0, 0, 0, &gamestate);


	
	//player 1 hand count should be +1, 2 more treasures, adventurer is discarded
	if (gamestate.handCount[0] == preHandCount1 + 1) {
		printf("PASS: Player 1 hand count is correct\n");
	}
	else printf("FAIL: Player 1 hand count is incorrect. Hand count should be %d, but is %d.\n", preHandCount1 + 1, gamestate.handCount[0]);
	

	//player 1 deck count should be less than starting value
	if (preDeckCount1 - 2 > gamestate.deckCount[0]) {
		printf("PASS: cards were drawn from deck");
	}
	else printf("FAIL: non-treasure cards not drawn from deck. Previous deck count is: %d, current is %d\n", preDeckCount1, gamestate.deckCount[0]);

	//player 1 deck + discard + hand count should be equal pre and post
	if (totalPreCardCount1 == gamestate.handCount[0] + gamestate.deckCount[0] + gamestate.discardCount[0]) {
		printf("PASS: No cards were gained or lost for Player 1\n");
	}
	else printf("FAIL: Total card count is not equal - Player 1 lost or gained cards. Started with % total cards, now has % cards.\n", totalPreCardCount1, gamestate.handCount[0] + gamestate.deckCount[0] + gamestate.discardCount[0]);

	//player 2 deck + discard + hand count should be equal pre and post
	if (totalPreCardCount2 == gamestate.handCount[1] + gamestate.deckCount[1] + gamestate.discardCount[1]) {
		printf("PASS: No cards were gained or lost for Player 2\n");
	}
	else printf("FAIL: Total card count is not equal - Player 2 lost or gained cards. Started with % total cards, now has % cards.\n", totalPreCardCount2, gamestate.handCount[1] + gamestate.deckCount[1] + gamestate.discardCount[1]);


	//player 1 treasure count should be +2
	int postTreasureCount1 = 0;
	int postTreasureCount2 = 0;

	for (i = 0; i < gamestate.handCount[0]; i++) {
		card = gamestate.hand[0][i];
		if (card == copper || card == silver || card == gold) {
			postTreasureCount1++;
		}
	}

	if (preTreasureCount1 + 2 == postTreasureCount1) {
		printf("PASS: Player 1 treasure count in hand is correct: there are now 2 more treasures in hand.\n");
	}
	else printf("FAIL: Player 1 treasure count in hand is incorrect. Treasure count should be %d, but is %d.\n", preTreasureCount1 + 2, postTreasureCount1);


	//player 2 treasure count should be unchanged
	for (i = 0; i < gamestate.handCount[1]; i++) {
		card = gamestate.hand[1][i];
		if (card == copper || card == silver || card == gold) {
			postTreasureCount2++;
		}
	}

	if (preTreasureCount2 == postTreasureCount2) {
		printf("PASS: Player 2 treasure count in hand is correct\n");
	}
	else printf("FAIL: Player 2 treasure count in hand is incorrect. Treasure count should be %d, but is %d.\n", preTreasureCount2, postTreasureCount2);



	//player 1 discard count should be > previous + 1
	if (gamestate.discardCount[0] > preDiscardCount1 + 1) {
		printf("PASS: Non-treasure cards were discarded\n");
	}
	else printf("FAIL: Cards were not discarded. There are %d cards in the discard pile.\n", gamestate.discardCount[0]);



	//check that other player's hand is unchanged
	if (preHandCount2 == gamestate.handCount[1]) {
		printf("PASS: hand count for Player 2 correct\n");
	}
	else printf("FAIL: hand count for Player 2 incorrect\n");


	//check that other player's deck is unchanged
	if (preDeckCount2 == gamestate.deckCount[1]) {
		printf("PASS: deck count for Player 2 correct\n");
	}
	else printf("FAIL: deck count for Player 2 incorrect\n");


	//check that other player's discard count is unchanged
	if (preDiscardCount2 == gamestate.discardCount[1]) {
		printf("PASS: discard count for Player 2 correct\n");
	}
	else printf("FAIL: discard count for Player 2 incorrect\n");


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

	printf("Completed adventurer card test\n\n");


}
