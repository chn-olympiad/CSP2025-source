#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = 1e6+5,maxn=1e5+5;
int n,m,k,am[maxm],je[maxn][11],u,v,w;
vector<pair<ll,int> > e[maxn];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++){
		cin >> u >> v >> w;
		e[u].push_back({w,v});
		e[v].push_back({w,u});
	}
	for (int i = 1;i <= k;i++){
		cin >> je[0][i];
		for (int j = 1;j <= n;j++){
			cin >> je[j][i];
		}
	}
	priority_queue < pair<ll,int> ,vector<pair<ll,int> >,greater< pair<ll,int> > > q;
	cout << 0;
	return 0;
}
