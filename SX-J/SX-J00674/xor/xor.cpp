#include <bits/stdc++.h>
using namespace std;
int a[100005];

int main() {
	freopen("xor.in", "r", "stdin");
	freopen("xor.out", "w", "stdout");
	int n, k, ans = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == k)
			ans++;
	}
	int t = a[1];
	for (int i = 1; i <= n; i++) {
		t = a[i];
		for (int j = i; j <= n; j++) {
			if ((t ^ a[j]) == 2) {
				ans++;
			} else {
				t += a[j];
			}
		}
	}
	cout << ans;
	return 0;
}