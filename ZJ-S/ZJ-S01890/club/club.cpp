#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

bool use[N];
int T, n, a[N][5], cnt[5], ans;
priority_queue < pair < int, int > > q[5];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		
		ans = 0;
		for (int i = 1; i <= 3; i++) {
			cnt[i] = 0;
			while (q[i].size()) q[i].pop();
		}
		for (int i = 1; i <= n; i++)
			use[i] = 0;
		
		for (int i = 1; i <= n; i++) 
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		for (int i = 1; i <= n; i++) {
			if (a[i][1] == a[i][2] && a[i][2] == a[i][3]) {
				ans += a[i][1]; continue;
			}
			int maxi = 1;
			for (int j = 1; j <= 3; j++)
				if (a[i][j] > a[i][maxi]) maxi = j;
			for (int j = 1; j <= 3; j++) 
				if (j != maxi) q[maxi].push({a[i][j] - a[i][maxi], i}); 
			cnt[maxi]++, ans += a[i][maxi];
		}
		if (cnt[1] <= n/2 && cnt[2] <= n/2 && cnt[3] <= n/2) {
			cout << ans << '\n';
			continue;
		}
		int id = 1;
		for (int i = 1; i <= 3; i++) if (cnt[i] > n/2) id = i;
		while (cnt[id] > n/2) {
			int val = q[id].top().first, x = q[id].top().second; q[id].pop();
			if (use[x]) continue; 
			use[x] = 1, cnt[id]--, ans += val;
		}
		cout << ans << '\n'; 
	}
	return 0;
}
