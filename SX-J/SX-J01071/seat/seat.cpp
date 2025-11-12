#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> score(n *m);
	int res = 0;
	for (auto& i : score) {
		cin >> i;
		if (i > score[0])
			res++;
	}
	int ans_row, ans_col;
	ans_col = (res / n) + 1;
	if (ans_col % 2 == 0) {
		ans_row = n - res % n;
	} else {
		ans_row = 1 + res % n;
	}
	cout << ans_col << ' ' << ans_row;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
//	int T;
//	cin >> T;
//	while (T--) {
//		solve();
//	}
	solve();
	return 0;
}