#include <bits/stdc++.h>
using namespace std;

const int T = 5, N = 1e5, A = 2e4;

int biggest(int val1, int val2, int val3) {
	if (val1 >= val2 && val1 >= val3)
		return 1;
	else if (val2 >= val1 && val2 >= val3)
		return 2;
	else
		return 3;
}

int a[N + 5][5];

priority_queue<int> que;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		int ans = 0, cnt[5] = {0, 0, 0, 0, 0};
		for (int i = 1; i <= n; i++) {
			int now = biggest(a[i][1], a[i][2], a[i][3]);
			cnt[now]++;
			ans += a[i][now];
		}
		int ind = biggest(cnt[1], cnt[2], cnt[3]);
		if (cnt[ind] > n / 2) {
			for (int i = 1; i <= n; i++) {
				int now = biggest(a[i][1], a[i][2], a[i][3]), oth1 = now % 3 + 1, oth2 = (now + 1) % 3 + 1;
				if (now == ind)
					que.push(max(a[i][oth1], a[i][oth2]) - a[i][now]);
			}
			for (int i = 1; i <= cnt[ind]; i++) {
				if (i <= cnt[ind] - n / 2)
					ans += que.top();
				que.pop();
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
