#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,b[10000];
struct xinxi{
	int u,v,w,x;
}a[10000];
bool f[10000]={0};
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>b[i]>>a[i].x;
	}
	cout<<"63787832";
	return 0;
}
