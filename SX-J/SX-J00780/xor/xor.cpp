#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+10;
int n, k, a[N], cnt, ans;
int b[N];
bool flag[N];

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int x = a[i];
		if (x == k) {
			b[i] = i;
			cnt++;
			continue;
		}
		for (int j = i + 1; j <= n; j++) {
			x ^= a[j];
			if (x == k) {
				b[i] = j;
				i = j;
				cnt++;
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}