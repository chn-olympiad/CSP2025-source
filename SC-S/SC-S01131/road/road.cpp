#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+100;
const int M=2e6;
int n,m,k,cntn,tot,cntm,fa[N],sz[N];
int x,y;
struct node{
	ll val;
	int u,v;
} G[M],edge[M];
ll ans,sum,v[20],a[20][N];
bool vis[20];
int find(int p){
	if(fa[p]==p){
		return p;
	}
	return fa[p]=find(fa[p]);
}
bool cmp(node x,node y){
	return x.val<y.val;
}
void solve(){
	tot=0;
	for(int i=1;i<=cntm;i++){
		if(tot==cntn-1){
			break;
		}
		x=find(G[i].u);y=find(G[i].v);
		if(x==y){
			continue;
		}tot++;sum+=G[i].val;
		if(sum>=ans){
			return ;
		}
		if(sz[x]<sz[y]){
			swap(x,y);
		}
		fa[y]=x;sz[x]+=sz[y];
	}
	ans=min(ans,sum);
	return ;
}
void dfs(int step){
	if(step>k){
		sum=0;cntn=n;cntm=m;
		for(int i=1;i<=m;i++){
			G[i].val=edge[i].val;
			G[i].u=edge[i].u;G[i].v=edge[i].v;
		}
		for(int i=1;i<=n+k;i++){
			fa[i]=i;sz[i]=1;
		}
		for(int i=1;i<=k;i++){
			if(vis[i]==1){
				sum+=v[i];cntn++;
				for(int j=1;j<=n;j++){
					cntm++;
					G[cntm].val=a[i][j];
					G[cntm].u=cntn;G[cntm].v=j;
				}
			}
		}
		sort(G+1,G+cntm+1,cmp);
		for(int i=1;i<=cntm;i++){
		}
		solve();
		return ;
	}
	vis[step]=0;dfs(step+1);
	vis[step]=1;dfs(step+1);
	return ;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	ans=2e18;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>edge[i].u>>edge[i].v>>edge[i].val;
	}
	for(int i=1;i<=k;i++){
		cin>>v[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n+k;i++){
		fa[i]=i;sz[i]=1;
	}
	cntn=n;cntm=m;sum=0;
	dfs(1);
	cout<<ans<<'\n';
	return 0;
}
