/*
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int read()
{
	register int x=0,t=1;
	register char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') t=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*t;
}
int n,m,k,c[N],d[15][N];
vector<int>g[N],w[N];
inline void add(int ui,int vi,int wi)
{
	g[ui].push_back(vi);
	w[ui].push_back(wi);
	return;
}
struct node
{
	int id,dis;
};
int dis[N];
ll minn=1e18;
bool operator <(const node &a,const node &b)
{
	return a.dis>b.dis;
}
bool vis[N];
priority_queue<node>q;
inline void work(int x)
{
//	cout << x << '\n';
	for(int i = 1;i<=n+k;i++){
		dis[i]=1e18;
		vis[i]=0;
	}
	dis[1]=0;
	q.push({1,dis[1]});
	ll ans=0;
	for(int i = 1;i<=k;i++){
		if(x&(1<<i-1)) ans+=c[i];
	}
	if(ans>=minn) return;
	while(q.size()){
		int u=q.top().id;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		ans+=dis[u];
		if(ans>=minn) return;
		if(u<=n){
			for(int i=0;i<g[u].size();i++){
				int v=g[u][i];
				if(!vis[v]){
					if(dis[v]>w[u][i])
					{
						dis[v]=w[u][i];
						q.push({v,w[u][i]});
					}
				}
			}
			for(int i = 1;i<=k;i++){
				if(x&(1<<i-1))
				if(!vis[n+i]){
					if(dis[n+i]>d[i][u]){
						dis[n+i]=d[i][u];
						q.push({n+i,dis[n+i]});
					}
				}
			}
		}
		else{
			for(int i = 1;i<=n;i++){
				if(!vis[i]){
					if(dis[i]>d[u-n][i]){
						dis[i]=d[u-n][i];
						q.push({i,dis[i]});
					}
				}
			}
		}
	}
	minn=min(minn,ans);
	return;
}	
bool flag=1;
signed main()
{
	freopen("road2.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i = 1;i<=m;i++){
		int ui=read(),vi=read(),wi=read();
		add(ui,vi,wi);
		add(vi,ui,wi);
	}
	for(int i = 1;i<=k;i++){
		c[i]=read();
		if(c[i]!=0){
			flag=0;
		}
		for(int j = 1;j<=n;j++){
			d[i][j]=read();
		}
	}
	if(flag){
		work((1<<k)-1);
		cout << minn << '\n';
	}
	else{
		for(int i = 0;i<(1<<k);i++){
			work(i);
		}
		cout << minn << '\n';
	}
	return 0;
}
/*

*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
int read()
{
	register int x=0,t=1;
	register char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') t=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*t;
}
int n,m,k,c[N],d[15][N];
bool flag=1;
struct node
{
	int u,v,w;
}e[N];
bool cmp(node x,node y)
{
	return x.w<y.w;
}

ll minn=1e18;
int f[N],siz[N];
int find(int x)
{
//	return x;
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
int bin(int x,int y)
{
	if(siz[x]<siz[y]){
		f[x]=y;
		siz[y]+=siz[x];
	}
	else{
		f[y]=x;
		siz[x]+=siz[y];
	}
}
int tot;
inline void work(int x)
{
	ll ans=0;
	for(int i = 1;i<=k;i++){
		if(x&(1<<i-1)) ans+=c[i];
	}
	for(int i = 1;i<=n+k;i++) f[i]=i,siz[i]=i;
	for(int i = 1;i<=tot;i++){
		if(e[i].u>n){
			if((x&(1<<e[i].u-1-n))==0){
				continue;
			}
		}
		int fu=find(e[i].u),fv=find(e[i].v);
		if(fu!=fv){
			f[fu]=fv;
			ans+=e[i].w;
		}
		if(ans>minn) return;
	}
	minn=min(minn,ans);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i = 1;i<=m;i++){
		e[i].u=read(),e[i].v=read(),e[i].w=read();
	}
	tot=m;
	for(int i = 1;i<=k;i++){
		c[i]=read();
		if(c[i]!=0){
			flag=0;
		}
		for(int j = 1;j<=n;j++){
			d[i][j]=read();
			e[++tot].u=i+n,e[tot].v=j,e[tot].w=d[i][j];
		}
	}
	sort(e+1,e+1+tot,cmp);
	if(flag){
		work((1<<k)-1);
		cout << minn << '\n';
		return 0;
	}
	for(int i = 0;i<(1<<k);i++){
		work(i);
	}
	cout << minn << '\n';
	return 0;
}
/*

*/
