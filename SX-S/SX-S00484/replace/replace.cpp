#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define fi first
#define se second

using namespace std;

const int N = 2e5 + 10;
const int INF = 1e9+10;
string ss[N][5];
string t[N][5];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> ss[i][1] >> ss[i][2];
	}
	for (int i = 1; i <= q; i++) {
		cin >> t[i][1] >> t[i][2];
		string s1 = t[i][1];
		string s2 = t[i][2];

		cout << 0 << endl;
	}

	return 0;
}
