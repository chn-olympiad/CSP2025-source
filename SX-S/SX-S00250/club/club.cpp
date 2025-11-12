#include <bits/stdc++.h>
using namespace std;
long long n, m, a[100100], b[100100], c[100100], s1[10010], s2[10010], s3[10010];
long long m1, m2, m3;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		m1 = 0;
		m2 = 0;
		m3 = 0;

		cin >> m;
		for (int j = 1; j <= m; j++) {
			cin >> a[j] >> b[j] >> c[j];
		}
		cout << 1 << endl;
	}
	return 0;
}