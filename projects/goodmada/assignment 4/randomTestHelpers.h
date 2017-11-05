#ifndef _RANDOMTESTHELPERS_H
#define _RANDOMTESTHELPERS_H

#include <stdio.h>
#include "dominion.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int randomNumPlayers(int iteration);
void randomKingdomCards(int *kingdomCards, int iteration);
int arrayContains(int testNum, int testArray[10]);
int randomCurrentPlayer(int numPlayers);


#endif