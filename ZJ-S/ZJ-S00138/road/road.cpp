#include<bits/stdc++.h>
using namespace std;

//vector <vector<int> > a;
int b[1000005][3];
int c[11];
int d[11][10005];
long long dis[10005][10005];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,k;
	cin >> n >> m >> k;
//	a.resize(n);
	for(int i = 1;i <= m;i++)
	{
		cin >> b[i][0] >> b[i][1] >> b[i][2];
//		a[b[i][0]].push_back(b[i][1]);
//		a[b[i][1]].push_back(b[i][0]);
	}
	for(int i = 1;i <= k;i++)
	{
		cin >> c[i];
		for(int j = 1;j <= n;j++)
		{
			cin >> d[i][j];
		}
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			dis[i][j] = 1e18;
		}
	}
	for(int i = 1;i <= n;i++)
	{
		dis[i][i] = 0;
	}
	for(int i = 1;i <= m;i++)
	{
		dis[b[i][0]][b[i][1]] = b[i][2];
		dis[b[i][1]][b[i][0]] = b[i][2];
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			for(int k = 1;k <= n;k++)
			{
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
			}
		}
	}
	long long ma = 0;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			ma = max(ma,dis[i][j]);
		}
	}
	cout << ma;
	return 0;
}
