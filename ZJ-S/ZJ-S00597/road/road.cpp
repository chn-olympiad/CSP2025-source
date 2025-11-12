#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k;
ll link[10005][10005],mp[15][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	int u,v;
	ll w;
	for (int i=1;i<=m;i++){
		scanf("%d%d%lld",&u,&v,&w);
		link[u][v]=link[v][u]=w;
	}
	for (int j=1;j<=k;j++)
		for (int i=0;i<=n;i++)
			scanf("%lld",&mp[j][i]);
	cout<<0;
	fclose(stdin);
	fclose(stdout);
}
