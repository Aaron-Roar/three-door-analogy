#define SIZE 100

typedef struct Threes {
    uint8_t results[SIZE];
    uint8_t doors[SIZE][3];
} Threes;

typedef enum Mode {NOSWAP, SWAP} Mode;
