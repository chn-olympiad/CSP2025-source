#include <bits/stdc++.h>
using namespace std;

int main() {
	string a, m;
	long long  j = 0, i = 0, n = 0, p = 0;
	char q;
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	i = lengthy.a;
	for (p = 0; p <= i; i++) {
		if (a[i] >= '1' && a[i] <= '9') {
			m += a[i];
			j++;
		}
	}
	i = 1;
	while (true) {
		for (p = 1; p <= j; p++) {
			i++;
			if (m[p] > m[p - 1]) {
				q = m[p];
				m[p] = m[p - 1];
				m[i - 1] = q;
				n++;
			}
		}
		if (n == 1) {
			break;
		} else {
			n = 1;
		}
	}
	for (p = 0; p <= i; p++) {
		cout << m[p];
	}
	cout << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
