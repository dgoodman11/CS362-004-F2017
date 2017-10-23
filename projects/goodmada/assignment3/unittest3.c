#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"

//returns true when province == 0, or 3 others == 0
//test both conditions


void isGameOvertest() {
	printf("Beginning test of isGameOver function\n");

	struct gameState gamestate;
	int kingdomCards[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };

	initializeGame(2, kingdomCards, 5, &gamestate);

	gamestate.supplyCount[curse] = 10;
	gamestate.supplyCount[estate] = 10;
	gamestate.supplyCount[duchy] = 10;
	gamestate.supplyCount[province] = 10;
	gamestate.supplyCount[copper] = 10;
	gamestate.supplyCount[silver] = 10;
	gamestate.supplyCount[gold] = 10;
	gamestate.supplyCount[adventurer] = 10;
	gamestate.supplyCount[council_room] = 10;
	gamestate.supplyCount[feast] = 10;
	gamestate.supplyCount[gardens] = 10;
	gamestate.supplyCount[mine] = 10;
	gamestate.supplyCount[remodel] = 10;
	gamestate.supplyCount[village] = 10;
	gamestate.supplyCount[baron] = 10;
	gamestate.supplyCount[great_hall] = 10;
	gamestate.supplyCount[minion] = 10;
	gamestate.supplyCount[steward] = 10;
	gamestate.supplyCount[tribute] = 10;
	gamestate.supplyCount[ambassador] = 10;
	gamestate.supplyCount[cutpurse] = 10;
	gamestate.supplyCount[embargo] = 10;
	gamestate.supplyCount[outpost] = 10;
	gamestate.supplyCount[salvager] = 10;
	gamestate.supplyCount[sea_hag] = 10;
	gamestate.supplyCount[treasure_map] = 10;

	int testReturnValue;


	//case 1: all supply counts > 0
	printf("Testing Case 1: All supply counts > 0\n");
	testReturnValue = isGameOver_t(&gamestate);
	if (testReturnValue == 0)
		printf("PASS: Return value correct, game is not over\n\n");
	else printf("FAIL: Return value incorrect, game is not over\n\n");
	

	//case 2: province == 0, all others > 0
	printf("Testing Case 2: Province == 0. All other supply counts > 0\n");
	gamestate.supplyCount[province] = 0;
	testReturnValue = isGameOver_t(&gamestate);
	if (testReturnValue == 1)
		printf("PASS: Return value correct, game is over\n\n");
	else printf("FAIL: Return value incorrect, game is over\n\n");


	//case 3: province > 0, treasure map, curse, mine == 0, all others > 0 (first, last, middle)
	printf("Testing Case 3: Province > 0, First, last, and middle enums (treasure map, curse, mine) == 0, all others > 0\n");
	gamestate.supplyCount[province] = 10;
	gamestate.supplyCount[curse] = 0;
	gamestate.supplyCount[mine] = 0;
	gamestate.supplyCount[treasure_map] = 0;
	testReturnValue = isGameOver_t(&gamestate);
	if (testReturnValue == 1)
		printf("PASS: Return value correct, game is over\n\n");
	else printf("FAIL: Return value incorrect, game is over\n\n");


	//case 4: first 3 == 0, others > 0
	printf("Testing Case 4: Supply count of first 3 enumns == 0, All other supply counts > 0\n");
	gamestate.supplyCount[mine] = 10;
	gamestate.supplyCount[treasure_map] = 10;
	gamestate.supplyCount[estate] = 0;
	gamestate.supplyCount[duchy] = 0;
	testReturnValue = isGameOver_t(&gamestate);
	if (testReturnValue == 1)
		printf("PASS: Return value correct, game is over\n\n");
	else printf("FAIL: Return value incorrect, game is over\n\n");


	//case 5: last 3 == 0, others > 0 
	printf("Testing Case 5: Supply count of last 3 enumns == 0, All other supply counts > 0\n");
	gamestate.supplyCount[curse] = 10;
	gamestate.supplyCount[estate] = 10;
	gamestate.supplyCount[duchy] = 10;
	gamestate.supplyCount[salvager] = 0;
	gamestate.supplyCount[sea_hag] = 0;
	gamestate.supplyCount[treasure_map] = 0;
	testReturnValue = isGameOver_t(&gamestate);
	if (testReturnValue == 1)
		printf("PASS: Return value correct, game is over\n\n");
	else printf("FAIL: Return value incorrect, game is over\n\n");

	printf("Completed isGameOver function test\n\n\n");


}