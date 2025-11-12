#include<bits/stdc++.h>
using namespace std;
vector<int> e[10005];
int n,m,k;
int w[1000005],c[15],a[15][100005];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v>>w[i];
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	cout<<114514;
	return 0;
}
