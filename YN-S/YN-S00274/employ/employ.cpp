#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	long long s = 1;
	cin >> n >> m;
	for (int i = n; i > 1; i--)
		s = s * i % 998244353;
	cout << s;
	return 0;
}