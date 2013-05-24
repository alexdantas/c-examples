
#include <stdio.h>
#include <stdbool.h>

/* Diz se o numero 'num' e primo. */
bool is_prime(int num)
{
	int x = 0;
	for (x = 2; x < num; x++)
		if ((num % x) == 0)
			return false;

	return true;
}

/* Calcula o n-esimo numero primo gemeo.
 *
 * Basicamente e assim:
 *
 * Enquanto gemeo for diferente de contador
 *     Encontrar um primo
 *     (primo+2) eh primo?
 *         Contador de gemeos++
 */
int gemini(int n)
{
	int gemini_count   = 1; // starts with 1 because will not consider
	int current_gemini = 1; // 0 as a prime
	int number         = current_gemini;

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

int main(int argc, char* argv[])
{
//    int i;
//    for (i = 1; i < 50; i++)
//		printf("%do primo gemeo: %d\n", i, gemini(i));

    printf("Me diga qual indice de numeros primos gemeos devo calcular: ");

	int i;
    scanf("%d", &i);
    getchar();

    int gemeo = gemini(i);
	printf("Primos Gemeos(%d)=(%d,%d)\n", i, gemeo, gemeo+2);
	return 0;
}

