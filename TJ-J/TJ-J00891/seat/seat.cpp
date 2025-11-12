#include <bits/stdc++.h>
using namespace std;

struct People
{
	int score;
	int num;
}p[105];

int n, m;

bool Cmp(People a, People b)
{
	return a.score > b.score;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
	{
		cin >> p[i].score;
		p[i].num = i;
	}
	sort(p + 1, p + 1 + n * m, Cmp);
	for(int i = 1; i <= n; i++)
	{
		
		if(i % 2)
		{
			for(int j = 1; j <= m; j++)
			{
				if(p[(i - 1) * m + j].num == 1)
				{
					cout << i << " " << j;
					return 0;
				}
			}
		}
		else
		{
			for(int j = m; j >= 1; j--)
			{
				if(p[i * m - j + 1].num == 1)
				{
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	return 0;
}
