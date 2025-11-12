#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int n2 = n * m;
	int a[n2];
	for (int i = 1; i <= n2; i++)
		cin >> a[i];
	int t = a[1];
	sort(a + 1, a + n2 + 1, cmp);
	if (t == a[1]) {
		cout << "1 1";
		return 0;
	}
	if (t == a[n2]) {
		cout << m << " ";
		if (m % 2 == 0)
			cout << 1;
		else
			cout << n;
		return 0;
	}
	int u = 1;
	int e = 1;
	for (int i = 1; i <= n2; i++) {
		if (u == n + 1) {
			e++;
			u = 1;
		}
		if (e % 2 == 1) {
			if (t == a[i]) {
				if (i % n == 0)
					cout << e << " " << n;
				else
					cout << e << " " << i % n;
				return 0;
			}
		} else {
			if (t == a[i]) {
				if (i % n == 0)
					cout << e << " 1";
				else if (i % n == 1)
					cout << e << " " << n;
				else
					cout << e << " " << n - i % n + 1;
				return 0;
			}
		}
		u++;
	}
	return 0;
}
