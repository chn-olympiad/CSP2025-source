#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 5;
typedef long long ll;
typedef pair<ll, ll> pll;

string s[maxn], t[maxn];
ll n, q;
void solve() {
	cin >> n >> q;

	for (int i = 1; i <= n; i++)

		cin >> s[i] >> t[i];

	while (q--) {
		string x, y;
		cin >> x >> y;
		cout << 0 << endl;
	}

}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int t = 1;
//	cin >> t;

	while (t--)
		solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}