CFLAGS = -fpic -coverage -lm

default: unittestresults.out

unittestresults.out: UnitTests.c adventurerfunction.c cardtest1.c dominion.c fullDeckCountfunction.c unittest1.c gainCardfunction.c unittest2.c isGameOverfunction.c unittest3.c numHandCardsfunction.c unittest4.c rngs.c sea_hagfunction.c cardtest2.c smithyfunction.c cardtest3.c treasure_mapfunction.c cardtest4.c unittestheader.h
	echo "Unit Test Results:" > unittestresults.out
	
	echo "cardtest1:" >> unittestresults.out
	gcc -o cardtest1 UnitTests.c cardtest1.c adventurerfunction.c dominion.c dominion.h dominion_helpers.h rngs.h rngs.c unittestheader.h $(CFLAGS)
	cardtest1 >> unittestresults.out
	gcov adventurerfunction.c >> unittestresults.out
	
	echo "cardtest2:" >> unittestresults.out
	gcc -o cardtest2 UnitTests.c cardtest2.c sea_hagfunction.c dominion.c dominion.h dominion_helpers.h rngs.h rngs.c unittestheader.h $(CFLAGS)
	cardtest2 >> unittestresults.out
	gcov sea_hagfunction.c >> unittestresults.out
	
	echo "cardtest3:" >> unittestresults.out
	gcc -o cardtest3 UnitTests.c cardtest3.c smithyfunction.c dominion.c dominion.h dominion_helpers.h rngs.h rngs.c unittestheader.h $(CFLAGS)
	cardtest3 >> unittestresults.out
	gcov smithyfunction.c >> unittestresults.out
	echo "cardtest4:" >> unittestresults.out
	
	gcc -o cardtest4 UnitTests.c cardtest4.c treasure_mapfunction.c dominion.c dominion.h dominion_helpers.h rngs.h rngs.c unittestheader.h $(CFLAGS)
	cardtest4 >> unittestresults.out
	gcov treasure_mapfunction.c >> unittestresults.out
	echo "unittest1:" >> unittestresults.out
	
	gcc -o unittest1 UnitTests.c unittest1.c fullDeckCountfunction.c dominion.c dominion.h dominion_helpers.h rngs.h rngs.c unittestheader.h $(CFLAGS)
	unittest1 >> unittestresults.out
	gcov fullDeckCountfunction.c >> unittestresults.out
	echo "unittest2:" >> unittestresults.out
	
	gcc -o unittest2 UnitTests.c unittest2.c gainCardfunction.c dominion.c dominion.h dominion_helpers.h rngs.h rngs.c unittestheader.h $(CFLAGS)
	unittest2 >> unittestresults.out
	gcov gainCardfunction.c >> unittestresults.out
	echo "unittest3:" >> unittestresults.out
	
	gcc -o unittest3 UnitTests.c unittest3.c isGameOverfunction.c dominion.c dominion.h dominion_helpers.h rngs.h rngs.c unittestheader.h $(CFLAGS)
	unittest3 >> unittestresults.out
	gcov isGameOverfunction.c >> unittestresults.out
	echo "unittest4:" >> unittestresults.out
	
	gcc -o unittest4 UnitTests.c unittest4.c numHandCardsfunction.c dominion.c dominion.h dominion_helpers.h rngs.h rngs.c unittestheader.h $(CFLAGS)
	unittest4 >> unittestresults.out
	gcov numHandCardsfunction.c >> unittestresults.out

clean :
	rm -f unittestresults.out

cleanall :
	rm -f unittestresults.out unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 *.gcda *.gcno *.gcov

