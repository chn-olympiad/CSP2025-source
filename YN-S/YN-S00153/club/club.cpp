#include <bits/stdc++.h>
using namespace std;
int b[100005];
int ccc[5], n, cnt = 0;

struct aaa {
	int x, y, z;
} a[100005];

void dfs(int dep, int ans) {
	if (dep > n) {
		cnt = max(cnt, ans);
		return ;
	}
	if (b[1] < n / 2) {
		b[1]++;
		dfs(dep + 1, ans + a[dep].x);
		b[1]--;
	}
	if (b[2] < n / 2) {
		b[2]++;
		dfs(dep + 1, ans + a[dep].y);
		b[2]--;
	}
	if (b[3] < n / 2) {
		b[3]++;
		dfs(dep + 1, ans + a[dep].z);
		b[3]--;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		cnt = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].z;
		}
		dfs(1, 0);
		cout << cnt << '\n';
	}
	return 0;
}