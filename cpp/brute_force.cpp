/*

This is a simple realization of brute-force algorithm. 
It is a test case from some interview.
There are some contracts. A function brute_force has no parameter validation. An user must validate all parameters manually.
*/
#include <cstdio>

using namespace std;
#define MAX_PASSWORD 256

// recursion over passord symbols
void broot_force(char* alpha, char* alpha_end, char* password_iter, char* end ,char* password)
{
	if(password_iter < end) // recursion
	{
		// iterate over alphabet
		for(char* alpha_iterator = alpha; alpha_iterator < alpha_end ; alpha_iterator++)
		{
			*password_iter = *alpha_iterator;
			broot_force(alpha, alpha_end, (password_iter + 1), end, password);
		}
	}
	else // stop recurion
	{
		printf("%s\n", password); 
	}
}
int main()
{
	const auto N = 10;
	const auto M = 10;
	char alpha[N+1] = {'a', 'b', 'c', '2', 'w', 'q', 'e', 'r', 't', 'y'};
	char password[M+1]={'\0'};
	char* iterator = &password[0];
	if(M < MAX_PASSWORD-1)
	    broot_force(alpha, &alpha[N], iterator, &password[M],password);

}
