#include <bits/stdc++.h>
using namespace std;
int n, m, s, c[5005], num = 1;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		num *= i;
	}
	cout << num;
	return 0;
}