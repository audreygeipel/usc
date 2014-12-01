// Author : Oguz Bilgic
// Date   : 14-September-2010
// Course : CS 100
// Project: Programing Assignment #1 - Going Broke
// Desc   : Simulation of Coin Flipping game 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
// Flips the coin
// Returns 0 or 1 depends on the "probablity of heads" input
// Gets "probablity of heads" as an input
int flip_coin(double pro_of_heads){    
       
        // if random number divided by RAND_MAX is bigger than "probablity of heads" return tail
        // else returns head           
        if (((double) rand() / (double) RAND_MAX) > pro_of_heads){
                return 0;
        } else {
                return 1;
        }
}
 
// Simulates 1 round of game
// Returns resulted number of coins for 3 players
// Gets "probablity of heads" as an input
// Gets "players" array as an input which is the array of number of coins before this round
int play_new_round(int *players, double pro_of_heads){
       
        // array which stores flipped coins for this round
        int coins_on_table[3] = {};
       
        // All players get a coin form their pocket
        players[0] --; players[1] --; players[2] --;
               
        // All players flip their coin and put it on the table
        coins_on_table[0] = flip_coin(pro_of_heads);
        coins_on_table[1] = flip_coin(pro_of_heads);
        coins_on_table[2] = flip_coin(pro_of_heads);
       
        // If all coins on the table are same this is tie game
        // Else if find the distinct coin and give all coins to owner of this coin
        if (coins_on_table[0] + coins_on_table[1] + coins_on_table[2] == 0 ||
                coins_on_table[0] + coins_on_table[1] + coins_on_table[2] == 3){
                players[0] ++; players[1] ++; players[2] ++;
        } else if(coins_on_table[0] == coins_on_table[1]){
                players[2] += 3;
        } else if(coins_on_table[1] == coins_on_table[2]){
                players[0] += 3;
        } else if(coins_on_table[0] == coins_on_table[2]){
                players[1] += 3;
        }
        return 0;
}
 
// Plays 1 complate game
// Returns the number of rounds played in this game
// Gets "number initial coins per player" as an input
// Gets "probablity of heads" as an input
int play_new_game(int num_of_coins, double pro_of_heads){
       
        // We give same number of coins to every player
        int players[3] = {num_of_coins, num_of_coins, num_of_coins};
       
        // This variable stores number of rounds played in this game
        int num_of_round = 0;
       
        // while none of the players has 0 coin , play new round
        while(players[0] != 0 && players[1] != 0 && players[2] != 0){
                play_new_round(players, pro_of_heads);
               
                // this round is played, so increase number of rounds played
                num_of_round ++;
        }
       
        return num_of_round;
}
 
// Simulates requested number of games
// Returns the averahe number of rounds played per game
// Gets "number of games" as an input
// Gets "number initial coins per player" as an input
// Gets "probablity of heads" as an input
double simulate_games(int num_of_games, int num_of_coins, double pro_of_heads){
       
        // number of current game
        int current_game;
       
        // average number of played rounds per each game
        // total number of round played in this simulation
        double average, total_average = 0;
       
        // Always be uniqe!
        // This forces rand() function to create unique sequences
        srand(time(NULL));
       
        //
        for(current_game = 1; current_game <= num_of_games; current_game++){
                total_average += play_new_game(num_of_coins, pro_of_heads);
        }
       
        average = (double) total_average / (double) num_of_games;
        return average;
}
 
int main(){
        int num_of_coins, num_of_games;
        double average, pro_of_heads = 0.5;
               
        printf("Initial coins per Player : ");
        scanf("%d", &num_of_coins);
       
        printf("Probability of heads (Fairness) : ");
        scanf("%lf", &pro_of_heads);   
       
        printf("Number of Game Simulations : ");
        scanf("%d", &num_of_games);
       
               
        average = simulate_games(num_of_games, num_of_coins, pro_of_heads);
       
        printf("Average is: %f \n", average);
       
        return 0;
}
