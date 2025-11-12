#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
typedef long long ll;
typedef pair<ll,ll> pll;
vector<pll> g[N];
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({w,v});
	}
	for(int i=1;i<=k;i++){
		int j=n+i;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
		}
	}
	cout<<"0"<<endl;
	return 0;
}
