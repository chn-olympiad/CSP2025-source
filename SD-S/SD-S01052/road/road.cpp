//T2
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
const int N=1e4+5,M=1e6+5,K=15;
const ll INF=1e18;
int n,m,k;
int fa[N];
void init(){
	for(int i=1;i<=n;i++) fa[i]=i;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	if(x==y) return;
	fa[x]=y;
}

struct node{
	int u,v;
	ll w;
	friend bool operator<(node a,node b){
		return a.w<b.w;
	}
};
vector<node> p;
ll c[N],a[N][K],g[N][N]; 

ll kruskal(){
	int tot=1;
	ll ans=0;
	for(node i:p){
		int u=find(i.u),v=find(i.v);
		if(u==v) continue;
		merge(u,v);
		ans+=i.w;
		if((++tot)==n) break;
	}
	return ans;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		g[i][j]=INF;
	for(int i=1;i<=m;i++){
		int u,v;
		ll w;
		cin>>u>>v>>w;
		if(u>v) swap(u,v);
		g[u][v]=min(g[u][v],w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++){
		ll minn=INF;
		for(int l=1;l<=k;l++)
			minn=min(minn,a[l][i]+a[l][j]);
		g[i][j]=min(g[i][j],minn);
	}
	
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)
		if(g[i][j]!=INF) p.push_back({i,j,g[i][j]});
	
	init();
	sort(p.begin(),p.end());
	cout<<kruskal()<<endl;

	return 0;
}

