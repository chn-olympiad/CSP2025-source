#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e2 + 10;
int a[N];
bool cmp (int a, int b) {
	return a > b;
}
signed main () {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	int tot = 0;
	for (int i = 1; i <= n; i ++ ) {
		for (int j = 1; j <= m; j ++ ) {
			int t; cin >> t;
			a[++tot] = t;
		}
	}
	int f = a[1], num = 0;
	sort (a + 1, a + tot + 1, cmp);
	for (int i = 1; i <= tot; i ++ ) {
		if (a[i] == f) {
			num = i;
			break;
		}
	}
	int c = num / n, r = (num - 1) % n + 1;
	if (num % n) c ++;
	if (c % 2 == 0) r = n - r + 1;
	cout << c << " " << r;
} 
