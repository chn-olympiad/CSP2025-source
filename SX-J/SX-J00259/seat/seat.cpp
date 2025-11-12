#include <bits/stdc++.h>
using namespace std;
int a[1005];
int cnt = 0;

//394TYWZ
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int m, n;
//nĞĞmÁĞ
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if (i > 1) {
			if (a[i] > a[1]) {
				cnt++;
			}
		}
	}
	int x = 0;
	int s = cnt / n;
	int b = cnt % n;
	if (s % 2 == 0) {
		x = b + 1;
	} else {
		x = n - b;
	}
	cout << s + 1 << " " << x;
	return 0;
}