#include <stdio.h>

int main() {
    char navigation[] = "<<<<<<><><><><<<<><><><><><<<<><><><><><>>>><<><><><><><><><><>>>><<<<<><><><><><<<<<><><><><><><<<<><><><><><><><><><><><<<<<<><><<><><>>><<>><<><<>><><<><><><><><><><<<<<<<<<>><<><><<<><><><><<<<<<>>>>>>>>>>><>><><><>><<<><><><><<><><<><><><><><><><<<<><><><>><<>>>>><><><>><<<><><><><><><>><><><><><><><><><><><><><><><><><<<><><><><><><><><><><><><><><><><><>>>><><><><><><><><><>><<<<<<<<<<>>>>><<<<<>>>><<<<>><<><<><><><><><><><><><><<<<<<<><><<><<><<><<><><><><><<>><><>><><><><><<><<<<<>><<<<><><<<><>>><<><>>>>><>>><<><<><><><><<>><><><><><><><><><><><><><><><><<<<><><<<<><<<>>>>>>>>><<><<<>>>>><<<<<<<<<>>>><<><>><><<><<>><<>><<>><";

    int present_floor = 0;  // initialize the present floor to 0
    int i = 0;  // initialize the counter i to 0

    // loop through each character in the navigation string until the end of the string is reached
    while (navigation[i] != '\0')
    {
        if (navigation[i] == '<')  // if the character is '<', increment the present floor by 1
           present_floor++;
        if (navigation[i] == '>')  // if the character is '>', decrement the present floor by 1
            present_floor--;
        i++;  // increment the counter i by 1
    }

    printf("John ended up on floor %d",present_floor);  // print the present floor where John ended up

    return (0);  // return 0 to indicate successful execution
}
