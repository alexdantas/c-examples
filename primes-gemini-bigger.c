/* Will print the biggest gemini number representable with 32 bits.
 *
 * WARNING: Heavy calculations ensue.
 *
 * Will start from INT_MAX and go until zero.
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/** Tells if #num is prime. */
bool is_prime(long num)
{
    if (num < 2)
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

/* Calculates n-esim gemini prime.
 *
 * Basically:
 *
 * While gemini != count
 *    Find prime
 *    Is (prime+2) also prime?
 *       If yes, gemini count++
 */
long gemini(long n)
{
	long gemini_count   = 1; // starts with 1 because will not consider
	long current_gemini = 1; // 0 as a prime
	long number         = current_gemini;

	while (gemini_count <= n)
	{
		while(!is_prime(number))
			number++;

		if (is_prime(number+2))
        {
			gemini_count++;
            current_gemini = number;
		}
        number++;
	}
	return current_gemini;
}

int bigger(long big)
{
    while (1)
    {
        if (is_prime(big) && is_prime(big-2))
        {
            printf("P[i + 2] = %li\n"
                   "P[i]     = %li\n", big, big-2);
            return 1;
        }
        big--;
    }
    return 0;
}

/* Print #amm primes, starting from zero */
void print_all(amm)
{
    int i;
    for (i = 0; i < amm; i++)
        if (is_prime(i) == true)
            printf("%d\n", i);
}

int main(int argc, char* argv[])
{
    /* Biggest number representable with 32 bits */
    long big    = 4294967295;

    int  bigger = 0;
    bigger--;

//    bigger(big);
//    print_all(100);

    long max_gemini = big - 1456;

    int i = 0;
    long value = gemini(i);
    while (value < max_gemini)
    {
        printf("i = %d... Nao! (%li)\n", i, value);
        i++;
        value = gemini(i);
    }


    printf("i = %d... Sim! (gemini(i) = %li)\n", i, gemini(i));

    return 0;
}

