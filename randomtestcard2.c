#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#define MAX_TESTS 9999999

int main(){
	struct gameState G;
	int result, rando = 0, player = 1, handCount, deckCount, good = 0, bad = 0, j , i;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy};
	printf("Running salvager card test.\n");
	for(j = 0; j < 4; j++){
		printf("Running round %d\n", j+1);
		for(i = 0; i < 500; i++){

			printf("Run #%d\n", i);
			int numPlayers = rand() % 4;
			int gameSeed = rand() % 5000;
			
			initializeGame(numPlayers, k, gameSeed, &G);
			
			rando = rand() % 10;
			if(rando == 5){
				G.deckCount[player] = 0;
				deckCount = 0;
			}
			else{
				rando = rand() % MAX_DECK;
				G.deckCount[player] = rando;
				deckCount = rando;
			}
			
			rando = rand() % MAX_DECK;
			G.handCount[player] = rand() % MAX_HAND;
			handCount = rando;
			
			G.discardCount[player] = rand() % MAX_DECK;
			
			result = salvagerFunc(player, &G, 1, 1);
			if(result == 0){
				good++;
			}
			else{
				bad++;
			}
		}
	}
	printf("Test Done!\n");
	if(bad > good){
		printf("Testing Failed!\n");
		return 0;
	}
	else{
		printf("Success!\n");
		return 1;
	}
}