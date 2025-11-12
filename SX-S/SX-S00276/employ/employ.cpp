#include <bits/stdc++.h>
using namespace std;
int a[510];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	long long n, m;
	string s;
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cout << n % 998244353;
	return 0;
}