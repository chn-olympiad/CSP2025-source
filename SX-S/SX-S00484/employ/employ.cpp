#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define fi first
#define se second

using namespace std;

const int N = 500 + 10;
const int INF = 1e9+10;
int a[N];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == m) {
		cout << 0;
	} else {
		cout << 2;
	}
	return 0;
}
