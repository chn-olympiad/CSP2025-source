//Luogu 743373-Vitamin_B:)
//ZJ-J01631
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

const int mod = 998244353;

int n, a[5005], dp[5005], all[5005], sum;

void init () {

	all[0] = 1;

	for (int i = 1; i <= 5000; ++ i)
		all[i] = all[i - 1] * 2 % mod;

	return ;
}

int main () {
//	freopen ("polygon1.in", "r", stdin);
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);

	init ();

	cin >> n;

	for (int i = 1; i <= n; ++ i)
		cin >> a[i];

//	dp[0] = 1;

	for (int i = 1; i <= n; ++ i) {

		for (int j = 5000; j >= a[i]; -- j)
			dp[j] += dp[j - a[i]] + 1;

		if (1 < i && i < n)
			sum = (sum + all[i] - dp[a[i + 1]] - 1) % mod;
//		cerr << i << ':' << sum << '=' << all[i - 1] << '-' << dp[3] << '\n';
	}

	cout << (sum + mod) % mod;

	return 0;
}
