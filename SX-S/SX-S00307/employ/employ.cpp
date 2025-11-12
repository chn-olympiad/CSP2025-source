#include <bits/stdc++.h>
using namespace std;
int n, m, c[600], sum;
string a;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> a;
	for (int i = 0; i < n ; i++) {
		cin >> c[i];
	}
	for (int i = 1; i <= n - m + 1; i++) {
		for (int j = 1; j <= i; j++) {
			sum += j;
		}
	}
	cout << sum;
	return 0;
}
