#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;

struct node
{
	int u, v, w;
};
int b[100010][6];
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	node a[m+1];
	for(int i = 1; i <= m; i++)
	{
		cin >> a[i].u>> a[i].v >> a[i].w;
	} 
	for(int i = 1; i <= k; i++)
	{
		for(int j = 1; j <= 5; j++)
		{
			cin >> a[i][j];
		}
	}
	
	
	return 0;
}
