#include "game.c"

int main() {
    srand( time(NULL) );

    Threes game_no_swap = playGame(NOSWAP);
    printf("No Swap Method WinRate: %.2f\n", winRatePercent(game_no_swap.results));

    Threes game_swap = playGame(SWAP);
    printf("Swap Method WinRate: %.2f\n", winRatePercent(game_swap.results));

}
