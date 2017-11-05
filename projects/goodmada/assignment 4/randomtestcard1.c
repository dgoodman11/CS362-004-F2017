#include "randomTestHelpers.h"
#include <stdio.h>
#include "dominion.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main() {
	srand(time(NULL));
	int NUMTESTS = 10000;
	struct gameState preState;
	struct gameState postState;
	int preCardTotal;
	int postCardTotal;
	int errorFlag;
	int numPlayers;
	int currentPlayer;
	int randomSeed;
	int iteration ;
	int i;
	int j;
	int kingdomCards[10];
	int initializeGameSuccess;



	///	//set up loop to do many many iterations 
	for (iteration = 1; iteration < NUMTESTS; iteration++) {
		printf("ITERATION %d\n", iteration);
		numPlayers = randomNumPlayers(iteration);
		randomKingdomCards(&kingdomCards, iteration);
		randomSeed = rand();
		currentPlayer = randomCurrentPlayer(numPlayers);
		errorFlag = 0;


		initializeGameSuccess = initializeGame(numPlayers, &kingdomCards, randomSeed, &preState);

		if (initializeGameSuccess != -1) {
			memcpy(&postState, &preState, sizeof(struct gameState));
			gainCard(13, &postState, 2, currentPlayer);
			smithyfunction(currentPlayer, postState.handCount[currentPlayer] - 1, &postState);
		

			//now check that current player's hand count increased by 3, but total card count didn't change
			//compare expected hand count to actual hand count
			if (preState.handCount[currentPlayer] + 2 == postState.handCount[currentPlayer])
				printf("PASS: Hand count correct for current player\n");
			else {
				printf("FAIL: Hand count incorrect. Should be %d, but is %d\n", preState.handCount[currentPlayer] + 2, postState.handCount[currentPlayer]);
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



			for (j = 0; j < numPlayers; j++) {
				if (j != currentPlayer) {
					//compare expected hand count to actual hand count for non-current players
					if (preState.handCount[j] == postState.handCount[j])
						printf("PASS: Hand count correct for player %d\n", j);
					else {
						printf("FAIL: Hand count incorrect for player %d. Should be %d, but is %d\n", j, preState.handCount[j], postState.handCount[j]);
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
		else printf("Iteration %d did not initialize properly\n", iteration);
		printf("Iteration: %d, Num players: %d, Current Player: %d, Random seed: %d\n", iteration, numPlayers, currentPlayer, randomSeed);
	}
	return 0;
}