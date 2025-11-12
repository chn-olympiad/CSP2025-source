#include <bits/stdc++.h>

using namespace std;

const int N = 1010, M = 1e6 + 10, K = 20;

int n, m, k, s;
int a[K][N], t, dist;

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i ++ ){
		int a1, b1, c1;
		scanf("%d%d%d", &a1, &b1, &c1);
		s += c1;
	}
	for (int i = 1; i <= k; i ++ ){
		scanf("%d", &t);
		for (int j = 1; j <= n; j ++ ){
			scanf("%d", &a[i][j]);
		}
	}
	cout << s;
	return 0;
}
