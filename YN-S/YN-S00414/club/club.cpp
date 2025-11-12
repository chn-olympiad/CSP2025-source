#include <bits/stdc++.h>
using namespace std;
#define int long long
//    CJC 2025 11 1 S T1 CODE AC
const int N = 1e5 + 5;
int T, n;

struct node {
	int ch[5];
};
node a[N];

bool cmp(node a, node b) {
	return a.ch[3] + a.ch[2] + a.ch[1] > b.ch[3] + b.ch[2] + b.ch[1];
}

int f(int x, int y, int z) {
	int u = max(x, max(y, z));
	if (x == u)
		return 1;
	if (y == u)
		return 2;
	if (z == u)
		return 3;
}

int f1(int x, int y, int z, int op) {
	int u = max(x, max(y, z));
	int v = min(x, min(y, z));
	int cnt = 0;
	if (x != u and x != v)
		cnt = 1;
	if (y != u and y != v)
		cnt = 2;
	if (z != u and z != v)
		cnt = 3;
	if (cnt == 0 or cnt == op) {
		cnt = (op + 1) % 3;
		if (cnt == 0)
			cnt = 3;
	}
	return cnt;
}

signed main(void) {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i].ch[1] >> a[i].ch[2] >> a[i].ch[3];
		sort(a + 1, a + n + 1, cmp);
		priority_queue<pair<int, int>>pq[5];
		int num = 0;
		for (int i = 1; i <= n; i++) {
			int now = f(a[i].ch[1], a[i].ch[2], a[i].ch[3]);
			if (pq[now].size() < n / 2)
				pq[now].push({-a[i].ch[now], i}), num += a[i].ch[now];
			else {
				int tmp = pq[now].top().second;
				int now2 = f1(a[tmp].ch[1], a[tmp].ch[2], a[tmp].ch[3], f(a[tmp].ch[1], a[tmp].ch[2], a[tmp].ch[3]));
				int now3 = f1(a[i].ch[1], a[i].ch[2], a[i].ch[3], now);
				if (num + a[i].ch[now3] > (num + pq[now].top().first + a[i].ch[now] + a[tmp].ch[now2])) {
					pq[now3].push({-a[i].ch[now3], i});
					num += a[i].ch[now3];
					continue;
				}
				num = num + pq[now].top().first + a[i].ch[now] + a[tmp].ch[now2];
				pq[now].pop();
				pq[now2].push({-a[tmp].ch[now2], tmp});
				pq[now].push({-a[i].ch[now], i});
			}
		}
		cout << num << "\n";
	}
	return 0;
}