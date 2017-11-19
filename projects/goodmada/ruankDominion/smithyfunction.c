

int smithyFunc(int currentPlayer, int handPos, struct gameState *state) {
	int i;
	//+3 Cards
	for (i = 0; i < 4; i++)
	{
		drawCard(currentPlayer, state);
	}

	//discard card from hand
	discardCard(handPos, currentPlayer, state, 1);

	return 0;
}