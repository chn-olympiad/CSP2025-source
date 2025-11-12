#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
	int ret=0;char c=getchar();
	while(c>='0'&&c<='9') {ret=ret*10+c-'0';c=getchar();}
	return ret;
}
const int N=2e6+10;
struct Edge{
	int u,v,w;
}edge[N],e[N];
bool mycmp(Edge x,Edge y) {return x.w<y.w;}
int n,m,k;
int c[12],a[12][N];
int fa[N];
int Find(int x){
	if(fa[x]==x) return x;
	return fa[x]=Find(fa[x]);
}
int t[N],tot;
bool vis[N];
ll ans=1e18;
ll work(){
	for(int i=1;i<=n+k;i++) fa[i]=i;
	ll ret=0;m=0;
	for(int i=1;i<=tot;i++) e[++m]=edge[t[i]];
	for(int i=1;i<=k;i++) {
		if(!vis[i]) continue;
		for(int j=1;j<=n;j++) e[++m]={j,n+i,a[i][j]};
	}
	sort(e+1,e+1+m,mycmp);
	for(int i=1;i<=m;i++){
		int fx=Find(e[i].u),fy=Find(e[i].v);
		if(fx!=fy){
			fa[fx]=fy;
			ret+=e[i].w;
		}
	}
	return ret;
}
void dfs(int d,ll sum){
	if(d==k+1){
		ans=min(ans,work()+sum);
		return;
	}
	vis[d]=1;
	dfs(d+1,sum+c[d]);
	vis[d]=0;
	dfs(d+1,sum);
}
void solve1(){
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(edge+1,edge+1+m,mycmp);
	for(int i=1;i<=m;i++){
		int fx=Find(edge[i].u),fy=Find(edge[i].v);
		if(fx!=fy){
			fa[fx]=fy;
			t[++tot]=i;
		} 
	}
	dfs(1,0);
	printf("%lld",ans);
}
void solve2(){
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++) edge[++m]={j,n+i,a[i][j]};
	sort(edge+1,edge+1+m,mycmp);
	ll ans=0;
	for(int i=1;i<=m;i++){
		int fx=Find(edge[i].u),fy=Find(edge[i].v);
		if(fx!=fy){
			fa[fx]=fy;
			ans+=edge[i].w;
		}
	}
	printf("%lld\n",ans);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++)
		edge[i]={read(),read(),read()};
	bool flag=0;
	for(int i=1;i<=k;i++){
		c[i]=read();
		if(c[i]>0) flag=1;
		for(int j=1;j<=n;j++) a[i][j]=read();
	}
	if(flag) solve1();
	else solve2();
	return 0;
}
