/*
In this code, the `print_layout` function is used to print the 2D layout of characters. 
The `next_minute_layout` function calculates the next layout based on the rules of the game. 
The `main` function initializes the start state, prints it, and then generates 
and prints the layouts until a repeated layout is encountered.
The layouts are stored in the `layouts` array to keep track of encountered layouts. 
The variable `layouts_count` is used to track the number of layouts stored in the array.

*/

#include <stdio.h>
#include <string.h>
#include <math.h>

#define ROWS 5
#define COLS 5

void print_layout(char layout[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", layout[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void next_minute_layout(char layout[ROWS][COLS], char new_layout[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int lifeforms_count = 0;
            int empty_spaces_count = 0;
            
            // Check the four adjacent tiles
            int dx[4] = {0, 0, 1, -1};
            int dy[4] = {1, -1, 0, 0};
            
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                
                // Count the adjacent lifeforms and empty spaces
                if (x >= 0 && x < ROWS && y >= 0 && y < COLS) {
                    if (layout[x][y] == 'X') {
                        lifeforms_count++;
                    }
                    else {
                        empty_spaces_count++;
                    }
                }
            }
            
            // Apply the rules to update the tile
            if (layout[i][j] == 'X') {
                if (lifeforms_count == 1) {
                    new_layout[i][j] = 'X';
                }
                else {
                    new_layout[i][j] = '.';
                }
            }
            else {
                if (lifeforms_count == 1 || lifeforms_count == 2) {
                    new_layout[i][j] = 'X';
                }
                else {
                    new_layout[i][j] = '.';
                }
            }
        }
    }
}

int main() {
    char start_state[ROWS][COLS] = {
        {'X', 'X', 'X', 'X', '.'},
        {'X', '.', '.', '.', '.'},
        {'X', '.', '.', 'X', '.'},
        {'.', 'X', '.', 'X', '.'},
        {'X', 'X', '.', 'X', 'X'}
    };
    
    // Print the start state
    printf("Start state:\n");
    print_layout(start_state);
    
    char layouts[100][ROWS][COLS];  // Keep track of encountered layouts
    int minute = 1;
    int layouts_count = 1;
    memcpy(layouts[0], start_state, sizeof(start_state));
    
     int lifeform_score = 0;
     
    while (1) {
        char next_layout[ROWS][COLS];
        next_minute_layout(layouts[layouts_count - 1], next_layout);
        
        int repeated = 0;
        for (int i = 0; i < layouts_count; i++) {
            if (memcmp(next_layout, layouts[i], sizeof(next_layout)) == 0) {
                repeated = 1;
                printf("%d minute:\n", minute);
                print_layout(next_layout);
                printf("Repeated layout occured after %d minute(s).\n", minute);
                for (int row = 0; row < ROWS; row++) {
                    for (int col = 0; col < COLS; col++) {
                        if (next_layout[row][col] == 'X') {
                            int tile_number = row * COLS + col;
                            int tile_value = pow(2, tile_number);
                            lifeform_score += tile_value;
                        }
                    }
                }
                
                break;
            }
        }
        
        if (repeated) {
            break;
        }
        else {
            memcpy(layouts[layouts_count], next_layout, sizeof(next_layout));
            printf("%d minute:\n", minute);
            print_layout(next_layout);
            minute++;
            layouts_count++;
            }
            
}
    printf("Lifeform score for the first layout that appears twice is: %d\n", lifeform_score);
    
    return 0;
}
