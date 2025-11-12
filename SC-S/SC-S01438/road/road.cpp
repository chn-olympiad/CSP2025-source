#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,ide;
int a[20][10010],c[20];
struct edge{
	int u,v,w,id;
	bool friend operator<(edge e1,edge e2){
		return e1.w<e2.w;
	}
}E[2000010];
int fa[10010];
int find(int x){return (fa[x]==x?x:fa[x]=find(fa[x]));}
int kruskar(int id){
	int ans=0;
	for(int i = 1;i<=n+k;i++)fa[i]=i; 
	for(int i = 1;i<=ide;i++){
		if(E[i].id!=0&&(((1<<(E[i].id-1))&id)==0))continue;
		if(find(E[i].u)!=find(E[i].v)){
			ans+=E[i].w;
			fa[find(E[i].u)]=find(E[i].v);
		}
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++)cin>>E[i].u>>E[i].v>>E[i].w; 
	ide=m;
	for(int i = 1;i<=k;i++){
		cin>>c[i];
		for(int j = 1;j<=n;j++)cin>>a[i][j],E[++ide]={i+n,j,a[i][j],i};
	}
	sort(E+1,E+ide+1);
	int ans=1e18;
	for(int i = 0;i<(1<<k);i++){
		int tmp=0;
		for(int j = 1;j<=k;j++)
			if(i&(1<<(j-1)))tmp+=c[j];
		ans=min(ans,kruskar(i)+tmp);
	}
	cout<<ans<<"\n";
}
/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,ans;
struct edge{
	int u,v,w;
	bool friend operator<(edge e1,edge e2){
		return e1.w<e2.w;
	}
}E[1000010];
int head[10010],idk,dfn[10010],siz[10010],iddfn;
struct node{
	int to,next,w;
}e[2000010];
void adde(int u,int v,int w){
	e[++idk]={v,head[u],w};head[u]=idk;
}
void dfs(int u,int fa){
	dfn[u]=++iddfn;siz[u]=1;
	for(int i = head[u];i;i=e[i].next){
		int v=e[i].to;
		if(v==fa)continue;
		dfs(v,u);
		siz[u]+=siz[v]; 
	}
}
int fa[10010];
int find(int x){return (fa[x]==x?x:fa[x]=find(fa[x]));}
void kruskar(){
	sort(E+1,E+m+1);
	for(int i = 1;i<=n;i++)fa[i]=i; 
	for(int i = 1;i<=m;i++){
		if(find(E[i].u)!=find(E[i].v)){
			ans+=E[i].w;
			adde(E[i].u,E[i].v,E[i].w);adde(E[i].v,E[i].u,E[i].w);
			fa[find(E[i].u)]=find(E[i].v);
		}
	}
}
int a[20][10010],c[20];
struct Node{
	int min,tag;
}tr[20][100010];
void pushdown(int id,int u){
	tr[id][u*2].tag+=tr[id][u].tag; 
	tr[id][u*2+1].tag+=tr[id][u].tag; 
	tr[id][u*2].min+=tr[id][u].tag; 
	tr[id][u*2+1].min+=tr[id][u].tag;
	tr[id][u].tag=0;
}
void update(int id,int u,int l,int r,int ql,int qr,int val){
	if(qr<ql)return;
	if(l>=ql&&r<=qr){tr[id][u].min+=val;tr[id][u].tag+=val;return;}
	if(l>qr||r<ql)return;
	int mid=(l+r)/2;
	pushdown(id,u);
	update(id,u*2,l,mid,ql,qr,val);update(id,u*2+1,mid+1,r,ql,qr,val);
	tr[id][u].min=min(tr[id][u*2].min,tr[id][u*2+1].min);
}
int query(int id,int u,int l,int r,int ql,int qr){
	if(qr<ql)return 1e18;
	if(l>=ql&&r<=qr)return tr[id][u].min;
	if(l>qr||r<ql)return 1e18;
	int mid=(l+r)/2;
	pushdown(id,u);
	return min(query(id,u*2,l,mid,ql,qr),query(id,u*2+1,mid+1,r,ql,qr));
}
void rebuild(){
	memset(tr,0x3f,sizeof(tr));
	for(int i = 1;i<=k;i++){
		for(int j = 1;j<=n;j++)
			update(i,1,1,n,dfn[j],dfn[j],a[i][j]);
	}
}
void prize(){
	for(int u = 1;u<=n;u++){
		for(int i = head[u];i;i=e[i].next){
			int v=e[i].to;
			if(dfn[v]<dfn[u])continue;
			int l=dfn[v],r=dfn[v]+siz[v]-1;
			for(int p = 1;p<=k;p++)
				update(p,1,1,n,l,r,min(query(p,1,1,n,1,l-1),query(p,1,1,n,r+1,n))-e[i].w);
		}
	}
}
int solve(int sit){
	
}
signed main(){
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++)cin>>E[i].u>>E[i].v>>E[i].w; 
	kruskar();
	dfs(1,0);
	for(int i = 1;i<=k;i++){
		cin>>c[i];
		for(int j = 1;j<=n;j++)cin>>a[i][j];
	}
	int ans2=0;
	for(int i = 0;i<(1<<k);i++){
		rebuild();
		int tmp=0;
		for(int j = 1;j<=k;j++)
			if(i&(1<<(j-1)))tmp+=c[j];
		ans2=min(solve(i),ans2+tmp);
	}
	cout<<ans+ans2<<"\n";
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
foot note:
2^k can't avoid,so 2^k*n*k*logn
1.get MIT-> ans
2.build MIT tree ok
(2.5).get dfn ok
3.2^k*dfs

10min remian,I can't comp it.
*/