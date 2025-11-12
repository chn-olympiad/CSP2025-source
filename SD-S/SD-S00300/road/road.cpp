#include<bits/stdc++.h>
using namespace std;
int a, b, c, n[10005], m[10000005][4], k[15][10005], l[1000005][4], number = 1;
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.in", "w", stdout);
	cin >> a >> b >> c;
	for(int i = 1; i <= b; i++)
	{
		cin >> m[i][1] >> m[i][2] >> m[i][3];
	}
	for(int i = 1; i <= c; i++)
	{
		for(int j = a; j <= a; j++)
		{
			cin >> k[i][j];
		}
		for(int j = 1; j <= a; j++)
		{
			for(int o = j + 1; o <= a; o++)
			{
				l[number][1] = j;
				l[number][2] = o;
				l[number][3] = k[i][j] + k[i][o];
			}
		}
	}
	
	return 0;
}

