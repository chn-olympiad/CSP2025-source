#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll  n, m, ans, a[200025], b[200025], q, w;
string  x, y;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m ;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		for (int j = 0; j < x.size(); j++) {
			if (x[j] == 'b') {
				a[i] = j;
			}
		}
		for (int j = 0; j < y.size(); j++) {
			if (y[j] == 'b') {
				a[i] -= j;
			}
		}
	}

	for (int i = 1; i <= m; i++) {

		cin >> x >> y;
		for (int j = 0; j < x.size(); j++) {
			if (x[j] == 'b') {
				q = j;
			}
		}
		for (int j = 0; j < y.size(); j++) {
			if (y[j] == 'b') {
				q -= j;
			}
		}
		for (int i = 1; i <= n; i++) {

			if (q == a[i]) {
				ans++;
			}
		}
		cout << ans << endl;
	}

}