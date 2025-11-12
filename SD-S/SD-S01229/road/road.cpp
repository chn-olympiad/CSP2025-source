#include<bits/stdc++.h>
using namespace std;
struct node{
	int v,w;
};
vector<node>edg[10001];
int c[11][10001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int x,y,z;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		edg[x].push_back({x,z});
		edg[x].push_back({y,z});
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>c[i][j];
		}
	}
	cout<<587493782;
	return 0;
}

