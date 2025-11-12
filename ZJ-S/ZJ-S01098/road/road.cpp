#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,K;
struct node{
	int u,v,w,ad;
};
vector<node>al;
int c[15];
int b[15];
int f[10005];
int ans=LONG_LONG_MAX;
int find(int x){
	if(f[x]==x) return f[x];
	return f[x]=find(f[x]);
}
void solve(){
	for(int i=0;i<=n;i++) f[i]=i;
	int sum=0;
	for(int i=0;i<=K;i++) sum+=(b[i]*c[i]);
	for(node i:al){
		int u=i.u;
		int v=i.v;
		int w=i.w;
		int ad=i.ad;
		if(b[ad]==0) continue;
		u=find(u);
		v=find(v);
		if(u==v) continue;
		if(b[ad]){
			sum+=w;
			f[u]=find(v);
		}
	}
	ans=min(ans,sum);
}
void dfs(int x){
	if(x==K+1){
		solve();
		return;
	}
	b[x]=0;
	dfs(x+1);
	b[x]=1;
	dfs(x+1);
	b[x]=0;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>K;
	memset(b,0,sizeof(b));
	b[0]=1;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		al.push_back({u,v,w,0});
	}
	for(int i=1;i<=K;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			al.push_back({0,j,w,i});
		}
	}
	sort(al.begin(),al.end(),[](node a,node b){
		return a.w<b.w;
	});
	dfs(1);
	cout<<ans;
}
