#include <cstdio>
#include <cstdlib>
#include <iostream>

#define inf 1000000

using namespace std;

int n; // duit yang ingin diperoleh
int m; // banyak koin
int c[100]; // nilai koin

int memo[100000];

int coin(int x)
{
	int& p = memo[x];

	if(p == -1) // kalau blom dicari
	{
		if(x == 0) p = 0; // base case
		else
		{
			p = inf;
			for(int i=0; i<m; i++) // maximize!
				if(x-c[i] >= 0)
					p = min(p, coin(x-c[i]) + 1); // recurence
		}
	}

	return p;
}

int main()
{
	// baca input
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++)
	{
		scanf("%d", &c[i]);
	}

	// init memo
	memset(memo, -1, sizeof(memo));

	// dp!
	printf("%d\n", coin(n));
}