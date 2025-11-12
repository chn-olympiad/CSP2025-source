#include <bits/stdc++.h>
using namespace std;

int T, n;
int cnt[4];
int a[100005][4];
int agans = 0;
int ans = 0;

void dfs(int k) {
	if (k > n) {
		agans = max(ans, agans);
		return;
	}
	for (int i = 1; i <= 3; i++) {
		if (cnt[i] + 1 > n / 2)
			continue;
		ans += a[k][i];
		cnt[i]++;
		dfs(k + 1);
		cnt[i]--;
		ans -= a[k][i];
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	cin >> T;

	while (T--) {
		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		if (n >= 100000) {
			for (int i = 1; i <= n; i++) {
				agans += a[i][1];
			}
			continue;
		}
		dfs(1);
		cout << agans << endl;
	}
	return 0;

}

