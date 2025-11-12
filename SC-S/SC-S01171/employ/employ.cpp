#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

ll n, m, s[505], c[505];

const ll MOD = 998244353;

bool All_easy = true;

int main () {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i ++) {
		cin >> s[i];
		if (s[i] == 0) All_easy = 0;
	}
	
	for (int i = 1; i <= n; i ++) {
		cin >> c[i];
	}
	
	if (All_easy) {
		ll ans = 1;
		for (int i = 1; i <= n; i ++) {
			ans *= i;
			ans %= MOD;
		}
		cout << ans;
	}
	return 0;
}
