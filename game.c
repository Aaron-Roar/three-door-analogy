#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>

#include "game_types.h"

//Returns remaining door not selected
uint8_t removeADoor(uint8_t doors[3], uint8_t selected_inex) {
    int i = 0;
    while(i < 3) {
        if(doors[i] == 0 && i != selected_inex)
            return 3 - i - selected_inex;
        i += 1;
    }
}

uint8_t playDoorsSwap(uint8_t doors[3]) {
    uint8_t favourite_door = rand()%3; //Always check middle door

    //*Reveals Not Winning Door*

    //The alternative remanining pick
    uint8_t remainingDoor = removeADoor(doors, favourite_door);

    return doors[remainingDoor];
}

uint8_t playDoorsDontSwap(uint8_t doors[3]) {
    int favourite_door = rand()%3; //Always check middle door

    //*Reveals Not Winning Door*
    //*Keeps Same Pick*

    return doors[favourite_door];
}

Threes generateGame() {
    Threes game = {0};

    int i = 0;
    while(i < SIZE) {
        game.doors[i][rand()%3] = 1;
        i += 1;
    }

    return game;
}

Threes playGame(Mode strategy) {
    Threes game = generateGame();

    int i = 0;
    while(i < SIZE) {
        if(strategy == NOSWAP) {
            game.results[i] = playDoorsDontSwap(game.doors[i]);
        }
        else {
            game.results[i] = playDoorsSwap(game.doors[i]);
        }
        i += 1;
    }

    return game;
}


float winRatePercent(uint8_t results[SIZE]) {
    int sum = 0;

    int i = 0;
    while(i < SIZE) {
        sum += results[i];
        i += 1;
    }

    return (float)((float)sum)/((float)SIZE);
}

