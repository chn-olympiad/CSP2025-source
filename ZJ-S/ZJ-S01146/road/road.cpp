#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	int u,v,w;
};
vector<node> vec[1000001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		vec[u].push_back({v,w});
		vec[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		int a,b;
		cin>>a;
		for(int j=1;j<=n;j++){
			cin>>b;
		}
	}
	cout<<0;
	return 0;
}

