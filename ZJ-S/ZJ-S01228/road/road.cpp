#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#define MAXN 10002
using namespace std;
long long arr[MAXN][MAXN];
long long tmp[MAXN], dis[MAXN];
bool vis[MAXN];
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	int n, m, k;
	long long ans = 0;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = INT_MAX;
		}
		arr[i][i] = 0;
	}
	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w;
		arr[u][v] = w;
		arr[v][u] = w;
	}
	for (int i = 0, c; i < k; i++) {
		cin >> c;
		for (int j = 1, a; j <= n; j++) {
			cin >> tmp[j];
		}
		for (int x = 1; x <= n; x++) {
			for (int y = 1; y <= n; y++) {
				arr[x][y] = min(arr[x][y], c + tmp[x] + tmp[y]);
			}
		}
	}
	vis[1] = true;
	for (int i = 1; i <= n; i++) {
		dis[i] = arr[1][i];
	}
	for (int _ = 1; _ < n; _++) {
		int mini = -1;
		for (int i = 1; i <= n; i++) {
			if (vis[i]) {
				continue;
			}
			if (mini == -1 || dis[i] < dis[mini]) {
				mini = i;
			}
		}
		vis[mini] = true;
		ans += dis[mini];
		for (int i = 1; i <= n; i++) {
			dis[i] = min(dis[i], arr[mini][i]);
		}
	}
	cout << ans;
	return 0;
}

