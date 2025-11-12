#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
char a[100000005], b[100000005], c, d;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> n >> m;
	cin >> c >> d;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (c[i] == a[j])
				ans++;
			c[i] = a[j];
		}
	}
	cout << ans;
	return 0;
}

