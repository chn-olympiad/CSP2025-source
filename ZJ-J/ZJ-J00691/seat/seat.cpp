#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define FOR(i, l, r, x) for (int i = l; i <= r; i = x)
#define DEFOR(i, l, r, x) for (int i = l; i >= r; i = x)
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, me = 0, p = 1;
	cin >> n >> m >> me;
	FOR(i, 2, n * m, ++i) {
		int u;
		cin >> u;
		if (u > me) {
			p++;
		}
	}
	int c = p / n, r;
	if (p % n != 0) {
		c++;
		r = p % n;
	} else {
		r = n; 
	}
	if (c % 2 == 0) {
		r = n - r + 1;
	}
	cout << c << " " << r << endl;
	return 0;
}