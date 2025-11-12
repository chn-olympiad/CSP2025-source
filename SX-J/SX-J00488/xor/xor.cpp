#include <bits/stdc++.h>
using namespace std;
int n, k, ans = 0, a[500005];

int main() {
	freopen("xor.in", "r", std.in);
	freopen("xor.out", "w", std.out);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int s = 0x3f, j = 1;
	while (1) {
		if (a[j] == k) {
			ans++;
			s = 0x3f;
		} else if (s == 0x3f) {
			s = a[j];
		} else {
			if ((s ^ a[j]) == k) {
				ans++;
				s = 0x3f;
			} else {
				s = s ^a[j];
			}
		}
		j++;
		if (j > n) {
			break;
		}
	}
	cout << ans;
	return 0;
}
