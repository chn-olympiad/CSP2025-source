#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define fr front
#define INF 2e9
using namespace std;

int n,m,k,a[15][10005],fa[10005],val[10005],c[10005];
struct edge{
	int u,v,w;
	friend bool operator<(edge a,edge b){
		return a.w<b.w;
	} 
}e[1000005];
vector<pii> g[20005],t[15][20005];

int find(int a){
	if(fa[a]==a)return a;
	return fa[a]=find(fa[a]);
}

void kruskal(){
	sort(e+1,e+m+1);
	int ans=0;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int fau=find(u),fav=find(v);
		if(fau==fav)continue;fa[fau]=fav;
		ans+=e[i].w;
	}
	cout<<ans;
}

signed main(){
	ios::sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			e[++m].u=n+i;e[m].v=j;e[m].w=a[i][j];
		}
	}
	kruskal();
}
/*
题目中的乡镇不是原来的n个城市中的
不难发现，一组边只能松弛一次，所以它假了
 
只能用最后一种了：我们倒着删边，每次我们找这条边能被哪两条边替代、
我们用换根预处理了外部和内部点
然后我们枚举边的时候可以考虑到两边的集合有没有和这个点联通 

写暴力吧，我们直接枚举两个点， 
*/
