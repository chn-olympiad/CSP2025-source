#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=1e5+10;
struct node{
	int v,x;
};
int n,m,k,a[11][10010],cnt=1e18;
vector<node>G[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,x;
		cin>>u>>v>>x;
		G[u].push_back({v,x});
		G[v].push_back({u,x});
	}
	for(int i=1;i<=k;i++){
		int c=0;
		for(int j=0;j<=n;j++){
			cin>>a[i][j];
			c+=a[i][j];
		}cnt=min(c,cnt);
	}
	cout<<cnt;
	return 0;
}

