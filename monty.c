#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int game(int door_count, int switch_door, int open_doors){
    int guess, winner; // initial guess, winning door
    guess = rand() % door_count;
    winner = rand() % door_count;

    /* First, assume we're switching doors.
     * Then, if your initial guess was correct, you lose.
     * Else, if you switched to one of the remaining doors,
     * The chances of winning are 1 in however many doors are left.
     * Otherwise, you lose. */
    if (switch_door){
        if (winner == guess) return 0;
        else if (rand() % (door_count - open_doors - 1) == 0) return 1;
        return 0;
    }
    /* If we assume that your initial guess was correct,
     * then not switching means you win, and switching means you lose. */
    else{
        if (winner == guess) return 1;
        return 0;
    }
}

int main(){
    srand(time(NULL)); // seeding rand
    int door_count = 7; // number of doors
    int open_doors = door_count - 4; //number of doors for Monty to open
    int trials = 1000;
    int switch_door = 1;
    int wins = 0;
    for (int i = 0; i < trials; i++){
        int result = game(door_count, switch_door, open_doors);
        /* printf("result:%i\n", result); */
        if (result){
            wins++;
        }
    }
    float rate = (float) wins/ (float) trials;
    printf("There are %i total doors.\n", door_count);
    printf("After your guess, Monty will open %i out of %i remaining doors.\n", open_doors, door_count-1);
    if (switch_door) printf("By switching doors, \n");
    else printf("By not switching doors, \n");
    printf("your win rate was %f in %i trials. \n", rate, trials);
}
