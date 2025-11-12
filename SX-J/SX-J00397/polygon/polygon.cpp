#include <bits/stdc++.h>
using namespace std;
int a[10005], b[10005], c[5005];
bool f[10005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		memset(f, 0, sizeof(f));
		for (int j = 5000; j >= 1; j--) {
			if (j >= a[i]) {
				if (b[j - a[i]] + a[i] <= b[j]) {
					c[b[j]]++;
				}
				if (b[j - a[i]] + a[i] >= b[j]) {
					c[b[j - a[i]] + a[i] ] += c[b[j - a[i]]] ;
					b[j] = b[j - a[i]] + a[i];
					if (b[j] > 2 * a[i] && !f[b[j]]) {
						sum = (sum + 1) % 998244353;
						f[b[j]] = 1;
					}
				}
			}
		}
	}
	cout << sum;
	return 0;
}