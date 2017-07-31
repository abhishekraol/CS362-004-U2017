#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#define MAX_TESTS 100

int main() {

	  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

	  int i, j, n, players, player, handCount, deckCount, seed, address;
	  struct gameState state;
	  struct gameState stat;
	  struct gameState sta;

	  printf("Running Random Adventurer Test\n");

	  for (i = 0; i < MAX_TESTS; i++) {

	   players = rand() % 4;
	   seed = rand();		
	   initializeGame(players, k, seed, &state);	//initialize Gamestate 

	   //Initialize valid state variables
		  state.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
		  state.discardCount[player] = rand() % MAX_DECK;
		  state.handCount[player] = rand() % MAX_HAND;

		  handCount = state.handCount[player];
		  deckCount = state.deckCount[player];

		//---------adventurer
		  //1 in 3 chance of making empty deck for coverage
		  if (seed % 3 == 0) {

			state.deckCount[player] = 0;
		  }
		  cardEffect(adventurer, 1, 1, 1, &state);		//Run adventurer card
	  }
	  
	   for (i = 0; i < MAX_TESTS; i++) {

  		  players = rand() % 4;
		  seed = rand();		//pick random seed
		
		  initializeGame(players, k, seed, &stat);	//initialize Gamestate

		  //Initiate valid state variables
		  stat.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
		  stat.discardCount[player] = rand() % MAX_DECK;
		  stat.handCount[player] = rand() % MAX_HAND;


		  //Copy state variables
		  handCount = stat.handCount[player];
		  deckCount = stat.deckCount[player];

		  //1 in 3 chance of making empty deck for coverage
		  if (seed % 3 == 0) {

			stat.deckCount[player] = 0;
		  }

		  cardEffect(adventurer, 1, 1, 1, &stat);		//Run adventurer card
	  }

	   for (i = 0; i < MAX_TESTS; i++) {

  		  players = rand() % 4;
		  seed = rand();		//pick random seed
		
		  initializeGame(players, k, seed, &sta);	//initialize Gamestate

		  //Initiate valid state variables
		  sta.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
		  sta.discardCount[player] = rand() % MAX_DECK;
		  sta.handCount[player] = rand() % MAX_HAND;
		  //Copy state variables
		  handCount = sta.handCount[player];
		  deckCount = sta.deckCount[player];

		  //1 in 3 chance of making empty deck for coverage
		  if (seed % 3 == 0) {

			sta.deckCount[player] = 0;
		  }
		  cardEffect(adventurer, 1, 1, 1, &sta);		//Run adventurer card

	   }
	  printf("Tests Adventurer Done\n");

	  return 0;
}