#include <stdio.h>
#include <stdlib.h>

double precision = 0.000000000000001;

int max_iterations = 200;


double get_square_root(double n) {
    // returns 1 which stands for error when n is negative
    // we cant use negative numbers because we use the low 0 and negative numbers would be below that value
    if (n < 0) {
        printf("\nNegative numbers are not allowed");
        return 1;
    }

    // Defines high guess as n + 1, low as 0 and the guess as high plus low divided by 2
    // Optimally we would use the next lowest and highest square root
    // because that would be saving us 2 iterations but in reality it doesn't matter
    double high = n + 1;
    double low = 0;
    double guess = (((high + low) / 2.0));

    int iteration = 0;

    // This is a while loop which stops running when high - low is less than the defined precision,
    // or the max_iterations is reached
    while ((high - low) > precision) {
        // Prints the high, low, guess and iteration of this iteration
        printf("\nhigh: {%.15f} | low: {%.15f} | guess: {%.15f} | iteration: {%d}", high, low, guess, iteration);
        
        // Advanced:
        // If the high plus low divided by 2 to the power of 2 is greater than n the high becomes the current guess
        // If the high plus low divided by 2 to the power of 2 is less than n the low becomes the current guess
        // The guess then becomes the new high plus low divided by 2
        //
        // Basic:
        // If the guess is to great the high becomes the current guess
        // If the guess is to low the low becomes the current guess
        // The guess then becomes the middle of the high and low
        if (((high + low) / 2.0) * ((high + low) / 2.0) > n)
            high = guess;
        else if (((high + low) / 2.0) * ((high + low) / 2.0) < n)
            low = guess;
        guess = (((high + low) / 2.0));

        // Used to increase the number of iterations and break the loop if the number of iterations reaches the max_iterations
        // It is max_iterations - 1 because computers start counting at 0
        if (iteration >= (max_iterations - 1)) {
            break;
        }
        else {
            iteration++;
        }
    }

    // After the loop is finished this returns the last guess as the square root of the number of iterations
    return guess;
}

long main (long n) {
    // Gets the user input
    printf("\nEnter the number you wanna get the square root of: ");
    scanf("%d", &n);

    double square_root = get_square_root(n);

    // Prints the square root
    printf("\n\n{%.15f} is the square root of the number{%d}\n", square_root, n);
    return 0;
}