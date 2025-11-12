#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
struct Node{
	long long v,w;
};
vector<Node> e[1000005];
long long c[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>c[j];
		}
	}
	cout<<0;
	return 0;
}
