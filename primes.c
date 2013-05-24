/* primes - Print and count prime numbers untill and between a
 *          specified range. Also tells if some number is a prime.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> /* bool type! */

/* The maximum range this program works */
#define MAX_VALUE 500000
#define MIN_VALUE 1

/* The different functions of the program:
 * - print all primes until
 * - print if number is prime
 * - print primes between
 */
typedef enum { UNTILL, SINGLE, BETWEEN } states;

/* Future implementation */
typedef enum { COUNT, PRINT } modes;

void print_usage()
{
    printf("primes v1.0\n");
    printf("Usage:\n");
    printf("\t primes [-n] number             (1st form)\n");
    printf("\t primes -b number1 number2      (2nd form)\n\n");
    printf("1st form: Tell all the prime numbers from 1 to 'number'.\n");
    printf("          If '-n' is specified, tells if 'number' is prime.\n");
    printf("2nd form: Tell all the prime numbers between 'number1' ");
    printf("and 'number2'.\n");
    printf("Note: The maximum value allowed is %d.\n", MAX_VALUE);
}

/** Tells if #num is prime. */
bool is_prime(long num)
{
    if (num < 0)
        return false;

    if (num == 1)
        return false;

    if (num == 2)
        return true;

    if ((num % 2) == 0)
        return false;

    int x   = 3;
    int lim = sqrt(num);

    while(x <= lim)
    {
        if ((num % x) == 0)
            return false;

        x += 2;
    }

    return true;
}

int main (int argc, char* argv[])
{
    states state = UNTILL;
    modes  mode  = PRINT;
    int    num1  = 0;
    int    num2  = 0;
    int    i     = 0;

    if (argc < 2)
    {
        print_usage();
        return EXIT_FAILURE;
    }

    /* handle command-line arguments */
    /* if we're dealing with one number only */
    state = UNTILL;
    /*state = SINGLE;*/
    num1 = atoi(argv[1]);
    if ((num1 < MIN_VALUE) || (num1 > MAX_VALUE))
    {
        printf("Error: Number out of range.\n");
        printf("       Please specify a number between %d and %d\n", MIN_VALUE, MAX_VALUE);
        return EXIT_FAILURE;
    }

    switch (state)
    {
        case UNTILL:
            for (i = 1; i <= num1; i++)
                if (is_prime(i))
                    printf("%d ", i);

            printf("\n");
            break;
        case SINGLE:
            if (is_prime(num1))
                printf("yes\n");
            else
                printf("no\n");
            break;
        case BETWEEN:
            for (i = num1; i <= num2; i++)
                if (is_prime(i))
                    printf("%d ", i);

            printf("\n");
            break;
        default:
            printf("Error: Mode not specified!\n");
            return EXIT_FAILURE;
            break;
    }

    return EXIT_SUCCESS;
}

