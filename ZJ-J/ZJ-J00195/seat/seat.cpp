#include<bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> a[110];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) 
		cin >> a[i].first, a[i].second = i;
	sort(a, a + n * m);
	for (int i = 0; i < n * m; i++) {
		if (a[i].second == 0) {
			cout << m - i / n << ' ';
			if ((m - i / n) % 2 == 1) cout << n - (i % n);
			else cout << 1 + (i % n);
			return 0;
		}
	}
	return 0;
}
