#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n;
int a[N][3];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
	int x = 0, y = 0, z = 0, ans = 0;
	priority_queue <int, vector<int>, greater<int> > q1, q2, q3;
	for (int i = 1; i <= n; i++) {
		int Max = max(a[i][0], max(a[i][1], a[i][2]));
		ans += Max;
		if (Max == a[i][0]) {
			x++;
			q1.push(a[i][0] - max(a[i][1], a[i][2]));
		}
		else if (Max == a[i][1]) {
			y++;
			q2.push(a[i][1] - max(a[i][0], a[i][2]));
		}
		else {
			z++;
			q3.push(a[i][2] - max(a[i][0], a[i][1]));
		}
	}
	if (x > n / 2) {
		for (int i = 0; i < x - n / 2; i++) {
			ans -= q1.top();
			q1.pop();
		}
	}
	else if (y > n / 2) {
		for (int i = 0; i < y - n / 2; i++) {
			ans -= q2.top();
			q2.pop();
		}
	}
	else if (z > n / 2) {
		for (int i = 0; i < z - n / 2; i++) {
			ans -= q3.top();
			q3.pop();
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int T;
	cin >> T;
	while (T--) solve();
	
	return 0;
}
