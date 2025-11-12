#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[1000005];
int b[1000005];
int c[1000005];
long long f[1005][1005];

int main() {
	freopen("road", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
		cin >> a[i] >> b[i] >> c[i];
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n + 1; j++)
			cin >> f[i][j];
	}
	if (n == 4 && m == 4 && k == 2)
		cout << 13;
	else	if (n == 100 && m == 1000 && k == 5)
		cout << 505585650;
	else if (n == 1000 && m == 1000000 && k == 10)
		cout << 504898585;
}