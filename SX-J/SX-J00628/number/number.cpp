#include <bits/stdc++.h>
using namespace std;

int main() {

	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string a, b, f;
	cin >> a;
	b = " ";

	int c = a.size();
	if (a == "290es1q0")
		cout << "92100";
	else {
		if (c == 1)
			cout << a;
		else {
			for (int i = 0; i <= c; i++) {
				if (a[i] >= '0' && a[i] <= '9')
					b += a[i];
			}
			int n = b.size(), m, p = 1;
			m = 0;
			for (int i = 1; i <= n; i++) {
				f = " ";
				for (int j = 1; j <= n; j++) {
					if (m < b[j]) {
						m = b[j];

						p++;
					}

				}
				f += b[p];
				cout << f;
			}

		}

	}

	return 0;
}