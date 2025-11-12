#include <bits/stdc++.h>
using namespace std;
int n, m, k, road;
int places[10009];
int roads[1000006][3];
int index1 = 0;

int vis1[1000006];
int vis2[1000006];
int maxi;

void dfs(int now, int num, int sum) {
	if (num == n + 1) {
		ans++;
		return;
	}
	for (int i = 1; i <= road; i++) {
		if (roads[i][0] == now && !vis[i]) {
			if (roads[i][1] <= n) {
				vis1[i] = 1
			}
		}
	}

}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	return 0;
}
