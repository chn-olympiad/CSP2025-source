#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int P = 998244353;
int n, m;

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	int sum = 1;
	for (int i = 2; i <= n; i++) {
		sum *= i;
		sum %= P;
	}
	cout << sum;
	return 0;
}
