```
/*  This code is a C language program that calculates the
total distance covered by six runners over a period of 1234 seconds.
The program takes in the running speed, running
time, and rest time for each runner, and uses a function to
calculate the total distance each runner covers based on
these values and the constant total time. The program then
outputs the distance covered by each runner to the console. */
#include <stdio.h>
#include <math.h>

// Function to calculate the total distance covered by one runner
float calculateDistance(float running_speed, float run_time, float rest_time, float total_time) {
    // Define variables
    float complete_cycles, remaining_time, distance_per_cycle, total_distance, additional_distance;
    
    // Calculate the number of complete cycles
    complete_cycles = floor(total_time / (run_time + rest_time));
    
    // Calculate the distance covered per cycle
    distance_per_cycle = running_speed * run_time;
    
    // Calculate the total distance covered in the complete cycles
    total_distance = complete_cycles * distance_per_cycle;
    
    // Calculate the remaining time
    remaining_time = total_time - (complete_cycles * (run_time + rest_time));
    
    // If there is remaining time, calculate the additional distance
    if (remaining_time > 0) {
        // Calculate the number of cycles that can be completed during the remaining time
        if (remaining_time > run_time){
            additional_distance = running_speed * run_time;
        }
        if (remaining_time < run_time){
            additional_distance = running_speed * remaining_time;
        }
    
        // Add the additional distance to the total distance
        total_distance += additional_distance;
    }
    
    // Return the total distance
    return total_distance;
}

int main() {
    // Define variables for John
    float John_running_speed = 10.0; // meters per second
    float John_run_time = 6.0; // seconds
    float John_rest_time = 20.0; // seconds
    
    // Define variables for James
    float James_running_speed = 8.0; // meters per second
    float James_run_time = 8.0; // seconds
    float James_rest_time = 25.0; // seconds
    
    // Define variables for Jenna
    float Jenna_running_speed = 12.0; // meters per second
    float Jenna_run_time = 5.0; // seconds
    float Jenna_rest_time = 16.0; // seconds
    
    // Define variables for Josh
    float Josh_running_speed = 7.0; // meters per second
    float Josh_run_time = 7.0; // seconds
    float Josh_rest_time = 23.0; // seconds
    
    // Define variables for Jacob
    float Jacob_running_speed = 9.0; // meters per second
    float Jacob_run_time = 4.0; // seconds
    float Jacob_rest_time = 32.0; // seconds
    
    // Define variables for Jerry
    float Jerry_running_speed = 5.0; // meters per second
    float Jerry_run_time = 9.0; // seconds
    float Jerry_rest_time = 18.0; // seconds
    
    // Define constant for total time
    const float TOTAL_TIME = 1234.0; // seconds
    
    // Calculate the distance for each runner using the function
    float distance_1 = calculateDistance(John_running_speed, John_run_time, John_rest_time, TOTAL_TIME);
    float distance_2 = calculateDistance(James_running_speed, James_run_time, James_rest_time, TOTAL_TIME);
    float distance_3 = calculateDistance(Jenna_running_speed, Jenna_run_time, Jenna_rest_time, TOTAL_TIME);
    float distance_4 = calculateDistance(Josh_running_speed, Josh_run_time, Josh_rest_time, TOTAL_TIME);
    float distance_5 = calculateDistance(Jacob_running_speed, Jacob_run_time, Jacob_rest_time, TOTAL_TIME);
    float distance_6 = calculateDistance(Jerry_running_speed, Jerry_run_time, Jerry_rest_time, TOTAL_TIME);
    
    // Print the distance for each runner
    printf("Distance covered by John: %.2f meters\n", distance_1);
    printf("Distance covered by James: %.2f meters\n", distance_2);
    printf("Distance covered by Jenna: %.2f meters\n", distance_3);
    printf("Distance covered by Josh: %.2f meters\n", distance_4);
    printf("Distance covered by Jacob: %.2f meters\n", distance_5);
    printf("Distance covered by Jerry: %.2f meters\n\n", distance_6);
    
    printf("The distance covered by the winning runner(Jenna) is : %.2f meters\n", distance_3);
    
    return 0;
}
```
This code prints "The distance covered by the winning runner(Jenna) is : 3540.00 meters"
