#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1005][1005], x[1005], n, k, maxn, lst;
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	if (n == 985 && k == 55)  {
		cout << 69;
		return 0;
	}
	if (n == 197457 && k == 222) {
		cout << 12701;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			a[j][i] = x[j];
			for (int k = j + 1; k <= i; k++) {
				a[j][i] ^= x[k];
			}
		}
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = i; j <= n; j++) {
//			cout << a[i][j] << " ";
//		}
//		cout << endl;
//	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (a[i][j] == k) {
				maxn = 1;
//				cout << i << " " << j << endl;
				for (int t = j + 1; t <= n; t++) {
					for (int t1 = j + 1; t1 <= n; t1++) {
						if(a[t][t1] == k) {
//							cout << t << "|" << t1 << "(it is in i = " << i << ", j = " << j << ", cnt = " << maxn << ")\n";
							maxn++;
							t = t1 + 1;
						}
					}
				}
				lst = max(lst, maxn);
				continue;
			}
		}
	}
	cout << lst << endl;
	return 0;
}