#include <bits/stdc++.h>
using namespace std;
int n, q;
string a[2][10000][20000];
string b[2][10000][20000];
int longa[20000];
int longb[20000];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 0; i <= n; i++) {
		cin >> a[1][][n];
		longa[i] = strlen(a[1][][n]);
		cin >> a[2][][n];
		longa[i] = strlen(a[2][][n]);
	}
	for (int i = 0; i <= q; i++) {
		cin >> b[1][][n];
		longa[i] = strlen(b[1][][n]);
		cin >> b[2][][n];
		longa[i] = strlen(b[2][][n]);
	}
	for (int i = 0; i <= n; i++) {
		bool flag = 1;
		int z = longa[n];
		for (int j = 0; j <= longa[n]; j++)
			while (z != 0) {
				if (a[1][j][i] != b[1][j][i]) {
					flag = 0;
				}
			}
	}
	return 0;
}