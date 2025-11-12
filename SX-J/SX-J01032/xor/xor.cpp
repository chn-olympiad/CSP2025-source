#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long a[500005];
long long ans;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		if (a[i] == k) {
			ans++;
			continue;
		}
		int t = a[i];
		for (int j = i + 1; j <= n; j++) {
			if (t == a[j])
				t = 0;
			else
				t = 1;
			if (t == k) {
				ans++;
				i = j;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}