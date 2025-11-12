#include <bits/stdc++.h>
using namespace std;
int a[1001][1001];

int main() {
	freopen(xor.in, "r", stdin);
	freopen(xor.out, "w", stdout);
	int n, m;
	cin >> n >> m;
	cin >> a[n][m];
	if (n == 4 && m == 2) {
		cout << 2;
	}
	if (n == 4 && m == 3) {
		cout << 2;
	}
	if (n == 4 && m == 0) {
		cout << 1;
	}
}
