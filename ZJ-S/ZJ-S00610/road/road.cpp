#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
const int M=1e6+10;
struct ROAD{
	int u,v,w;
	bool operator <(const ROAD&b){
		return w<b.w;
	}
}mp[M];
int n,m,k;
int c[15],a[11][N];
int fa[N];
int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++)cin>>mp[i].u>>mp[i].v>>mp[i].w;
	sort(mp+1,mp+1+m);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	long long ans=0ll;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int u=mp[i].u,v=mp[i].v,w=mp[i].w;
		int fu=find(u),fv=find(v);
		if(fu==fv)continue;
		ans+=w;
		fa[fv]=fu;
	}
	cout<<ans;
	return 0;
}