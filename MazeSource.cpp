#include <stdio.h>
#include <conio.h>  // For _getch() function
#include<stdlib.h>

//A simple 2d maze where you control a character '@' to reach the goal 'G'. It uses ASCII characters to create a simple maze environment.
//This game is not perfect and doesn't include any error checking. If the player tries to go off the map, the game will crash. Please be careful and play within the map.

// Game map dimensions
#define WIDTH 21
#define HEIGHT 10

// Game map
char map[HEIGHT][WIDTH] = {
    "####################",
    "#@                 #",
    "#                  #",
    "#                  #",
    "#                  #",
    "#                  #",
    "#                  #",
    "#                  #",
    "#                 G#",
    "####################"
};

// Player coordinates
int playerX = 1;
int playerY = 1;

void render() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }
}

int main() {
    while (1) {
        // Render the game
        render();

        // Player movement
        char move = _getch(); // Reads a single character from the user
        map[playerY][playerX] = ' '; // Clears the player's old position

        if (move == 'w') { // Move up
            playerY--;
        }
        else if (move == 'a') { // Move left
            playerX--;
        }
        else if (move == 's') { // Move down
            playerY++;
        }
        else if (move == 'd') { // Move right
            playerX++;
        }

        if (map[playerY][playerX] == 'G') {
            printf("You win!\n");
            break;
        }

        map[playerY][playerX] = '@'; // Sets the player's new position

        // Clear the screen
        system("CLS");
    }

    return 0;
}
