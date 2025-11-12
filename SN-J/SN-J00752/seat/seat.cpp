#include<bits/stdc++.h>
using namespace std;

struct scoreAndPosition{
	int score;
	int position;
}score[410], seats[410];

const bool cmp(const scoreAndPosition &A, const scoreAndPosition &B)
{
	return A.score > B.score;
}


int main()
{
	freopen("seat.in", "r+", stdin);
	freopen("seat.out", "w+", stdout);
	
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &score[(i - 1) * n + j].score);
			score[(i - 1) * n + j].position = ((i - 1) * n + j);
		}
	}
	
	sort(score + 1, score + (n * m) + 1, cmp);
	
	/*printf("Debug:\n");
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			printf("%d ", score[(i - 1) * n + j]);
		}
		printf("\n");
	}*/
	
	for (int i = 1; i <= m; i++)
	{
		if (i % 2 == 1)
		{
			for (int j = 1; j <= n; j++)
			{
				if (score[(i - 1) * n + j].position == 1)
					{printf("%d %d", i, j); return 0;}
				seats[(j - 1) * n + i] = score[(i - 1) * n + j];
			}
		}
		else
		{
			for (int j = 1; j <= n; j++)
			{
				if (score[(i - 1) * n + j].position == 1)
					{printf("%d %d", i, (m - j + 1)); return 0;}
				seats[(n - j) * n + (i - 1)] = score[(i - 1) * n + j];
			}
		}
	}
	
	return 0;
}
