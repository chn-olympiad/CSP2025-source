#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long a[N], ans, n, k, s[N];
bool used[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	cin >> a[1];
	s[1] = a[1];
	for (int i = 2; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] ^ a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == k) {
			ans++;
			used[i] = 1;
		}
	}
	for (int i = 2; i <= n; i++) {
		for (int l = 1; l <= n - i + 1; l++) {
			if (used[l] == 1) {
				continue;
			}
			long long t = a[l];
			for (int j = l + 1; j <= l + i - 1; j++) {
				if (used[j] == 1) {
					t = -1;
					break;
				}
				t = t ^a[j];
				//used[j] = 1;
			}
			if (t == k) {
				ans++;
				for (int j = l + 1; j <= l + i - 1; j++) {
					used[j] = 1;
				}
			}
		}
	}
	cout << ans;
	return  0;
}
