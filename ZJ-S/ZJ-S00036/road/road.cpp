#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 5;
const int M = 1e5 + 5;

ll dis[N][N],c[11],a[11][N];
int n,m,k;

//¼ÇµÃÉ¾×¢ÊÍ
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dis[i][j] = 1e9 + 5;
			if (i == j) dis[i][j] = 0;
		}
	}
	for(int i = 1; i <= m; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		dis[u][v] = w;
		dis[v][u] = w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dis[i][j] > dis[i][k] + dis[k][j])
				dis[i][j] = dis[i][k] + dis[k][j];
			}
		}
	}
	
	cout << dis[1][n] << endl;

	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
Ren5Jie4Di4Ling5%
*/
