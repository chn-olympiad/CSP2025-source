#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
long long a[N], b[14][N], s[14], o = 0, ma = LLONG_MIN;

void print(int k) {
	if (ma < k) {
		ma = k;
	}
}

void dfs(int k, int f, int y) {
	if (y - 1 == a[f]) {
		print(k);
		return;
	}
	for (int i = 1; i <= 3; i++) {
		if (s[i] + 1 <= a[f] / 2) {
			s[i]++;
			k = k + b[i][y];
			y++;
			dfs(k, f, y);
			y--;
			k = k - b[i][y];
			s[i]--;
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	long long n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ma = LLONG_MIN;
		cin >> a[i];
		for (int j = 1; j <= a[i]; j++) {
			cin >> b[1][j] >> b[2][j] >> b[3][j];
		}
		dfs(0, i, 1);
		cout << ma << endl;
	}
	return 0;
}
