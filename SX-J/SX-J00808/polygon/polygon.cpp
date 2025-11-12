#include <bits/stdc++.h>
using namespace std;
int n;
long long sum = 0;
int a[5010];

void f(int x, int k, int l, int maax, int z) {
	if (k >= 3 && z == 1) {
		if (l > maax * 2) {
			sum++;
		}
	}
	if (x == n + 1)
		return;
	f(x + 1, k + 1, l + a[x], a[x], 1);
	f(x + 1, k, l, maax, 0);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	f(1, 0, 0, 0, 0);
	long long hhh = sum % 998224353;
	int hhhh = hhh;
	cout << hhhh;
	return 0;
}
