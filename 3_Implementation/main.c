#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include"hangman.h"

int main() {

	printf("\n\t Be aware you can be hanged!!.");

	printf("\n\n\t Rules : ");
	printf("\n\t - Maximum 6 mistakes are allowed.");
	printf("\n\t - All alphabet are in lower case.");
	printf("\n\t - All words are name of very popular Websites. eg. Google");
	printf("\n\t - If you enjoy continue, otherwise close it.");

	printf("\n\t Syntax : Alphabet");
	printf("\n\t Example : a \n\n");

	char values[WORDS][WORDLEN] = {"N~mqOlJ^tZletXodeYgs","gCnDIfFQe^CdP^^B{hZpeLA^hv","7urtrtwQv{dt`>^}FaR]i]XUug^GI",
									"aSwfXsxOsWAlXScVQmjAWJG","cruD=idduvUdr=gmcauCmg]","BQt`zncypFVjvIaTl]u=_?Aa}F",
									"iLvkKdT`yu~mWj[^gcO|","jSiLyzJ=vPmnv^`N]^>ViAC^z_","xo|RqqhO|nNstjmzfiuoiFfhwtdh~",
									"OHkttvxdp|[nnW]Drgaomdq"};
	char *body = malloc(CHANCE+1);

	int id = i_rnd(WORDS);
	char *word = decrypt(values[id]);
	int len = strlen(word);
	char *guessed = malloc(len);
	char falseWord[CHANCE];

	memset(body, ' ', CHANCE+1);
	memset(guessed, '_', len);
	char guess;
	bool found;
	char* win;

	int mistakes = 0;
	setvbuf(stdin, NULL, _IONBF, 0);

	do {

		found = false;
		printf("\n\n");
		printBody(mistakes, body);
		printf("\n\n");
		printf("\tFalse Letters : ");
		if(mistakes == 0) printf("None\n");
		for (int i = 0; i < mistakes; ++i)
		{
			printf("%c", falseWord[i]);
		}
		printf("\n\n");
		printWord(guessed, len);
		printf("\tGive me a alphabet in lower case : ");
		do {scanf("%c",&guess);} while ( getchar() != '\n' );
		for (int i = 0; i < len; ++i)
		{
			if(word[i] == guess) {
				found = true;
				guessed[i] = guess;
			}
		}
		if(!found) {
			falseWord[mistakes] = guess;
			mistakes += 1;
		}
		win = strchr(guessed, '_');
	}while(mistakes < CHANCE && win != NULL);

	if(win == NULL) {
		printf("\n");
		printWord(guessed, len);
		printf("\n\tCongrats! You have won : %s\n\n", word);
	} else {
		printf("\n");
		printBody(mistakes, body);
		printf("\n\n\tBetter try next time. Word was %s\n\n", word);
	}

	free(body);
	free(word);
	free(guessed);
	return EXIT_SUCCESS;
}
