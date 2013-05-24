// Proving that adding two big numbers results into an integer
// overflow
//
// (6 May 2011)

#include <stdio.h>

int main(int argc, char* argv[])
{

    int a = 2e10213;
    int b = 2e12;

    printf("c = %d\n", a + b);

    return 0;
}

