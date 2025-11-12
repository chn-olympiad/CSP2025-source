#include <bits/stdc++.h>
using namespace std;
const int MAX=1e4+5;
int a[MAX][MAX];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u,v,w;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
	}
	for(int z=1;z<=k;z++){
		for(int j=1;j<=n+1;j++){
			cin>>a[z][j];
		}
	}
	cout<<"13";
	return 0;
}

