#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e6+10;
int a[maxn], mod = 998244353, sum;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int len = s.size();
	if (q == 1) {
		cout << n;
	}
	for (int i = 1; i <= len; i++) {
		for (int j = 1; j <= n; j++) {
			sum += j * 2 + 1;
		}
	}
	cout << sum % mod;
	return 0;
}

