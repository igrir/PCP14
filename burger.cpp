#include <cstdio>
#include <cstdlib>

int n;

double memo[50100][50100];

double burger(int x, int y)
{
	double& p = memo[x][y];
	if(p < 0)
	{
		if(x == 0)
		{
			if(y >= 2) p = 1;
			else p = 0;
		} else if(y == 0)
		{
			if(x >= 2) p = 1;
			else p = 0;
		} else
		{
			p = burger(x-1, y) + burger(x, y-1);
			p /= 2;
		}
	}
	return p;
}

int main()
{
	scanf("%d", &n);

	for(int j=0; j<50100; j++)
		for(int i=0; i<50100; i++)
			memo[j][i] = -1;

	printf("%.4lf\n", burger(n/2, n/2));
}