#include <cstdio>
#include <cstdlib>
#include <iostream>

#define inf 1000000

using namespace std;

int n; // kapasitas
int m; // banyak benda
pair<int, int> data[100];

int memo[100000][100];

int knapsack(int x, int y)
{
	int& p = memo[x][y];
	if(p == -1)
	{
		if(y == m) p = 0;
		else
		{
			p = knapsack(x, y+1);
			if(x-data[y].first >= 0)
				p = max(p, knapsack(x-data[y].first, y+1)+data[y].second);
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
		scanf("%d %d", &data[i].first, &data[i].second); 
	}

	// init memo
	memset(memo, -1, sizeof(memo));

	// dp!
	printf("%d\n", knapsack(n, 0));
}