#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll arr[10000086];
bool b, c;

int main() {

	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (arr[i] != 1) {
			b = 1;
		}
		if (arr[i] != 0 && arr[i] != 1)
			c = 1;
	}
	if (b == 0) {
		if (k == 1)
			cout << n;
		else if (k == 0)
			cout << n / 2;
		else
			cout << 0;
		return 0;
	}
	if (c == 0) {
		if (k == 0) {
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				if (arr[i] == 0)
					ans++;
				else if (arr[i - 1] == 1)
					ans++, arr[i] = 0;
			}
			cout << ans;
		} else {
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				if (arr[i] == 1)
					ans++;
			}
			cout << ans;
		}
		return 0;
	}
	int tot = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		if (arr[i] == k) {
			tot++, ans = 0;
			continue;
		}
		if (ans != 0) {
			ans ^= arr[i];
			if (ans == k) {
				tot++, ans = 0;
				continue;
			}
		} else {
			ans = arr[i];
		}
	}
	cout << tot;
	return 0;
}
