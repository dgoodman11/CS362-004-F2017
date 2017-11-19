#include <stdio.h>
#include "dominion.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "randomTestHelpers.h"


int main() {
	
	srand(time(NULL));
	int NUMTESTS = 10000;
	struct gameState preState;
	struct gameState postState;
	int preCardTotal;
	int postCardTotal;
	int preTreasureCount;
	int postTreasureCount;
	int errorFlag;
	int numPlayers;
	int currentPlayer;
	int randomSeed;
	int iteration = 1;
	int i;
	int j;
	int k;
	int kingdomCards[10];
	int tempVal;
	int initializeGameSuccess;



///	//set up loop to do many many iterations 
	for (iteration = 1; iteration < NUMTESTS; iteration++) {

		numPlayers = randomNumPlayers(iteration);
		randomKingdomCards(&kingdomCards, iteration);
		randomSeed = rand();
		currentPlayer = randomCurrentPlayer(numPlayers);
		errorFlag = 0;
		preTreasureCount = 0;
		postTreasureCount = 0;
		
		initializeGameSuccess = initializeGame(numPlayers, &kingdomCards, randomSeed, &preState);

		if (initializeGameSuccess != -1) {
			memcpy(&postState, &preState, sizeof(struct gameState));
			adventurerFunc(currentPlayer, &postState);


			//tests comparing postState to changes expected to preState////////////////////////////////////////////////////////////////////////////////

			//compare expected hand count to actual hand count
			if (preState.handCount[currentPlayer] + 2 == postState.handCount[currentPlayer])
				printf("PASS: Hand count correct for current player\n");
			else {
				printf("FAIL: Hand count incorrect. Should be %d, but is %d\n", preState.handCount[currentPlayer] + 2, postState.handCount[currentPlayer]);
				errorFlag = 1;
			}



			//check that the two cards added to hand are treasure cards
			for (j = 0; j < preState.handCount[currentPlayer]; j++) {
				if (preState.hand[currentPlayer][j] == copper || preState.hand[currentPlayer][j] == silver
					|| preState.hand[currentPlayer][j] == gold) {
					preTreasureCount++;
				}
			}

			for (j = 0; j < postState.handCount[currentPlayer]; j++) {
				if (postState.hand[currentPlayer][j] == copper || postState.hand[currentPlayer][j] == silver
					|| postState.hand[currentPlayer][j] == gold) {
					postTreasureCount++;
				}
			}

			if (preTreasureCount + 2 == postTreasureCount)
				printf("PASS: treasure count in hand increased by 2 for current player\n");
			else {
				printf("FAIL: treasure count did not increase by 2 for current player. Treasure count should be %d, but is %d\n", preTreasureCount + 2, postTreasureCount);
				errorFlag = 1;
			}



			//total number of cards between deck, discard, and hand for current player
			preCardTotal = preState.deckCount[currentPlayer] + preState.handCount[currentPlayer] + preState.discardCount[currentPlayer];
			postCardTotal = postState.deckCount[currentPlayer] + postState.handCount[currentPlayer] + postState.discardCount[currentPlayer];
			if (preCardTotal == postCardTotal)
				printf("PASS: card total for current player did not change\n");
			else {
				printf("FAIL: card total for current player should be %d, but is %d\n", preCardTotal, postCardTotal);
				errorFlag = 1;
			}


			//reset pre and post treasure counts before testing other player's decks
			preTreasureCount = 0;
			postTreasureCount = 0;

			//same set of tests for non-current players
			for (j = 0; j < numPlayers; j++) {
				if (j != currentPlayer) {
					//compare expected hand count to actual hand count for non-current players
					if (preState.handCount[j] == postState.handCount[j])
						printf("PASS: Hand count correct for player %d\n", j);
					else {
						printf("FAIL: Hand count incorrect for player %d. Should be %d, but is %d\n", j, preState.handCount[j], postState.handCount[j]);
						errorFlag = 1;
					}


					//check that no treasure cards are added to non-current player's hand
					for (k = 0; k < preState.handCount[j]; k++) {
						if (preState.hand[j][k] == copper || preState.hand[j][k] == silver
							|| preState.hand[j][k] == gold) {
							preTreasureCount++;
						}
					}

					for (k = 0; k < postState.handCount[j]; k++) {
						if (postState.hand[j][k] == copper || postState.hand[j][k] == silver
							|| postState.hand[j][k] == gold) {
							postTreasureCount++;
						}
					}

					if (preTreasureCount == postTreasureCount)
						printf("PASS: treasure count did not increase for player %d\n", j);
					else {
						printf("FAIL: treasure count changed for player %d. Treasure count should be %d, but is %d\n", j, preTreasureCount, postTreasureCount);
						errorFlag = 1;
					}


					//check total card count for non-current players
					preCardTotal = preState.deckCount[j] + preState.handCount[j] + preState.discardCount[j];
					postCardTotal = postState.deckCount[j] + postState.handCount[j] + postState.discardCount[j];
					if (preCardTotal == postCardTotal)
						printf("PASS: card total for player %d did not change\n", j);
					else {
						printf("FAIL: card total for player %d should be %d, but is %d\n", j, preCardTotal, postCardTotal);
						errorFlag = 1;
					}



				}
			}

		}
		else {
			printf("Could not initialize game on iteration %d\n", iteration);
		}

		//	if (errorFlag)
		printf("Iteration: %d\nNum players: %d\nCurrent Player: %d\nRandom seed: %d\n", iteration, numPlayers, currentPlayer, randomSeed);
	
} 
	return 0;
}

