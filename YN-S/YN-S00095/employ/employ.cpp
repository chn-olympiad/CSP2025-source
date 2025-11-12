#include <bits/stdc++.h>
using namespace std;
string s;
int a[600];

int dg(int n) {
	if (n != 0)
		return n * dg(n - 1);
	else
		return 1;
}

int main() {

	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, p = 0;
	cin >> n;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i])
			p++;
	}
	if (p == n) {
		cout << dg(n);
		exit(0);
	}


	return 0;
}
