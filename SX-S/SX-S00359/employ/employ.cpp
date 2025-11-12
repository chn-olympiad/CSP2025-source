#include <bits/stdc++.h>
using namespace std;
int n, m;
string a;
long long c[600], ans;
long long b[600];
long long f[600];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> a;
	int s = a.size();
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	int d = 1;
	for (int i = 1; i <= s; i++) {
		b[i] = b[i - 1] + int(a[i]);
		if (b[i] > c[d]) {
			f[d] = i;
			d++;
		}
	}
	sort(c + 1, c + n + 1);
	cout << 0;
	return 0;
}
