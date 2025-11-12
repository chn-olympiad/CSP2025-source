#include <bits/stdc++.h>
using namespace std;
long long n, m, tot = 1;
const int X = 998244353;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		tot *= i;
		tot %= X;
	}
	cout << tot;
	return 0;
}
