#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1.1e6;
const int N=1.1e4;
const int K=12;
int n,m,k,ans=0,cnt=0;
int fa[N],f[N];
bool flag[2*M];
int findr(int x){
	return x==fa[x]?x:fa[x]=findr(fa[x]);
}
struct node{
	int u,v,w;
}e[2*M],E[2*M];
int c[K],a[K][N];
bool cmp(node a,node b){
	return a.w<b.w;
}
void solve(){
	for(int i=1;i<=n+k;++i)fa[i]=i;
	
//	for(int i=1;i<=n+k;++i)cout<<f[i]<<" ";
//	cout<<'\n';
	int s=0;
	for(int i=n+1;i<=n+k;++i)if(f[i])s+=c[i-n];
//	for(int i=1;i<=m;++i){
//		cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<'\n';
//	}
	for(int i=1;i<=cnt;++i){
		if(!f[E[i].u] or !f[E[i].v])continue;
		int fx=findr(E[i].u),fy=findr(E[i].v);
		if(fx==fy)continue;
//		cout<<e[i].u<<" :"<<e[i].v<<" "<<e[i].w<<'\n'; 
		fa[fx]=fy;
		s+=E[i].w;
		
	}
	ans=min(ans,s);
}
void dfs(int step){
	if(step==n+k){
		solve();
		return ;
	}
	f[step+1]=0;
	dfs(step+1);
	f[step+1]=1;
	dfs(step+1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
			e[++m]=(node){n+i,j,a[i][j]};
		}
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n+k;++i)fa[i]=i;
	for(int i=1;i<=n;++i)f[i]=1;
	ans=0;
	for(int i=1;i<=m;++i){
		if(!f[e[i].u] or !f[e[i].v])continue;
		int fx=findr(e[i].u),fy=findr(e[i].v);
		if(fx==fy)continue;
		fa[fx]=fy;
		ans+=e[i].w;
		flag[i]=1; 
	} 
	for(int i=1;i<=m;++i){
		if(!f[e[i].u] or !f[e[i].v]){
			E[++cnt]=e[i];
		}
		else if(flag[i])E[++cnt]=e[i]; 
	}
	dfs(n);
	cout<<ans<<'\n';
}
