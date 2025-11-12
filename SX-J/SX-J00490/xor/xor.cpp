#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int a[N], m[N], c[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, maxx = INT_MIN;
	cin >> n >> k;
	int v = 0, b = 0, f;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == k) {
			b++;
			c[b] = i;
			v++;
			m[v] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		int s = a[i];
		for (int j = i + 1; j <= n; j++) {
			f = 0;
			s = s ^a[j];
			if (s == k ) {
				for (int r = 1; r <= b; r++) {
					if (i > c[b] || j < c[b]) {
						f++;
					}
				}
				if (f == b) {
					v++;
					m[v] = j - i;
				}
			}
		}
	}
	for (int i = 1; i <= v; i++) {
		maxx = max(maxx, m[i]);
	}
	cout << maxx;
	return 0;
}