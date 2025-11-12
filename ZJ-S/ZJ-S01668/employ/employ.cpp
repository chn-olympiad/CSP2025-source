//Luogu 743373-Vitamin_B:)
//ZJ-S01668
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

const ll mod = 998244353;

int n, m, s[505], c[505], sum, tot;

ll p = 1;

int main () {
	freopen ("employ3.in", "r", stdin);
//	freopen ("employ.in", "r", stdin);
//	freopen ("employ.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);

	cin >> n >> m;

	for (int i = 1; i <= n; ++ i)
		cin >> s[i], tot += (! s[i]);

	for (int i = 1; i <= n; ++ i)
		cin >> c[i], sum += (bool) (c[i]);

	sort (c + 1, c + 1 + n, greater <int> ());

//	for (int i = 1; i <= m; ++ i)
//		if (c[i] <= 0) {
//
//			cout << 0;
//
//			return 0;
//
//		}

//	if (sum < m) {
//
//		cout << 0;
//
//		return 0;
//	}

	if (tot)
		p = n, n -= m;

	for (int i = 1; i <= n; ++ i)
		p = p * i % mod;

	cout << p << '\n';

	return 0;
}
