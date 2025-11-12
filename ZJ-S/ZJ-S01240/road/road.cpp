#include <iostream>
#include <cstdio>

struct node{
	int u,v,w;
}a[1000005];

int f[15],c[100015],ans = 1e8;

using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i].u >> a[i].v >> a[i].w; 
		ans = min (ans,a[i].w);
	}
	for (long long i = 1; i <= k*(n+1); i++)
	{
		cin >> c[i];
	}
	cout << ans;
}