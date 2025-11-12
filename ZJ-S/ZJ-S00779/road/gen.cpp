#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define sz size
#define fi first
#define se second
#define mem(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 1e5 + 5;

mt19937 rnd(time(NULL));

int fa[N];

signed main() {
	freopen("road114.in", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n = 10000, m = 1000000, k = 10;
	cout << n << ' ' << m << ' ' << k << '\n';
	for (int i = 2; i <= n; i++) cout << i << ' ' << rnd() % (i - 1) + 1 << ' ' << rnd() << '\n';
	for (int i = 1; i <= m - (n - 1); i++) cout << rnd() % n + 1 << ' ' << rnd() % n + 1 << ' ' << rnd() << '\n';
	for (int i = 1; i <= k; i++) {
		cout << rnd() << ' ';
		for (int i = 1; i <= n; i++) cout << rnd() << ' ';
		cout << '\n';
	}
	return 0;
}
