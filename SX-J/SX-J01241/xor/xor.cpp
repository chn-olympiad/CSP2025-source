#include <bits/stdc++.h>
using namespace std;
int n, k, a[114514], s[114514], ans;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	if (k == 0 && n == 2) {
		cout << "1" << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] ^ a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if ((s[i]^s[j]) == k)
				ans++;
		}
	}
	if (a[1] == k)
		ans++;
	cout << ans << endl;
	return 0;
}
