#include <stdio.h>
#include <stdlib.h>

/* This C program generates all possible permutations of the digits in the integer 1867,
finds the smallest and largest permutation values that are divisible by 7, calculates their average,
and displays all permutation values along with the minimum, maximum, and average values that are divisible by 7.
The program uses a recursive approach to generate all permutations and checks if each permutation is divisible by 7
to update the minimum and maximum values. The average is then calculated using the minimum and maximum values. 
This program can be used as a reference for generating permutations of other integers 
and finding the minimum, maximum, and average values that satisfy certain conditions. */


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int *arr, int start, int end, int *min, int *max) {
    if (start == end) {
        // calculate the permutation value
        int num = 0;
        for (int i = 0; i <= end; i++) {
            num = num * 10 + arr[i];
        }
        printf("%d ", num); // display the permutation value
        // update the minimum and maximum values if the permutation is divisible by 7
        if (num % 7 == 0) {
            if (num < *min) {
                *min = num;
            }
            if (num > *max) {
                *max = num;
            }
        }
        
    } else {
        for (int i = start; i <= end; i++) {
            swap(&arr[start], &arr[i]);
            permute(arr, start+1, end, min, max);
            swap(&arr[start], &arr[i]);
        }
    }
    
}

int main() {
    int arr[] = {1, 8, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int min = 9999, max = 0;
    printf("All permutation values:\n");
    permute(arr, 0, n-1, &min, &max);
    if (min == 9999) {
        printf("\nThere are no permutations of the digits in 1867 that are divisible by 7.\n");
        return 0;
    }
    float avg = (float)(min + max) / 2;
    printf("\nSmallest permutation value divisible by 7: %d\n", min);
    printf("Largest permutation value divisible by 7: %d\n", max);
    printf("Average of smallest and largest permutation values divisible by 7: %.2f\n", avg);
    return 0;
}
