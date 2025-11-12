#include <bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,c,a[1001],cnt = 0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++)
	{
		cin >> u >> v >> w;
	}
	for(int i = 1;i <= k;i++)
	{
		cin >> c >> a[n];
	}
	for(int i = 1;i <= m;i++)
	{
		cnt = a[2]+a[3];
		cout << cnt;
	}
	return 0;
}
