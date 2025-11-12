#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 2e6+5;
int read () {
	int f=1,x=0;char ch=getchar();
	while (!isdigit(ch)) {if(ch=='-')f=-1;ch=getchar();}
	while (isdigit(ch)) {x=x*10+ch-48;ch=getchar();}
	return f*x;
}
struct edge {
	int u,v,w;
}e[5*N];
bool cmp(edge a,edge b) {
	return a.w<b.w;
}
int n,m,k,cnt;
int r[15],w[15][N],fa[N],sum,a[N],cn,vis[N];
int find (int x) {
	if(x==fa[x]) return x;
	return x=find(fa[x]);
}
void add (int u,int v,int w) {
	cnt++;e[cnt].u=u,e[cnt].v=v,e[cnt].w=w;
}

map <pair <int,int> ,int> mp;
signed main () {
	freopen ("road.in","r",stdin);
	freopen ("road.out","w",stdout); 
	n=read(),m=read(),k=read();
	if(k==0) {
		for (int i=1;i<=m;i++) {
			int u,v,w;
			u=read(),v=read(),w=read();
			add(u,v,w);add(v,u,w);
		}
		sort(e+1,e+cnt+1,cmp);
		for (int i=1;i<=n;i++) fa[i]=i;
		for (int i=1;i<=cnt;i++) {
			int u=e[i].u,v=e[i].v;
			u=fa[u],v=fa[v];
			if(fa[u]!=fa[v]) {
				cn++;fa[u]=find(fa[v]);
				sum+=e[i].w;
			} if(cn==n-1) {cout<<sum;return 0;}
		} 
	}
	else 
	{
		for (int i=1;i<=m;i++) {
			int u,v,w;
			u=read(),v=read(),w=read();
			add(u,v,w);add(v,u,w);
		} 
		for (int i=1;i<=k;i++) {
			int c=read();
			for (int j=1;j<=n;j++)
				a[j]=read();
			for(int j=1;j<=n;j++) {
				add(j,n+i,a[j]);
				add(n+i,j,a[j]);
			} 
		} sort(e+1,e+cnt+1,cmp);
		int nn=n;
		for (int i=1;i<=n+k;i++) fa[i]=i;
		for (int i=1;i<=cnt;i++) {
			int u=e[i].u,v=e[i].v;
			int uu=u,vv=v;
			u=fa[u],v=fa[v];
			if(fa[u]!=fa[v]) {
				if(uu>n&&!vis[uu]) vis[uu]=1,nn++;
				if(vv>n&&!vis[vv]) vis[vv]=1,nn++;
				cn++;fa[u]=find(fa[v]);
				sum+=e[i].w;
			} if(cn==nn-1) {cout<<sum;break;}
		} 
	}
	return 0;
}
