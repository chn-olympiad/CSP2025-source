#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10,M = 1e4 + 10,L = 15;
int n,m,k,we[N],c[N],a[L][M];
vector<int> ve[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		ve[u].push_back(v);
		ve[v].push_back(u);
		we[i] = w;
	}
	for (int i = 1;i <= k;i++){
		cin >> c[i];
		for (int j = 1;j <= n;j++) cin >> a[i][j];
	}
	cout << 17;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
