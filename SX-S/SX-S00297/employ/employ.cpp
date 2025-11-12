#include <bits/stdc++.h>
using namespace std;
int c[1000010], t[1000010];
bool l[1000010];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	long long n, m, x = 1;
	string a;
	cin >> n >> m >> a;
	for (int i = 0; i < n; i++) {
		t[i] = a[i] - '0';
		cin >> c[i];
	}
	for (int i = 0; i < n; i++) {
		if (c[i] == 0) {
			n--;
		}
	}
	for (int i = 0; i < n; i++) {
		x = x * (n - i) % 998244353;
	}
	cout << x % 998244353;
	return 0;
}