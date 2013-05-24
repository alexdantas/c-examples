/* Test to see if realloc() works.
 *
 * It actually is a dynamic malloc()!
 *
 * (21 Aug 2012)
 */
#include <stdio.h>
#include <stdlib.h>

int main ()
{
	char* ptr     = NULL;
	int   i       = 0;
	int   ptrsize = 0;

    // starting with single char
	ptr = malloc(sizeof(char));
	ptr[0] = 'a';
	ptrsize = 1;

    // reallocating each time
	for (i = 0; i < 30; i++)
	{
		ptr = realloc(ptr, (ptrsize + 1) * sizeof(char));
		ptr[ptrsize] = 'a' + i;
		ptrsize++;
	}
	ptr[ptrsize - 1] = '\0';

    // printing it!
/*	printf("*%s*\n", ptr); */
	printf("%s", ptr);

	free(ptr);

	return 0;
}

