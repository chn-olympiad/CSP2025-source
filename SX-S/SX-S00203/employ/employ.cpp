#include <bits/stdc++.h>
using namespace std;
int c, m, sum = 1;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> c >> m;
	if (m == 1) {
		for (int i = 2; i <= c; i++) {
			sum *= i;
		}
	}
	cout << sum;
	return 0;
}
