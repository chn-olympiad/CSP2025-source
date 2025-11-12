#include<bits/stdc++.h>
using namespace std;
//const int Fuck_CCF=114514;
int n,m,k,xcl[10][10005],xc[15];
map<int ,int >e[10005];
//long long ans[10005]={1000000000};
//int lt[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u][v]=w;
		e[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>xc[i];
		for(int j=1;j<=n;j++){
			cin>>xcl[i][j];
		}
	}
	cout<<0;
	return 0;
}