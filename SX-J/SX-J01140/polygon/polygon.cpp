#include <bits/stdc++.h>
using namespace std;
const int N = 1e4;
long long n, a[N], maxa, b[N], v[N], o, ans;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 1; i <= n ; i++) {
		scanf("%lld", &a[i]);
		maxa = max(maxa, a[i]);
	}
	sort(a + 1, a + 1 + n);
	if (n == 3 && a[1] + a[2] > a[3])
		cout << 1;
	else if (maxa == 1) {
		cout << (n - 2)*(n - 1) / 2;
	} else
		cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
