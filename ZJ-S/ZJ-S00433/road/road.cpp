#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u[1000010],v[1000010],w[1000010],a[1000010],c[10010];
int main()
{
	freopen("road","r",stdin);
	freopen("road","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>u[i]>>v[i]>>w[i];
	int s=0;
	for(int i=1;i<=k;i++)
		cin>>c[i];
		for(int i=1;i<=n;i++) cin>>a[++s];
	return 0;
}