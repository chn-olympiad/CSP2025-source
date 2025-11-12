#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 998244353;
ll n, m, c[510];
string s;
ll ans;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	ans = 1;
	for (int i = 1; i <= n; i++) {
		ans = ans * i % mod;
	}
	cout << ans << endl;
	return 0;
}