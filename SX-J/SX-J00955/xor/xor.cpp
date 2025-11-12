#include <bits/stdc++.h>
using namespace std;
int a[1009];

bool b[1009];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int z = 1; z <= n; z++) {
		if (a[z] == m) {
			b[z] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int zbc = a[i];
			bool t = 1;
			if (i == j && a[i] == m) {
				b[i] = 1;

			}
			for (int z = i + 1; z <= j; z++) {

				zbc = zbc ^a[z];
				if (b[z])
					t = 0;
			}
			if (zbc == m && t) {
				//cout << i << " " << j << '\n';
				ans++;
				for (int z  = i; z <= j; z++) {
					b[z] = 1;
				}
			}

		}
	}
	cout << ans;
}
