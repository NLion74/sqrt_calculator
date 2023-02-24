#include <stdio.h>
#include <stdlib.h>

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

    // defines the precision of the square root
    double precision = 0.000000000000001;

    // Defines when the loop should break
    // Is defined so in case something goes wrong it does not go on forever
    int max_iterations = 200;

    // Defines the iteration because it has to be defined before it can be used in the loop below
    int iteration = 0;

    // This is a while loop which stops running when high - low is less than the defined precision,
    // or the max_iterations is reached
    while ((high - low) > precision || iteration >= (max_iterations - 1)) {
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
        if (((high + low) / 2.0) * 2 > n)
            high = guess;
        else if (((high + low) / 2.0) * 2 < n)
            low = guess;
        guess = (((high + low) / 2.0));

        // Increases the iteration counter
        iteration++;
    }

    // After the loop is finished this returns the last guess as the square root of the number of iterations
    return guess;
}

long main (long n) {
    // Gets the user input
    printf ("\nEnter the number you wanna get the square root of: ");
    scanf ("%d", &n);

    // Gets the square root of the input
    double square_root = get_square_root(n);

    // Prints the square root
    printf ("\n\n{%.15f} is the square root of the number{%d}\n", square_root, n);
    return 0;
}
