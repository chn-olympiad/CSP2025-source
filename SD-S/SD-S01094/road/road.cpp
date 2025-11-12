#include<bits/stdc++.h>//柬埔寨人看到这道题吓哭了 
#define ll long long
using namespace std;
const int MAXN=1e4+10,MAXM=1e6+10,INF=1e9+10;
inline int read(){
	int x=0;bool f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=0;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f?x:-x;
}
struct edge{
	int v,w;
};
vector<edge>g[MAXN];
int n,m,s;ll ans;
int c[15];
int a[15][MAXN];
int fa[MAXN];
int dis[MAXN];
int find(int u){
	if(fa[u]==u)return u;
	return fa[u]=find(fa[u]);
}
void kruskal(){
	ans=0;
	fa[1]=1;
	int cnt=0;
	dis[++cnt]=1;
	while(cnt<n){
		int minw=INF,minv=-1;
		for(int i=1;i<=cnt;i++){
			int u=dis[i];
			for(int j=0;j<g[u].size();j++){
				int v=g[i][j].v,w=g[i][j].w;
				if(find(v)==fa[u])continue;
				if(minw>w)minw=w,minv=v;
//	cout<<1;
			}
		}
		ans+=minw;dis[++cnt]=minv;fa[minv]=1;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),s=read();
	///cout<<1;
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		g[u].push_back((edge){v,w});
		g[v].push_back((edge){u,w}); 
	}
////	cout<<1;
	for(int i=1;i<=n;i++)fa[i]=i;
	bool flag=0;
	for(int i=1;i<=s;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
///	cout<<1;
	kruskal();
	cout<<ans;
		fclose(stdin);
		fclose(stdout);
	return 0;
}

