#include <bits/stdc++.h>
using namespace std;
int n, k;
int h[500010];
int jp[500010];
int d = 1;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
		if (h[i] == k) {
			jp[d] = i;
			d++;
		}
	}
	jp[d] = n + 1;
	for (int i = 1; i <= d; i++) {
		int b = 0;
		for (int j = jp[i - 1] + 1; j < jp[i]; j++) {
			int z = 0;
			int s = 0;
			for (int o = j; o < jp[i]; o++) {
				z = z ^h[o];
				if (z == k) {
					s++;
					z = 0;
				}
			}
			b = max(b, s);
		}
		d += b;
	}
	cout << d - 1 ;
}