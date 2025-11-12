#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>

using namespace std;

const int M=2e6+5,N=2e4+5;
int n,m,k,ans,Edge;
pair<int,pii> g[M];
int fa[N],c[N];
int f[N][15];

inline int read(){
	int num=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while('0'<=c&&c<='9') num=num*10+(c-'0'),c=getchar();
	return num*f;
}

int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}


signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		g[i].second.first=read();
		g[i].second.second=read();
		g[i].first=read();
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			f[i][j]=read();
			g[++m].second.first=n+i;
			g[m].second.second=j;
			g[m].first=f[i][j];
		}
	}
	n+=k;
	sort(g+1,g+m+1);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int u=g[i].second.first,v=g[i].second.second;
		if(find(u)!=find(v)){
			ans+=g[i].first;
			Edge++;
			fa[find(u)]=find(v);
		}
		if(Edge==n-1) break;
	}
	printf("%lld",ans);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 0 8 2 4
0 0 3 2 4
*/
