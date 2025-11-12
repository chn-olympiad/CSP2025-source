#include <bits/stdc++.h>
using namespace std;
int m, n, cnt, maxn = 0;
long long a[100000], t;

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> m >> n;
	cnt = n;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	for (int i = 2; i <= m; i++) {
		t = (a[i] ^ a[i - 1]);
		if (t > n) {
			continue;
		}
		if (t < n) {
			for (int j = i + 1; i <= m; i++) {
				if ((t ^ a[j]) < n) {
					cnt++;
					t = (t ^a[j]);
				}
				if ((t ^ a[j] ) >= n) {
					break;
				}
			}
		}
		if (cnt > maxn) {
			maxn = cnt;
		}
	}
	if (maxn < n) {
		cout << n;
		return 0;
	}
	cout << maxn;
	return 0;
}
