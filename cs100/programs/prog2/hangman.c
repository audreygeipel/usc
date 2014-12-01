// Author : Oguz Bilgic
// Date	  : 21-September-2010
// File   : hangman.c
// Project: CS 100 - Programing Assignment #2 - Game Time
// Desc	  : Hangman game with C
// Repo   : https://gist.github.com/6c57635453f073d2c0a6
// Version: 

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int i, lives = 10, is_complated = 0;
char *word, given_char, given_chars[30] = {};
char word_list[20][25] = {"computer", "engineer", "windows", "apple", "ubuntu", 
						  "usc", "keyboard", "software", "homework", "web", 
						  "internet", "design", "function", "class", "pointer", 
						  "poker", "blackboard", "mail", "decomposition", "mouse"}; 

// Selects 1 random word from the word_list
void select_word(){
	srand(time(NULL));
	word = word_list[rand() % 20];
}

// Prints selected word with dashes
// If some letters of the word are given by the player , it prints the letter insted of dash
// If all the letters in the word are given by the player , it sets is_complated variable as true
void print_word(){
	is_complated = 1;
	
	printf("%-15s", "Word:");
	for(i = 0; i < 25; i++){
		if(strchr(given_chars, word[i])){
			printf("%c  ", (char) word[i]);
		} else {
			printf("__  ");
			is_complated = 0;
		}
	}
}

// Prints the number of lives player has
void print_lives(){
	printf("\nYou have %d lives left.\n", lives);
}

// Requests a character from the user
// Adds given character to given_character array
void request_player_guess(){
	printf("Guess a character (to exit press ctrl+c): ");
	given_char = getchar();
	while (getchar() != '\n');
	for(i = 0; (i < 30) && (given_chars[i-1] != given_char); i++)
		given_chars[i] = given_chars[i] == '\0'? given_char : given_chars[i] ;
}

// Prints the result of this turn 
// If the given character is in the word, Player wins this turn
// If the given character is not in the word, Player loses this turn
void print_turn_result(){
	if(strchr(word, given_char)){
		printf("The character you gave is in the word! :)\n");
	} else {
		lives--;
		printf("Opssss word does not include this character :( \n");
	}
	printf( "###################################################################\n");
}

// Plays 1 turn
// Print the word 
// Prints number of lives player has
// Request character from player
// Prints result of this turn
void play_turn(){
	print_word();
	if (is_complated) return ;
	print_lives();
	request_player_guess();
	print_turn_result();
}

// Prints result of the game
void print_game_result(){
	if(is_complated){
		printf("\n__   __         __      __          _ \n");
		printf("\\ \\ / /__ _  _  \\ \\    / /__ _ _   | |\n");
		printf(" \\ V / _ \\ || |  \\ \\/\\/ / _ \\ ' \\  |_|\n");
		printf("  |_|\\___/\\_,_|   \\_/\\_/\\___/_||_| (_)\n");
	} else {
		printf("\n:( Sorry You lost.\n");
	}
}

// Plays hangman game
// Selects random word from the list
// Until word is complated or user has 0 lives , plays turn
// Prints result of the game
void play_hangman(){
	select_word();
	while(!is_complated && lives > 0){
		play_turn();
	}
	print_game_result();
}

// Show menu
// Asks for instructions
// Asks for game start
void show_menu(){
	char show_ins, start_play;

	printf( "\n###################################################################\n");	
	printf( " _                                              ____________ _____ \n");
	printf( "| |                                             | ___ \\ ___ \\  _  |\n");
	printf( "| |__   __ _ _ __   __ _ _ __ ___   __ _ _ __   | |_/ / |_/ / | | |\n");
	printf( "| '_ \\ / _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\  |  __/|    /| | | |\n");
	printf( "| | | | (_| | | | | (_| | | | | | | (_| | | | | | |   | |\\ \\\\ \\_/ /\n");
	printf( "|_| |_|\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_| \\_|   \\_| \\_|\\___/ \n");
	printf( "                   |___/\n");
	printf( "by Oguz Bilgic\n");
	printf( "####################################################################\n");
	
	
	printf("Do you want to see game instructions? (y/n): ");
	scanf("%c", &show_ins);
	while (getchar() != '\n');
	if (show_ins == 'y'){
		printf("\nHangman is a word guessing game.\nPlayer suggests a letter which occurs in the word, the program writes it in all its correct positions.\nIf the suggested letter does not occur in the word, player loses 1 life.\nThe game is over, if player guesses the word or loses all lives.\n");
		printf("You can close the program anytime by pressing ctrl+c\n");
	}
	printf( "####################################################################\n");
	
	
	printf("Do you want to play hangman PRO? (y/n): ");
	scanf("%c", &start_play);
	printf( "####################################################################\n");
	while (getchar() != '\n');
	if (start_play == 'y'){
		play_hangman();
	}
}

int main(){
	show_menu();
	
	return 0;
}
