#include "randomTestHelpers.h"



/*
int main() {

	struct gameState state;
	int numPlayers;
	int kingdomCards[10];// = { 7, 8, 9, 25, 11, 12, 13, 14, 15, 16 };
	int randomSeed = rand();
	int currentPlayer = 0;
	int iteration;
	int i;
	int initializeGameSuccess;

	for (iteration = 0; iteration < 1000; iteration++) {
		numPlayers = randomNumPlayers(iteration);
//		printf("iteration %d: num players %d\n", iteration, numPlayers);
		randomKingdomCards(&kingdomCards, iteration);
		
		randomSeed = rand();
		currentPlayer = randomCurrentPlayer(numPlayers);
//		printf("current player: %d\n", currentPlayer);
		initializeGameSuccess = initializeGame(numPlayers, &kingdomCards, randomSeed, &state);
		if (initializeGameSuccess != -1) {
			adventurerfunction(currentPlayer, &state);
			//printf("iteration %d\n", iteration);
		}
		else {
			printf("iteration %d\n", iteration);
			for (i = 0; i < 10; i++) {
				printf("kingdom card %d: %d\n", i, kingdomCards[i]);
			}
		}
	}


	return 0;
}

*/
int randomNumPlayers(int iteration) {
	int numPlayers;

//	if (iteration % 100 != 0) {
		numPlayers = rand() % 3 + 2; // 2 to 4 players
//	}
//	else numPlayers = rand() % 5 + 1; //1 to 5 players

	return numPlayers;
}



void randomKingdomCards(int *kingdomCards, int iteration) {
	int kingdomCardVals[20] = { 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26 };
	int tempVal;
	int i;
	//randomize kingdomcards - valid values are 7 - 26, no repeats, 10
//	if (iteration % 150 != 0) { //unless 150th iteration, kingdom cards can't be duplicates, in accordance with rules of the game
		for (i = 0; i < 10; i++) {
			do {
				tempVal = rand() % 20;
			} while (arrayContains(kingdomCardVals[tempVal], kingdomCards));

			kingdomCards[i] = kingdomCardVals[tempVal];
		}
	}
//	else { //every 150th iteration, possibility of duplicate kingdom cards
//		for (i = 0; i < 10; i++) {
//			tempVal = rand() % 20;
//			kingdomCards[i] = kingdomCardVals[tempVal];
//		}
//	}





int arrayContains(int testNum, int testArray[10]) {
	int i;
	for (i = 0; i < 10; i++) {
		if (testArray[i] == testNum)
			return 1;
	}
	return 0;
}



int randomCurrentPlayer(int numPlayers) {
	return rand() % numPlayers;
}