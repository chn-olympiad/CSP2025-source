#include <bits/stdc++.h>
using namespace std;
int a[10000000];

int main() {
	int n, k, s = 0, maxv = -1;
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > maxv) {
			maxv = a[i] ;
			k = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j and a[i] + a[j] > maxv and i != k and j != k) {
				cout << 1;
				return 0;
			}
		}
	}
	cout << s;
	return 0;
}