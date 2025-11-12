#include <bits/stdc++.h>
using namespace std;
#define int long long
int w[10005];

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, k, sum = 0;
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
	}
	int ccc = 1;
	for (int i = 1; i <= n; i++) {
		ccc *= i;
	}
	cout << ccc;
	return 0;
}