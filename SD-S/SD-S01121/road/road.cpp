#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+105,maxm=2e6+105;
int read(){
	int f=1,x=0;
	char ch=getchar();
	while (ch<'0' || '9'<ch){
		if (ch=='-') f*=-1;
		ch=getchar();
	}
	while ('0'<=ch && ch<='9'){
		x=(x*10+ch-'0');
		ch=getchar();
	}
	return f*x;
}
int n,m,k,tot;
struct node{
	int u,v,w;
}eg[maxm];
int fa[maxn],res;
int sz[maxn];
int find(int x){
//	cout<<x<<' ';
	if (fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for (int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		tot++;
		eg[tot].u=u;
		eg[tot].v=v;
		eg[tot].w=w;
		tot++;
		eg[tot].u=v;
		eg[tot].v=u;
		eg[tot].w=w;
	}
	for (int i=n+1;i<=n+k;i++){
		int tmp=read();
		for (int j=1;j<=n;j++){
			int p=read();
			/*
			tot++;
			eg[tot].u=i;
			eg[tot].v=j;
			eg[tot].w=p;
			tot++;
			eg[tot].u=j;
			eg[tot].v=i;
			eg[tot].w=p;
			*/
		}
	}
	sort(eg+1,eg+1+tot,cmp);
	for (int i=0;i<maxn;i++)
		fa[i]=i;
	for (int i=1;i<=n;i++)
		sz[i]=1;
	for (int i=1;i<=tot;i++){
		int u=eg[i].u,v=eg[i].v;
//		cout<<u<<' '<<fa[u]<<'\n';
		int fau=find(u),
			fav=find(v);
//		cout<<"OK\n";
		if (!(fau==fav)){
			res+=eg[i].w;
			fa[fau]=fav;
			sz[v]+=sz[u];
			if (sz[v]==n) break;
		}
	}
	cout<<res;
	return 0;
}

