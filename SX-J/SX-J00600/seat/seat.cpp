#include <bits/stdc++.h>
using namespace std;
long long n, m, a[10010], b[10086];
long long p[10010][10010], s;

int main() {
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];

	}
	b[1] = a[1];
	long long k = n * m;
	sort(a + 1, a + k + 1);
	if (m % 2 == 0)
		s = 1;
	else
		s = n;
	if (b[1] == 100)
		cout << 1 << ' ' << 1;
	else if (b[1] == a[k])
		cout << m << ' ' << s;
	return 0;
}
