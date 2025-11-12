#include <bits/stdc++.h>
using namespace std;
int a[500005], n, r;
bool vis[500005];

int xsum(int bl, int er) {
	int rans = a[bl] ^ a[bl + 1];
	for (int i = bl + 1; i <= er; i++) {
		rans = rans ^a[i];
	}
	return rans;
}


int main() {
	freopen("xor.in ", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> r;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n <= 2) {
		cout << n;
		return 0;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!vis[i] && !vis[j] && xsum(i, j)) {
				ans++;
				vis[i] = vis[j] = true;
			}
		}
	}
	cout << ans;
	return 0;
}
