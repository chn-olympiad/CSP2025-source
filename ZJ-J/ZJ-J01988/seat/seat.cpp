#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
const int N = 1e2 + 7, M = 1e4;
int n, m, a[N];
void IOS() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	return ;
}
void file() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	return ;
}
void __init() {
	file();
//	IOS();
	return ;
}
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i) {
		cin >> a[i];
	}
	int k = a[1], Idex = 0;
	sort (a + 1, a + n * m + 1);
	for (int i = 1; i <= n * m; ++i) {
		if (a[i] == k) {
			Idex = i;
			break;
		}
	}
	Idex = n * m - Idex + 1;
	int x = Idex % n, y;
	if (x == 0) {
		y = Idex / n;
		x = n;
	} else {
		y = Idex / n + 1;
	}
	if (y % 2 == 0) {
		x = n - x + 1;
	}
	cout << y << ' ' << x << '\n';
	return ;
}
int main() {
	__init();
	LL _ = 1;
//	cin >> _;
	while (_--) {
		solve();
	}
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92

*/
