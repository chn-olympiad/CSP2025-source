#include <bits/stdc++.h>
using namespace std;
const int N = 998244353;
int a, b, d[500], z, e, f;
string c;

int main() {
	freopen("employ.out", "r", stdin);
	freopen("employ.in", "w", stdout);
	cin >> a >> b;
	cin >> c;
	for (int i = 1; i <= a; i++) {
		cin >> d[i];
		if (d[i] <= 0) {
			z++;
		}
	}
	for (int i = 0; i < a; i++) {
		if (c[i] == '1') {
			e++;
		} else {
			f++;
		}
	}
	cout << e;
	return 0;
}
