#include <bits/stdc++.h>
using namespace std;
int s[500005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	int cnt = 0;
	for (int l = 1, r = 1; l <= r && r <= n; r++) {
		if (l == r) {
			if (s[l] == k) {
				l++;
				cnt++;
			}
		} else {
			int h = 0;
			for (int i = l; i <= r; i++) {
				h += s[i];
			}
			if (h == k) {
				cnt++;
				l = r + 1;
				r = l;
			}
		}
	}
	cout << cnt;
	return 0;
}
