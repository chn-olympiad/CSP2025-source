#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int t, n, a[N][3], ans;

int Abs(int x) {
	return x > 0 ? x : -x;
}

void run() {
	priority_queue<int>q[3];
	scanf("%d", &n), ans = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
		int mx = -1, mxi = -1;
		for (int j = 0; j < 3; ++j) {
			if (a[i][j] > mx)
				mxi = j, mx = a[i][j];
		}
		ans += mx, mx = -0x3f3f3f3f;
		for (int j = 0; j < 3; ++j) {
			if (j == mxi)
				continue;
			mx = max(mx, a[i][j] - a[i][mxi]);
		}
		q[mxi].push(mx);
	}
	for (int i = 0; i < 3; ++i) {
		while (q[i].size() > n / 2)
			ans += q[i].top(), q[i].pop();
	}
	printf("%d\n", ans);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--)
		run();
	return 0;
}
