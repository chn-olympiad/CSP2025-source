#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int sum;
vector <int> g;
int cnt = 1;
const int N = 1e3+22;
int a[N][N];

signed main() {
	cin >> n >> m;
	int t = m * n;
	while (t--) {
		int x;
		cin >> x;
		if (cnt) {
			sum = x;
			cnt = 0;
		}
		g.push_back(x);
	}
	sort(g.rbegin(), g.rend());
	/*	for (auto i : g) {
			cout << i << ' ';
		}*/
//	cout << sum;
	cout << endl;
	int c = 0;
	for (int j = 1; j <= m; j++) {

		if (j % 2 == 1) {
			for (int i = 1; i <= n; i++) {
				a[i][j] = g[c];
				c++;
			}
		} else {
			for (int i = n; i >= 1; i--) {
				a[i][j] = g[c];
				c++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == sum)
				cout << j << ' ' << i;
		}
	}

	return 0;
}


/*3 4
1 2 3 4 5 6 7 8 9 10 11 12*/