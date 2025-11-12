#include <bits/stdc++.h>
using namespace std;
string a[100010], b[100010];

int main() {
	//freopen("replace.in","r",stdin);
	//freopen("replace.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= t; i++) {
		memset(b, 0, sizeof b);
		memset(m, 0, sizeof m);
		int n;
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j] >> a[2][j] >> a[3][j];
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= 3; k++) {
					if (b[k] < n / 2) {
						m[n * k + 1] += a[k][j];
						b[k]++;
					}
				}
			}
		}
	}
	return 0;
}
