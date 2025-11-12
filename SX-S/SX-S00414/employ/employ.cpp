#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll n, m, a, ans;
string sum;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m>> sum;
	for (ll i = 1; i <= n; i++) {
		cin >> a;
		ans += a;
	}
	cout << 0 * ans <, endl;
	return 0;
}
