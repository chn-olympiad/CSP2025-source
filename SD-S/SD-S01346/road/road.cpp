#include<bits/stdc++.h>
#define int long long
using namespace std;
void IOS(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
const int N=1e4+5;
int n,m,k;
struct edge{
	int u,v,w;
	bool operator <(const edge &fg) const{
		return fg.w<w;
	}
};
priority_queue<edge> q;
int a[12][N],c[12];
int f[N];
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
signed main(){
	IOS();
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i)f[i]=i;
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		q.push({u,v,w});
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		int h=0;
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
			if(a[i][j]==0)h=j;
		}
		for(int j=1;j<=n;++j)q.push({h,j,a[i][j]});
	}
	int ans=0;
	while(!q.empty()){
		edge g=q.top();
		q.pop();
		int u=min(g.u,g.v),v=max(g.u,g.v);
		int fu=find(u),fv=find(v);
		if(fu==fv)continue;
		f[fu]=fv;
		ans+=g.w;
	}
	cout<<ans<<"\n";
	return 0;
}
