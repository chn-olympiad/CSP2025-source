#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MAXN = 1e5+5;
const int MAXK = 1e1+5;

int n,m,k;
vector<pair<int,int> >edge[MAXN];
int c[MAXK],a[MAXK][MAXN];
bool check(){
	for (int i=1;i<=k;i++) {
		if (c[i] != 0) return 0;
	}
	for (int i=1;i<=k;i++) {
		for (int j=1;j<=n;j++) {
			if (a[i][j] != 0) return 0;
		}
	}
	return 1;
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for (int i=1,u,v,w;i<=m;i++) {
		cin>>u>>v>>w;
		edge[u].emplace_back(w,v);
		edge[v].emplace_back(w,u);
	}
	for (int i=1;i<=k;i++) {
		cin>>c[i];
		for (int j=1;j<=n;j++) {
			cin>>a[i][j];
		}
		
	}
	if (check()) {
		cout<<0;
	}
	return 0;
}
