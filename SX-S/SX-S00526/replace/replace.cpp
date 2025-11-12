#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define fi first
#define se second
#define endl '\n'
map<string, string> wbxl;

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//int n;
	//cin >> n;
	//cout << n + 1;
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		string a, b;
		cin >> a >> b;
		wbxl[a] = b;
	}
	for (int i = 1; i <= q; i++) {
		string a, b;
		cin >> a >> b;
		if (wbxl[a] == b)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
	return 0;
}
