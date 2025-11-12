#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int,int>
#define ull unsigned long long
const ll inf=1e18;
const int N=1e4+10;
const int M=1e6+10;
int fa[N];
int find(int x){
	if(fa[x]==x)return fa[x];
	return fa[x]=find(fa[x]);
}
bool merge(int u,int v){
	u=find(u),v=find(v);
	if(u!=v){
		fa[u]=v;return true;
	}
	return false;
}
void init(int l,int r){
	for(int i=l;i<=r;i++)fa[i]=i;
}
struct node{
	int u,v,w;
}e[M];
int a[20][N],c[N];
bool cmp(node a,node b){
	return a.w<b.w;
}
vector<node>Nd;
ll Kluskal1(int tot){
	ll ans=0;
	sort(e+1,e+1+tot,cmp);
	for(int i=1;i<=tot;i++){
		if(merge(e[i].u,e[i].v)){
			ans+=(ll)e[i].w;
			Nd.push_back(e[i]);
		}
	}
	return ans;
}
node E[M];
ll Kluskal2(int tot){
	ll ans=0;
	for(int i=1;i<=tot;i++)E[i]=e[i];
	sort(E+1,E+1+tot,cmp);
	for(int i=1;i<=tot;i++){
		if(merge(E[i].u,E[i].v)){
			ans+=(ll)E[i].w;
		}
	}
	return ans;
}
ll ans=inf;
int k,m,n;
void dfs(int pl,ll C){
	if(pl==k+1){
		init(1,n+k);
		ans=min(ans,Kluskal2(m)+C);
		return;
	}
	//choose
	for(int i=1;i<=n;i++){
		e[++m]={i,n+pl,a[pl][i]};
	}
	dfs(pl+1,C+c[pl]);
	m-=n;
	dfs(pl+1,C);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	init(1,n);
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	ans=Kluskal1(m);
	m=Nd.size();
	for(int i=0;i<m;i++){
		e[i+1]=Nd[i];
	}
	Nd.clear();
	dfs(1,0);
	cout<<ans;
	return 0;
}
/*
我要当太上皇!!!!!
*/