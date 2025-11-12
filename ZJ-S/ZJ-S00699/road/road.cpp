#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int maxn=1e6+10;
const ll INF=1e16;
int n,m,k;
struct node{
	int u,v;
	ll w;
}g[maxn];
int cnt;
const int maxm=11;
int c[maxm];
int a[maxm][maxn];
bool cmp(node a,node b){
	return a.w<b.w;
}
int f[maxn];
int find(int x){
	if(f[x]==x) return f[x];
	return f[x]=find(f[x]); 
} 
ll zx(int n,int cnt,node g[]){
	sort(g+1,g+cnt+1,cmp);
	ll ans=0;
	for(int i=1; i<=n; i++)
		f[i]=i;
	for(int i=1; i<=n-1; i++){
		while(1){
			int u=g[i].u;
			int v=g[i].v;
			int x=find(u),y=find(v);
			if(x!=y){
				f[x]=y;
				ans+=g[i].w;
				break;
			}
			i++;
		}
	}
	return ans;
}
ll ans=INF;
void dfs(int o,int cnt,node g[],ll s,int t){
	if(o>k) return;
	ans=min(ans,zx(n+t,cnt,g)+s);
	dfs(o+1,cnt,g,s,t);
	for(int i=1; i<=n; i++)
		g[++cnt]={n+o,i,a[o][i]};
	ans=min(ans,zx(n+t+1,cnt,g)+c[o]+s);
	dfs(o+1,cnt,g,s+c[o],t+1);
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++){
		int u,v;
		ll w;
		cin>>u>>v>>w;
		g[++cnt]={u,v,w};
	}
	bool flaga=1;
	for(int i=1; i<=k; i++){
		cin>>c[i];
		if(c[i]!=0) flaga=0;
		for(int j=1; j<=n; j++){
			cin>>a[i][j];
			if(a[i][j]!=0) flaga=0;
		}
	}
	if(k==0){
		cout<<zx(n,m,g);
		return 0;
	}
	else if(flaga){
		cout<<1;
		for(int i=1; i<=k; i++)
			for(int j=1; j<=n; j++)
				g[++cnt]={n+i,j,0};
		cout<<zx(n+k,cnt,g);
		return 0;
	}
	else{
		dfs(1,cnt,g,0,0);
		cout<<ans;
	}
	return 0;
}

