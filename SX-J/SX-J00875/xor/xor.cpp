#include <bits/stdc++.h>
using namespace std;
int n, m, a[500500], f[505000], f1[505000];
long long a1[505000], a2[505000], ans, anss;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		a1[i] = a1[i - 1] + a[i];
	}
	a2[1] = a[1];
	for (int i = 2; i <= n; i++) {
		a2[i] = a2[i - 1] ^ a[i];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if ((a2[j]^a2[i]) == m ) {
				if (f1[i + 1] != 1 && f1[j] != 1) {
					anss++;
					for (int k = i + 1; k <= j; k++)
						f1[k] = 1;
				} else
					break;
			}
		}
	}
	for (int i = 0; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (a1[j] - a1[i] == m ) {
				if (f1[i + 1] != 1 && f1[j] != 1) {
					anss++;
					for (int k = i + 1; k <= j; k++)
						f1[k] = 1;
				} else
					break;
			}
		}
	}
	cout << anss ;
	return 0;
}
