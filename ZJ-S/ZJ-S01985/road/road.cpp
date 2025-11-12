#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,k;
struct node{
	int to;
	int v;
};
vector <node> edge[N][N];
int c[N],a[N][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edge[u][v].push_back(w);
		edge[v][u].push_back(w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
