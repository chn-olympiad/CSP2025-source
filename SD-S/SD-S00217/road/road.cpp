#include<bits/stdc++.h>
using namespace std;
const int N=1e4+9;
const int M=1e6+9;
typedef long long ll;
int n,m,k;
int c[13];
struct edge{
	int u,v;
	int w;
}p[M],t[13][N];
int idx=2;
int cnt[N],fa[N],vis;
ll ans=1e18;
void add(int u,int v,int w){
	p[idx++]={u,v,w};
}
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int fi(int x){
	return fa[x]==x?x:fa[x]=fi(fa[x]);
}
void tree(ll res){
	for(int i=1;i<=n;i++) fa[i]=i;
	int pos=n;
	for(int i=1;i<=n;i++) if(cnt[i]) pos++;
	int x[13],b=0;
	for(int i=0;i<=k;i++) x[i]=0;
	t[0][0].w=INT_MAX;
	for(int h=1;h<pos;h++){
		int id=1;
		for(int i=2;i<=k;i++){
			if(t[i][x[i]].w<t[id][x[id]].w) id=i;
		}
		int u,v,w;
		if(p[b].w<t[id][x[id]].w){
			u=p[b].u,v=p[b].v,w=p[b].w;
			b++;
		}
		else {
			u=t[id][x[id]].u,v=t[id][x[id]].v,w=t[id][x[id]].w;
			x[id]++;
		}
		if(fi(u)==fi(v)) continue;
		res+=w,fa[fi(u)]=fi(v),h++;
		if(res>ans) return ;
	}
	ans=min(ans,res);
}
void init(){
	sort(p,p+idx,cmp);
	for(int i=1;i<=k;i++){
		sort(t[i],t[i]+n,cmp);
	}
	return ;
}
void dfs(int dep,ll res){
	if(res>ans) return ;
	if(dep==k+1){
		tree(res);	
		return ;
	} 
	c[dep]=1,dfs(dep+1,res+c[dep]);
	if(c[dep]) c[dep]=0,dfs(dep+1,res);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		add(u,v,w);
	}
	int K=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		K++;
		for(int j=1,w;j<=n;j++){
			cin>>w;
			t[i][j-1]={n+i,j,w};
		}
	}
	k=K;
	init();
	dfs(1,0);
	cout<<ans;
	return 0;
}
