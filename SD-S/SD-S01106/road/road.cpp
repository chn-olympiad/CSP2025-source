#include<bits/stdc++.h>
using namespace std;
int n,m,k;
inline int read()
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
int fa[10020];
int find(int x)
{
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}

struct edge{
	int u,v;
	int w;
}bian[1100005];
struct node{
	int to;
	int wei;
};
vector<node> g[10020];
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
void krusckal(){
	for(int i=1;i<=m+n*k;i++){
		edge noww=bian[i];
		if(find(noww.u)!=find(noww.v)){
			fa[fa[noww.u]]=fa[noww.v];
			node xian;
			xian.to=noww.v,xian.wei=noww.w;
			g[noww.u].push_back(xian);
			xian.to=noww.u;
			g[noww.v].push_back(xian);
		}
	}
	return;
}
bool vis[10020];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		bian[i].u=read();
		bian[i].v=read();
		bian[i].w=read();
	}
	for(int i=1;i<=k;i++){
		edge noww;
		noww.u=read()+n;
		for(int j=1;j<=n;j++){
			noww.w=getchar();
			noww.v=j;
			bian[m+(i-1)*n+j]=noww;
		}
	}
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	sort(bian+1,bian+1+m+n*k,cmp);
	krusckal();
	long long ans=0;
	for(int i=1;i<=n+k;i++){
		for(int j=0;j<g[i].size();j++){
			int v=g[i][j].to;
			int quan=g[i][j].wei;
			if(v>n&&g[v].size()==1){
				continue;
			}
			if(vis[v])continue;
			ans+=quan;
		}
		vis[i]=1;
	}
	cout<<ans; 
	return 0;
}
