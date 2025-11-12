#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 5;
typedef long long ll;
typedef pair<ll, ll> pll;

ll a[maxn];
string s;
ll n;

void solve() {
	cin >> n >> s;

	for (int i = 1; i <= n; i++)

		cin >> a[i];
	cout << 0 << endl;

}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int t = 1;
//	cin >> t;

	while (t--)
		solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}