#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"

void gainCardtest() {
	printf("Beginning test of gainCard function\n");

	//initialize game
	struct gameState gamestate;
	int kingdomCards[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };

	initializeGame(2, kingdomCards, 5, &gamestate);

	int preDeckCount = gamestate.deckCount[0];
	int preHandCount = gamestate.handCount[0];
	int preDiscardCount = gamestate.discardCount[0];
	int preCurseSupplyCount = gamestate.supplyCount[curse];



	//test add curse to hand 
	printf("TESTING CONDITION: ADD CURSE CARD TO HAND\n");
	gainCard_t(curse, &gamestate, 2, 0);

	int postDeckCount = gamestate.deckCount[0];
	int postHandCount = gamestate.handCount[0];
	int postDiscardCount = gamestate.discardCount[0];
	int postSupplyCount = gamestate.supplyCount[curse];

	if (preHandCount + 1 == postHandCount)
		printf("PASS: card successfully added to hand\n");
	else printf("FAIL: hand count should be %d, but is %d.\n", preHandCount + 1, postHandCount);

	if (preDeckCount != postDeckCount)
		printf("FAIL: deck count should be unchanged\n");
	else printf("PASS: deck count unchanged\n");

	if (preDiscardCount != postDiscardCount)
		printf("FAIL: discard count should be unchanged\n");
	else printf("PASS: discard count unchanged\n");

	if (preCurseSupplyCount - 1 != postSupplyCount)
		printf("FAIL: Curse supply count did not decrease. Should be %d, but is %d.\n", preCurseSupplyCount - 1, postSupplyCount);
	else printf("PASS: Curse supply count decreased by 1\n");

	preHandCount++;
	preCurseSupplyCount--;

	//add to deck curse
	printf("TESTING CONDITION: ADD CURSE CARD TO DECK\n");
	gainCard_t(curse, &gamestate, 1, 0);

	postDeckCount = gamestate.deckCount[0];
	postHandCount = gamestate.handCount[0];
	postDiscardCount = gamestate.discardCount[0];
	postSupplyCount = gamestate.supplyCount[curse];

	if (preDeckCount + 1 == postDeckCount)
		printf("PASS: card successfully added to deck\n");
	else printf("FAIL: deck count should be %d, but is %d.\n", preDeckCount + 1, postDeckCount);

	if (preDiscardCount != postDiscardCount)
		printf("FAIL: discard count should be unchanged\n");
	else printf("PASS: discard count unchanged\n");

	if (preHandCount != postHandCount)
		printf("FAIL: hand count should be unchanged\n");
	else printf("PASS: hand count unchanged\n");

	if (preCurseSupplyCount - 1 != postSupplyCount)
		printf("FAIL: Curse supply count did not decrease. Should be %d, but is %d.\n", preCurseSupplyCount - 1, postSupplyCount);
	else printf("PASS: Curse supply count decreased by 1\n");

	preCurseSupplyCount--;
	preDeckCount++;

	//add to discard curse
	printf("TESTING CONDITION: ADD CURSE CARD TO DISCARD\n");
	gainCard_t(curse, &gamestate, 0, 0);

	postDeckCount = gamestate.deckCount[0];
	postHandCount = gamestate.handCount[0];
	postDiscardCount = gamestate.discardCount[0];
	postSupplyCount = gamestate.supplyCount[curse];

	if (preDiscardCount + 1 == postDiscardCount)
		printf("PASS: card successfully added to discard\n");
	else printf("FAIL: discard count should be %d, but is %d.\n", preDiscardCount + 1, postDiscardCount);

	if (preHandCount != postHandCount)
		printf("FAIL: hand count should be unchanged\n");
	else printf("PASS: hand count unchanged\n");

	if (preDeckCount != postDeckCount)
		printf("FAIL: deck count should be unchanged\n");
	else printf("PASS: deck count unchanged\n");

	if (preCurseSupplyCount - 1 != postSupplyCount)
		printf("FAIL: Curse supply count did not decrease. Should be %d, but is %d.\n", preCurseSupplyCount - 1, postSupplyCount);
	else printf("PASS: Curse supply count decreased by 1\n");

	preCurseSupplyCount--;
	preDiscardCount++;



	//add using bogus flag (not 0, 1, or 2) curse
	printf("TESTING CONDITION: FLAG THAT INDICATES WHERE TO ADD CARD (DECK, HAND, DISCARD) IS INVALID\n");
	gainCard_t(curse, &gamestate, 10, 0);

	postDeckCount = gamestate.deckCount[0];
	postHandCount = gamestate.handCount[0];
	postDiscardCount = gamestate.discardCount[0];
	postSupplyCount = gamestate.supplyCount[curse];


	if (preHandCount != postHandCount)
		printf("FAIL: hand count should be unchanged. hand count should be %d, but is %d.\n", preHandCount, postHandCount);
	else printf("PASS: hand count unchanged, should be %d, and is %d.\n", preHandCount, postHandCount);

	if (preDeckCount != postDeckCount)
		printf("FAIL: deck count should be unchanged\n");
	else printf("PASS: deck count unchanged\n");

	if (preDiscardCount != postDiscardCount)
		printf("FAIL: discard count should be unchanged. Discard count should be %d, but is %d.\n", preDiscardCount, postDiscardCount); 
	else printf("PASS: discard count unchanged\n");

	if (preCurseSupplyCount != postSupplyCount)
		printf("FAIL: Curse supply count should not change. Should be %d, but is %d.\n", preCurseSupplyCount, postSupplyCount);
	else printf("PASS: Curse supply count unchanged\n");

	preDiscardCount++;

	//test add card to hand with zero supplyCount
	printf("TESTING CONDITION: ADD CURSE CARD TO HAND WHEN CURSE SUPPLY COUNT IS 0\n");
	gamestate.supplyCount[curse] = 0;
	preCurseSupplyCount = gamestate.supplyCount[curse];

	gainCard_t(curse, &gamestate, 2, 0);

	postDeckCount = gamestate.deckCount[0];
	postHandCount = gamestate.handCount[0];
	postDiscardCount = gamestate.discardCount[0];
	postSupplyCount = gamestate.supplyCount[curse];


	if (preHandCount != postHandCount)
		printf("FAIL: supply count was 0, so nothing should have been added to hand\n");
	else printf("PASS: hand count unchanged, should be %d, and is %d.\n", preHandCount, postHandCount);

	if (preDeckCount != postDeckCount)
		printf("FAIL: deck count should be unchanged\n");
	else printf("PASS: deck count unchanged\n");

	if (preDiscardCount != postDiscardCount)
		printf("FAIL: discard count should be unchanged\n");
	else printf("PASS: discard count unchanged\n");

	if (preCurseSupplyCount != postSupplyCount)
		printf("FAIL: Curse supply count should not change. Should be %d, but is %d.\n", preCurseSupplyCount - 1, postSupplyCount);
	else printf("PASS: Curse supply count unchanged\n");





	




	//add to deck zero supply count
	gainCard_t(curse, &gamestate, 1, 0);

	postDeckCount = gamestate.deckCount[0];
	postHandCount = gamestate.handCount[0];
	postDiscardCount = gamestate.discardCount[0];
	postSupplyCount = gamestate.supplyCount[curse];


	//add to discard zero supply count
	gainCard_t(curse, &gamestate, 0, 0);

	postDeckCount = gamestate.deckCount[0];
	postHandCount = gamestate.handCount[0];
	postDiscardCount = gamestate.discardCount[0];
	postSupplyCount = gamestate.supplyCount[curse];



	printf("Completed gainCard function test\n\n\n");


}
	
	
	