#include <bits/stdc++.h>
using namespace std;
int n, q;
string a[100005], a1[100005], b[100005], b1[100005];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> a1[i];
	for (int i = 1; i <= q; i++)
		cin >> b[i] >> b1[i];
	for (int i = 1; i <= q; i++) {
		int ans = 0;
		for (int j = 1; j <= n; j++) {
			if (a[j] == b[i] && a1[j] == b1[i] ) {
				ans++;
			}
		}
		cout << ans << endl;
	}

	return 0;
}
