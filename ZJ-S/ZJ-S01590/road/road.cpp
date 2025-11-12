#include<bits/stdc++.h>
using namespace std;
vector<int> G[10005];
struct edge{
	int u,v,w;
}e[1000005];
int c[15];
int a[10][10005];
bool cmp(edge a1,edge a2){
	return a1.w<a2.w;
}
class DSU{
	private:
		int fa[10005];
		int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
	public:
		DSU(int size){for(int i=1;i<=size;i++) fa[i]=i;}
		void merge(int a,int b){int A=find(a),B=find(b);fa[A]=B;}
		bool sameset(int a,int b){return find(a)==find(b);}
};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m,k;cin>>n>>m>>k;
	DSU dsu(n);
	for(int i=1;i<=n;i++) G[i].resize(n+1-i,INT_MAX);
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
		if(k!=0){
			if(e[i].u>e[i].v) swap(e[i].u,e[i].v);
			G[e[i].u][e[i].v-e[i].u]=min(G[e[i].u][e[i].v-e[i].u],e[i].w);
		}
	}	
	if(k==0){
		sort(e+1,e+1+m,cmp);
		long long ans=0;
		for(int i=1;i<=m;i++){
			if(!dsu.sameset(e[i].u,e[i].v)){
				ans+=e[i].w;
				dsu.merge(e[i].u,e[i].v);
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	int len=0;
	for(int i=1;i<=n;i++){
		for(int j=1;i+j<=n;j++){
			for(int x=1;x<=k;x++) G[i][j]=min(G[i][j],a[x][i]+a[x][j]);
			e[++len]={i,i+j,G[i][j]};
		}
	}
	sort(e+1,e+1+len,cmp);
	long long ans=0;
	for(int i=1;i<=m;i++){
		if(!dsu.sameset(e[i].u,e[i].v)){
			ans+=e[i].w;
			dsu.merge(e[i].u,e[i].v);
		}
	}
	cout<<ans;
	return 0;
}
