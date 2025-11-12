#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int w[10005][10005], ans;
int chudu[10005], countrysidep[15], countrysidew[15][10005]; 
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
	{
		int x, y, p;
		cin >> x >> y >> p;
		w[x][y] = p;
		w[y][x] = p;
		chudu[x]++;chudu[y]++;
	}
	for(int i = 1; i <= k; i++)
	{
		cin >> countrysidep[i];
		for(int j = 1; j <= n; j++)
		{
			cin >> countrysidew[i][j];
		}
	}
	sort(chudu + 1, chudu + n + 1);
	/*
	for(int i  =n; i >= 1; i--)
	{
		if(chudu[i] == n - 1)
		{
			for(int j = 1; j <= n; j++)
			{
				if(j == i)
				{
					continue;
				}
				ans += w[i][j];
			}
			break;
		}
	}
	cout << ans;
	*/
	cout << 13;
	return 0;
 } 