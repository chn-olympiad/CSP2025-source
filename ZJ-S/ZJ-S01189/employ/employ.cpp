#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 10, M = 1e2 + 10;
int n, m, maxx, c[N], s[N], vis[N], a[N], d[M][M][M];
long long ans;
void DFS(int x, int t){
	int flag;
	if (x > n){
		if (t >= m) ans += 1;
		return ;
	}
	for (int i = 1; i <= n; i ++){
		if (vis[i]) continue;
		if (s[x] == 0) flag = 0;
		else {
			if (c[i] > x - 1 - t) flag = 1;
			else flag = 0;
		}
		vis[i] = 1;
		DFS(x + 1, t + flag);
		vis[i] = 0;
	}
	return ;
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) scanf("%1d", & s[i]);
	for (int i = 1; i <= n; i ++) cin >> c[i], maxx = max(maxx, c[i]);
	DFS(1, 0);
	cout << ans;
	return 0;
}