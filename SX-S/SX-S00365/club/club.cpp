#include <bits/stdc++.h>
using namespace std;
int a[100005][3];
int maxn;
int anser;
int n;
int d[100005];

void dfs(int u, int size[], int sum) {
	if (u == n + 1) {
		anser = max(anser, sum);
		/*for (int i = 1; i <= n; i++) {
			cout << d[i] << " ";
		}
		cout << "Oh" << '\n';*/
		return;
	}
	for (int i = 1; i <= 3; i++) {
		if (size[i] <= maxn) {
			d[u] = a[u][i];
			sum += a[u][i];
			size[i]++;
			dfs(u + 1, size, sum);
			sum -= a[u][i];
			size[i]--;
		}
	}
}
int c[3];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int z = 1;
	cin >> z;
	for (int j = 1; j <= z; j++) {
		memset(a, sizeof a, 0);
		anser = -1;
		cin >> n;
		maxn = n / 2;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		dfs(1, c, 0);
		cout << anser;
	}
	return 0;
}