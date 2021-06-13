#ifndef HANGMAN_H_
#define HANGMAN_H_

#define WORDS 10
#define WORDLEN 40
#define CHANCE 6


int i_rnd(int);
char* decrypt(char*);
void printBody(int, char*);
void printWord(char*, int);

#endif
