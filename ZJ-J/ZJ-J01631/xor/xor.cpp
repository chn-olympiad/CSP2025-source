//Luogu 743373-Vitamin_B:)
//ZJ-J01631
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

int n, k, a[500005], lst[2000005], dp[500005];

int main () {
//	freopen ("xor6.in", "r", stdin);
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);

	cin >> n >> k;

	for (int i = 1; i < 1 << 20; ++ i) lst[i] = n + 1;
	dp[n + 1] = -1;

	for (int i = 1; i <= n; ++ i) {

		cin >> a[i], a[i] ^= a[i - 1];

		dp[i] = max (dp[i - 1], dp[lst[a[i] ^ k]] + 1);
//		cerr << '\n' << i << ':' << a[i] << ':' << lst[a[i] ^ k] << '=' << dp[lst[a[i] ^ k]] << "->" << dp[i] << '\n';
		lst[a[i]] = i;

	}

	cout << dp[n];

	return 0;
}
/*
4 0
2 1 0 3
*/
