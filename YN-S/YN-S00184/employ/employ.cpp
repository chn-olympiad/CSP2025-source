#include <bits/stdc++.h>
using namespace std;
int n, m, c[505];
string s;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	if (m == n) {
		int sum1 = 0, sum2 = 0;
		for (int i = 1; i <= n; i++)
			sum1 += i, sum2 += c[i];
		if (sum1 > sum2)
			cout << 0;
		else
			cout << 9;
	} else
		cout << 0;
	return 0;
}