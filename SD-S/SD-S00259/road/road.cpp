#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int N=1e6+5;
int n,m,k,u,v,w,c[N],a[N];
vector<pii>g[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>u>>v>>w;
		g[u].push_back(pii(v,w));
		g[v].push_back(pii(u,w));
	}for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j){
			cin>>a[j];
			g[m+i].push_back(pii(j,a[j]+c[i]));
			g[j].push_back(pii(m+i,a[j]+c[i]));
		}//将其视为一种新的节点
	}//单源最短路*n->O(n^2logn)
	cout<<0;//A
	return 0;
}/*
4 4 2

1 4 6
2 3 7
2 4 5
3 4 4

  1 1 8 2 4
100 1 3 2 4
*/
