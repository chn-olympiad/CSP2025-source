#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
long long n, t;
int f[N];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int j = 1; j <= t; j++) {
		cin >> n;
		long long  b, c, s = 0;
		for (int i = 1; i <= n; i++) {

			cin >> f[i] >> b >> c;
		}
		sort(f + 1, f + n + 1);
		for (int i = n; i > n / 2; i--) {
			s = s + f[i];
		}
		cout << s;
	}
	return 0;
}
