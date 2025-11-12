#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,M=2e4+5;
int n,a[15][N],c[N],p[N];
int find(int x){
	if(x!=p[x]) x=find(p[x]);
	return p[x];
}
void merge(int a,int b){
	int pa=p[a],pb=p[b];
	if(pa!=pb){
		p[pa]=pb;
	}
}
bool same(int a,int b){
	int pa=p[a],pb=p[b];
	return pa==pb;
}
vector<pair<int,int>> g[N];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int u,v,w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		merge(u,v);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	return 0;
} 
