#include <bits/stdc++.h>
using namespace std;
long long t;

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdin);
	cin >> t;
	int n;

	while (t--) {
		long long n;
		long long a[10005][3];
		cin >> n;

		for (int i = 1; i <= n; i++) {

			int m, b, c;
			cin >> m >> b >> c;
			int m[a], n[b], t[c];
			cin >> m[a] >> n[b] >> t[c];

		}

		for (int i = 1; i <= n; i++) {

			int m, b, c;
			cin >> m >> b >> c;
			int m[a], n[b], t[c];
			cin >> m[a] >> n[b] >> t[c];

			m[a] = n[b];
			n[b] = t[c];
			t[c] = m[a];
		}

		cout << n << endl;

	}





	return 0;
}
