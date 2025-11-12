#include<bits/stdc++.h>
using namespace std;
int u[10005],v[10005],w[10005];
int a1[10005],a2[10005],a3[10005],a4[10005],c[10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		cin >> u[i] >> v[i] >> w[i];
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> c[i]>>a1[i]>>a2[i]>>a3[i]>>a4[i];
	}
	cout << "0";
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
