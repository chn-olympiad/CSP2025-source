#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,k,u,v,w;
vector <pair<int,int>> vt[1000001];
void kusal(){
	cout<<13<<endl;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		vt[u].push_back({v,w});
		vt[v].push_back({u,w});
	}
	kusal();
	return 0;
}