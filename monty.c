#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int game(int door_count, int switch_door){
    int guess, winner; // initial guess, winning door
    guess = rand() % door_count;
    winner = rand() % door_count;

    // in the simulation, Monty reveals all of the doors but two.
    // If you chose the correct door initially,
    // then guess == winner, and you lose by switching
    // and win by not switching.
    //
    // Stating the problem this way should make the result
    // of the simulation unsurprising

    if (switch_door == 1){
        if (winner == guess) return 0;
        return 1;
    }
    else{
        if (winner == guess) return 1;
        return 0;
    }
}

int main(){
    srand(time(NULL)); // seeding rand
    int door_count = 4; // number of doors
    int trials = 1000;
    int wins = 0;
    for (int i = 0; i < trials; i++){
        int result = game(door_count, 1);
        printf("result:%i\n", result);
        if (result == 1){
            wins++;
        }
    }
    float rate = (float) wins/ (float) trials;
    printf("By switching doors with %i total doors and %i trials,\n", door_count, trials);
    printf("your win rate was %f\n", rate);
}
