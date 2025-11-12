#include<bits/stdc++.h>

using namespace std;
#define int long long
struct str{
	int a,b,c,d,e;
}gh[10005];
int n,m,k,g,ans,u[1000005],v[1000005],w[1000005];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=n+1;i++)cin>>gh[i].a>>gh[i].b>>gh[i].c>>gh[i].d>>gh[i].e;
	for(int i=1;i<=n;i++){
		g=min(u[i],v[i]);
		ans+=min(g,w[i]);
	}
	for(int i=1;i<=n+1;i++){
		g=min(gh[i].a,gh[i].b);
		g=min(g,gh[i].c);
		g=min(g,gh[i].d);
		ans+=min(g,gh[i].e);
	}
	cout<<gh;
	return 0;
}
