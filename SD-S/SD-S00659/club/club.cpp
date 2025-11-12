# include <bits/stdc++.h>
# define ll long long

using namespace std;

const ll N = 1e5 + 5;
const ll M = 205;
ll t, n, ans;
ll A[5][N];
bool flagA;

void dfs (ll now, ll suma, ll sumb, ll sumc, ll sum) {
	if (now == n + 1) {
		ans = max (ans, sum);
		return ;
	}
	if (suma < n / 2)
		dfs (now + 1, suma + 1, sumb, sumc, sum + A[1][now]);
	if (sumb < n / 2)
		dfs (now + 1, suma, sumb + 1, sumc, sum + A[2][now]);
	if (sumc < n / 2)
		dfs (now + 1, suma, sumb, sumc + 1, sum + A[3][now]);
}

int main () {

	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
    ios::sync_with_stdio (0);
    cin.tie (0), cout.tie (0);
	cin >> t;
	while (t --) {
		ans = 0, flagA = 1;
		cin >> n;
		for (ll i = 1; i <= n; i ++) {
			cin >> A[1][i] >> A[2][i] >> A[3][i];
			if (A[2][i] || A[3][i]) flagA = 0;
		}
		if (flagA) {
			sort (A[1] + 1, A[1] + n + 1);
			for (ll i = 1; i <= n / 2; i ++) ans += A[1][i];
			cout << ans << "\n";
		} else if (n <= 10) {
			dfs (1, 0, 0, 0, 0);
			cout << ans << "\n";
		} else {
			for (ll i = 1; i <= n; i ++) 
				ans += max (A[1][i], max (A[2][i], A[3][i]));
			cout << ans << "\n";
		}
	}

	return 0;
}
// 35
