#include <bits/stdc++.h>
using namespace std;
int n, k, a[500001], book[500001], cnt;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int l = 1; l <= n; l++) {
		for (int i = 1; i <= n; i++) {
			if (book[i] == 1)
				continue;
			int p = l;
			if ((p + i) > n)
				continue;
			int f = 0;
			for (int j = i; j <= p + i; j++) {
				if (book[j] == 1) {
					f = 1;
				}
			}
			if (f == 1)
				continue;
			int t = 0, c;
			while (p--) {
				t = t ^a[i];
				c++;
				if (t == k) {
					cnt++;
					for (int j = i; j <= i + c; j++) {
						book[i] = 1;
					}
					break;
				}
			}
		}
	}
	cout << cnt;
	return 0;
}