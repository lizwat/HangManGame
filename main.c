#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

int main() {

	srand(time(NULL));
	
	char Words[][16] = {
		"example",
		"fifteen",
		"compilers",
		"linux",
		"virtual",
		"program",
		"feeling",
		"computer"	
	};
	
	int index = rand() % 8;
	int lives = 5;
	int correctGuesses = 0;
	bool previousGuess = false;
	int wordLength = strlen(Words[index]);
	int letters[10];
	bool quit = false;
	char guessed[16];
	char guessedLetter;
	char wrongLetters[5];
	int count = 0;
	int i;
	char wordChosen[wordLength];
	char lettersInWord[wordLength];
	char ch = 'x';
	for (i = 0; i <10; i++) {
		letters[i] = 0;
	}
	
	
	strcpy(wordChosen, Words[index]);
	strcpy(lettersInWord, wordChosen);
	for(i = 0; i < wordLength; i++){
		lettersInWord[i] = '_';
	}
	printf("%c:", lettersInWord);
	printf("Words:%s index:%d wordLength:%d\n", Words[index], index, wordLength);
	printf("Guess the word:%s\n", lettersInWord);
	while(correctGuesses < wordLength) {
		printf("Enter a letter:");
		fgets(guessed, 16, stdin);
		
		guessedLetter = guessed[0];
		
		if( strncmp(guessed, "quit", 4) ==0) {
			quit = true;
			break;
		}
		else {
			printf(" %c taken as guess \n", guessedLetter);
		}
		
		for(i = 0; i < wordLength; i++) {
			if(guessedLetter == wordChosen[i]){
				if(guessedLetter == lettersInWord[i]){
						previousGuess = true;
					}
				lettersInWord[i] = guessedLetter;
				count +=1;
			}
		}
		
		if(previousGuess) {
			printf("Previously Guessed Correct Letter\n", lettersInWord);
			count = 0;
			previousGuess = false;
			continue;
		}
		
		if(count > 1){
			correctGuesses += count;
			printf("Correct letters guessed: %s \n", lettersInWord);
		}
		else if (count == 1) {
			correctGuesses += count;
			printf("Correct letter guessed: %s \n", lettersInWord);
		}
		else if(count == 0){
			lives -= 1;
			strncat(wrongLetters, &guessedLetter, 1);
			printf("Incorrect letter guessed: %s \n", wrongLetters);
		}
		
		count = 0;
		
		if(lives == 0){
			printf("You Lost :( The word was: %s \n", wordChosen);
			break;
		}
		
	}
	
	if (quit) {
		printf("Game has been exited\n");
	}
	
	if(correctGuesses == wordLength) {
		printf("Congratulations! You won: %s", lettersInWord);
	}
	return 0;

}
