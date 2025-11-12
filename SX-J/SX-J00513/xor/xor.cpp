#include <bits/stdc++.h>
using namespace std;
int n, k, x;
map<int, int> mp;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "r", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> mp[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int ans = mp[i];
			for (int a = i + 1; a <= j; a++) {
				ans = ans ^mp[a];
			}
			if (ans == k) {
				x++;
				for (int a = i; a <= j; a++) {
					mp[a] = 1e9;
				}
			}
		}
	}
	cout << x;
	return 0;
}
