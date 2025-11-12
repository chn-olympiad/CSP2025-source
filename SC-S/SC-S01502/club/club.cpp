#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;

int n, a[3][N];
int where[N], cnt[3];

void process() {
	
	cin >> n;
	cnt[0] = cnt[1] = cnt[2] = 0;
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j < 3; j ++) cin >> a[j][i];
		int mx = 0, wh = 0;
		for (int j = 0; j < 3; j ++)
			if (mx <= a[j][i]) mx = a[j][i], wh = j;
		where[i] = wh, cnt[wh] ++, ans += mx;
	}
	priority_queue<int> q;
	for (int i = 0; i < 3; i ++) if (cnt[i] > n / 2) {
		for (int j = 1; j <= n; j ++) if (where[j] == i) {
			int mx = -1e9;
			for (int k = 0; k < 3; k ++) if (i != k)
				 mx = max(mx, a[k][j] - a[i][j]);
			q.push(mx);
		}
		while (cnt[i] > n / 2) cnt[i] --, ans += q.top(), q.pop();
	}
	
	cout << ans << "\n";
	
}

int main() {
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	
	int t; cin >> t;
	while (t --) process();
	
	return 0;
}