#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int r, c;
bool map[300][300];
bool visit[300][300][30];
bool goal[300][300];
int sx, sy;

int n;
int perintah[30];
int arah[30];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void dfs(int x, int y, int p)
{
	//printf("%d %d %d\n", x, y, p);
	visit[x][y][p] = true;
	if(p == n)
	{
		goal[x][y] = true;
	} else
	{
		if(perintah[p] == 0)
		{
			int nx = x + dx[arah[p]];
			int ny = y + dy[arah[p]];
			if(nx >= 0 && nx < c && ny >= 0 && ny < r && !map[nx][ny])
			{
				if(!visit[nx][ny][p]) dfs(nx, ny, p);
				if(!visit[nx][ny][p+1]) dfs(nx, ny, p+1);
			}
		} else
		{
			if(!visit[x][y][p+1]) dfs(x, y, p+1);
		}
	}
}

int main()
{
	scanf("%d %d", &r, &c);
	getchar();
	for(int j=0; j<r; j++)
	{
		for(int i=0; i<c; i++)
		{
			char c;
			scanf("%c", &c);
			if(c == '#') map[i][j] = true;
			else map[i][j] = false;
			if(c == 'H')
			{
				sx = i;
				sy = j;
			}
		}
		getchar();
	}

	/*for(int j=0; j<r; j++)
	{
		for(int i=0; i<c; i++)
		{
			printf("%d", map[i][j]);
		}
		printf("\n");
	}*/

	scanf("%d", &n);

	for(int i=0; i<n; i++)
	{
		char p[10];
		scanf("%s\n", p);
		if(strcmp(p, "LURUS") == 0)
		{
			perintah[i] = 0;
		} else if(strcmp(p, "KANAN") == 0)
		{
			perintah[i] = 1;
		} else if(strcmp(p, "KIRI") == 0)
		{
			perintah[i] = 2;
		}
	}

	/*for(int i=0; i<n; i++)
	{
		printf("%d\n", perintah[i]);
	}*/

	// preprocessing arah
	arah[0] = 0;
	for(int i=1; i<n; i++)
	{
		if(perintah[i-1] == 0) // lurus
		{
			arah[i] = arah[i-1];
		} else if(perintah[i-1] == 1) // kanan
		{
			arah[i] = (arah[i-1] + 1) % 4;
		} else if(perintah[i-1] == 2) // kiri
		{
			arah[i] = (arah[i-1] + 3) % 4;
		}
	}

	/*for(int i=0; i<n; i++)
	{
		printf("%d\n", arah[i]);
	}*/

	// dfs!

	memset(visit, 0, sizeof(visit));
	memset(goal, 0, sizeof(goal));

	dfs(sx, sy, 0);

	int cnt = 0;

	for(int j=0; j<r; j++)
	{
		for(int i=0; i<c; i++)
		{
			if(goal[i][j]) cnt++;
		}
	}

	printf("%d\n", cnt);

	for(int j=0; j<r; j++)
	{
		for(int i=0; i<c; i++)
		{
			if(goal[i][j]) printf("%d %d\n", j+1, i+1);
		}
	}
	
	/*for(int j=0; j<r; j++)
	{
		for(int i=0; i<c; i++)
		{
			printf("%d", goal[i][j]);
		}
		printf("\n");
	}*/
}