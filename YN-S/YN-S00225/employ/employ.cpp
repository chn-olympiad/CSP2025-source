#include <bits/stdc++.h>
using namespace std;
int m, n, c[99999999];
long long an = 1;
string x;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> x;
	int p = n;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		if (c[i] == 0)
			p--;
	}
	an = p - m + 1;
	for (int i = an + 1; i <= p; i++) {
		an = (an * i) % 998244353;
	}
	cout << an ;
	return 0;
}
