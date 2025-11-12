#include <bits/stdc++.h>
using namespace std;
/*
about 3 minute
100 pts
*/
int n, m, seat[110][110];
vector<int> a;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	a.resize(n * m);
	for (auto& i: a) cin >> i;
	int find_R = a[0];
	int id = 0, x = 1, y = 1; // x: row y: line
	sort(a.rbegin(), a.rend());
	while (id < n * m) {
		seat[x][y] = a[id];
		if (a[id] == find_R) {
			cout << y << " " << x;
			return 0;
		}
		id ++;
		if (y % 2 == 1) x ++;
		if (y % 2 == 0) x --;
		if (x > n) x = n, y ++;
		if (x < 1) x = 1, y ++;
	}
	return 0;
}