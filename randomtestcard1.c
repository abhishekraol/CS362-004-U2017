//test smithy card
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#define MAX_TESTS 1300

int main() {

	  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

	  int i, j, n, players, player, handCount, deckCount, seed, address;
	  struct gameState state;
	  struct gameState stat;
	  struct gameState sta;

	  printf("Running Random Card 1 Test for Smithy\n");


	  for (i = 0; i < MAX_TESTS; i++) {
		  
		 players = rand() % 4;
		 seed = rand();	
		 initializeGame(players, k, seed, &state);	//initialize Gamestate

		  //Initiate valid state variables
		  state.deckCount[player] = rand() % MAX_DECK; 
		  state.discardCount[player] = rand() % MAX_DECK;
		  state.handCount[player] = rand() % MAX_HAND;

		  //state variables
		  handCount = state.handCount[player];
		  deckCount = state.deckCount[player];
		  //----------------smithy
		  		  	  		  		  printf("%d\n", i);
		  cardEffect(smithy, 1, 1, 1, &state);		//Run smithy card
		  printf("%dB\n", i);
	  }

	   for (i = 0; i < MAX_TESTS; i++) {
			printf("PRE2\n");

			initializeGame(players, k, seed, &stat);	//initialize Gamestate

			printf("POST\n");
		
		  //Initiate valid state variables
		  stat.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
		  stat.discardCount[player] = rand() % MAX_DECK;
		  stat.handCount[player] = rand() % MAX_HAND;


		  //Copy state variables
		  handCount = stat.handCount[player];
		  deckCount = stat.deckCount[player];

   		  printf("%d\n", i);


		  cardEffect(smithy, 1, 1, 1, &stat);		//Run smithy card

		  		  printf("%dB\n", i);
	  }


	   for (i = 0; i < MAX_TESTS; i++) {
			printf("PRE2\n");
			initializeGame(players, k, seed, &sta);	//initialize Gamestate

	  	printf("POST2\n");
		  //Initiate valid state variables
		  sta.deckCount[player] = rand() % MAX_DECK; 
		  sta.discardCount[player] = rand() % MAX_DECK;
		  sta.handCount[player] = rand() % MAX_HAND;
		  //Copy state variables
		  handCount = sta.handCount[player];
		  deckCount = sta.deckCount[player];

		  printf("%d\n", i);

		  cardEffect(smithy, 1, 1, 1, &sta);		//Run smithy card

		 printf("%dB\n", i);

	  }
	  printf("Test Smithy Done\n");

	  return 0;
}