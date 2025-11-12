#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
int n, m, a[MAXN];
int findR(int score) {
	for (int i = 0; i < n * m; i++) {
		if (a[i] == score) return i;
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int t = n * m;
	for (int i = 0; i < t; i++) {
		cin >> a[i];
	}
	int rs = a[0];
	sort(a, a + t, greater<int>());
	int pos = findR(rs);
	int col = pos / n, row = pos % n;
	if (col % 2 == 1) row = n - row - 1;
	cout << (col + 1) << " " << (row + 1) << endl;
	return 0;
}
// AC