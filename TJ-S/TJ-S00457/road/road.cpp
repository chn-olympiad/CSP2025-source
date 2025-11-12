#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
using namespace std;
int n,m,k; 
const int p = 10000001;
int u[p],w[p],v[p];
int c;
int a[p];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++)
	{
		cin >> u[i] >> v[i] >> w[i];
		for(int j = 1;j <= n+1;j++)
		{
			cin >> c >> a[i];
		}
	} 
	return 0;
}
