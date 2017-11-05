#include "randomTestHelpers.h"
#include <stdio.h>
#include "dominion.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int randomNumCardsToHand();
int randCardToHand();
int alreadyTreasureMapInHand(struct gameState *state, int currentPlayer);
int treasureMapPos(struct gameState *state, int currentPlayer);
int treasureMapCount(struct gameState *state, int currentPlayer);


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
	int iteration;
	int i;
	int j;
	int kingdomCards[10] = { 7, 8, 19, 20, 21, 22, 23, 24, 25, 26 };
	int initializeGameSuccess;
	int addedCard1; //add one or two cards to current player's hand to make sure enough cards in hand, and catch both conditions: 1 treasure map in hand and 2
	int addedCard2;
	int treasuremapPos;
	int numCardsAdded;



	///	//set up loop to do many many iterations 
	for (iteration = 1; iteration < NUMTESTS; iteration++) {
		printf("ITERATION %d\n", iteration);
		numPlayers = randomNumPlayers(iteration);
//		randomKingdomCards(&kingdomCards, iteration);
		randomSeed = rand();
		currentPlayer = randomCurrentPlayer(numPlayers);
		errorFlag = 0;


		initializeGameSuccess = initializeGame(numPlayers, &kingdomCards, randomSeed, &preState);

		if (initializeGameSuccess != -1) {

			if (alreadyTreasureMapInHand(&preState, currentPlayer)) { //player already has a map in their hand
				addedCard1 = randCardToHand();
				gainCard(addedCard1, &preState, 2, currentPlayer); //add a random card to hand, possibly a second treasure map
				treasuremapPos = treasureMapPos(&preState, currentPlayer); //get the position of known treasure map
				
			}
			else { //no treasure maps in hand
				//add one or two cards to hand
				numCardsAdded = randomNumCardsToHand();
				addedCard1 = randCardToHand();
				gainCard(addedCard1, &preState, 2, currentPlayer); // add first random card to hand

				if (numCardsAdded == 2) {
					addedCard2 = randCardToHand();
					gainCard(addedCard2, &preState, 2, currentPlayer);
				}

				if (alreadyTreasureMapInHand(&preState, currentPlayer)) { //if drawn card is treasure, use that hand position in fuction call
					treasuremapPos = treasureMapPos(&preState, currentPlayer);
				}
				else treasuremapPos = preState.handCount[currentPlayer] - 1;
			}

			printf("Starting treasure maps in hand: %d\n", treasureMapCount(&preState, currentPlayer));
			memcpy(&postState, &preState, sizeof(struct gameState));
			treasure_mapfunction(treasuremapPos, currentPlayer, &postState);


			//set up tests to check function behavior
			if (treasureMapCount(&preState, currentPlayer) < 2 && preState.handCount[currentPlayer] != 0) {
				//confirm hand count - 1
				if (preState.handCount[currentPlayer] - 1 == postState.handCount[currentPlayer])
					printf("PASS: Hand count correct for current player\n");
				else printf("FAIL: Hand count incorrect for currrent player. Should be %d, but is %d\n", preState.handCount[currentPlayer] - 1, postState.handCount[currentPlayer]);



				//confirm total card count - 1
				preCardTotal = preState.deckCount[currentPlayer] + preState.handCount[currentPlayer] + preState.discardCount[currentPlayer];
				postCardTotal = postState.deckCount[currentPlayer] + postState.handCount[currentPlayer] + postState.discardCount[currentPlayer];
				if (preCardTotal -1 == postCardTotal)
					printf("PASS: card total for current player is correct\n");
				else {
					printf("FAIL: card total for current player should be %d, but is %d\n", preCardTotal -1 , postCardTotal);
					errorFlag = 1;
				}


				//confirm no change in deck count
				if (preState.deckCount[currentPlayer] == postState.deckCount[currentPlayer]) {
					printf("PASS: deck count did not change for current player\n");
				}
				else printf("FAIL: deck count incorrect, should be %d, but is %d\n", preState.deckCount[currentPlayer], postState.deckCount[currentPlayer]);

			}
		







			else {
				//hand count - 2
				if (preState.handCount[currentPlayer] - 2 == postState.handCount[currentPlayer])
					printf("PASS: Hand count correct for current player\n");
				else printf("FAIL: Hand count incorrect for currrent player. Should be %d, but is %d\n", preState.handCount[currentPlayer] - 2, postState.handCount[currentPlayer]);
				
				
				//total card count + 2
				preCardTotal = preState.deckCount[currentPlayer] + preState.handCount[currentPlayer] + preState.discardCount[currentPlayer];
				postCardTotal = postState.deckCount[currentPlayer] + postState.handCount[currentPlayer] + postState.discardCount[currentPlayer];
				if (preCardTotal + 2 == postCardTotal)
					printf("PASS: card total for current player is correct\n");
				else {
					printf("FAIL: card total for current player should be %d, but is %d\n", preCardTotal + 2, postCardTotal);
					errorFlag = 1;
				}
				
				
				
				//deck count + 4
				if (preState.deckCount[currentPlayer] + 4 == postState.deckCount[currentPlayer]) {
					printf("PASS: deck count increased by 4 for current player\n");
				}
				else printf("FAIL: deck count incorrect, should be %d, but is %d\n", preState.deckCount[currentPlayer] + 4, postState.deckCount[currentPlayer]);


				
			}




			//other players don't change



		}
	}

		return 0;
}





int randomNumCardsToHand() {
	int numCards = rand() % 2 + 1;
	return numCards;
}

int randCardToHand() {
	int index;
	int cardOptions[3] = { 5, 26, 7 }; //33% chance of drawing the treasure map
	index = rand() % 3;

	return cardOptions[index];
}

int alreadyTreasureMapInHand(struct gameState *state, int currentPlayer) {
	int i;
	for (i = 0; i < state->handCount[currentPlayer]; i++) {
		if (state->hand[currentPlayer][i] == 26)
			return 1;
	}
	return 0;
}


int treasureMapPos(struct gameState *state, int currentPlayer) {
	int i;
	for (i = 0; i < state->handCount[currentPlayer]; i++) {
		if (state->hand[currentPlayer][i] == 26)
			return i;
	}
	return -1;
}


int treasureMapCount(struct gameState *state, int currentPlayer) {
	int counter = 0;
	int i;
	for (i = 0; i < state->handCount[currentPlayer]; i++) {
		if (state->hand[currentPlayer][i] == 26)
			counter++;
	}
	return counter;

}
