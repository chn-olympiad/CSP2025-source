#include <bits/stdc++.h>
using namespace std;

const int N = 10, M = 10, A = 100;

int a[N * M + 5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int cnt = 0;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if (a[i] >= a[1])
			cnt++;
	}
	int co = (cnt + n - 1) / n, ro = co % 2 ? (cnt - 1) % n + 1 : n - ((cnt - 1) % n + 1) + 1;
	cout << co << ' ' << ro << '\n';
	return 0;
}
