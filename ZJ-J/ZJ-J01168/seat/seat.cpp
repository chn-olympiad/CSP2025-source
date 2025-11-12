#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int n, m, x, a[10005], A, g[1005][1005];

bool cmp(int u, int v)
{
	return u > v;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	A = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	
	for(int j = 1; j <= m; j++)
	{
		if(j % 2 == 1)
		{
			for(int i = 1; i <= n; i++)
			{
				x++;
				g[i][j] = a[x];
			}
		}
		else
		{
			for(int i = n; i >= 1; i--)
			{
				x++;
				g[i][j] = a[x];
			}
		}
	}
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(g[i][j] == A)
			{
				cout << j << " " << i << "\n";
				return 0;
			}
////			cout << g[i][j] << " ";
		}
//		cout << "\n";
	}
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92

2 2
99 100 97 98

2 2
98 99 100 97
*/
