#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define i128 _int128_t
#define endl "\n"
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1e6+100;
const int MaxN = 1e9;
int a[105];

bool cmp(int x, int y) {
	return x > y;
}

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int x;
	cin >> x;
	a[1] = x;
	for (int i = 2; i <= n * m; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= m; i++) { //列
		if (i % 2 == 1) {
			for (int j = 1; j <= n; j++) { //行
				int it = (i - 1) * n + j; //排名
				if (a[it] == x) {
					cout << i << ' ' << j;
					return 0;
				}
			}
		} else {
			for (int j = n; j >= 1; j--) {
				int it = i * n - j + 1; //排名
				if (a[it] == x) {
					cout << i << ' ' << j;
					return 0;
				}
			}
		}
	}
	return 0;
}