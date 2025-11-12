#include <bits/stdc++.h>
using namespace std;
int b[110];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> b[i];
	}
	int r = b[1];
	sort(b + 1, b + n * m + 1);
	int cnt = 0;
	for(int i = n * m; i >= 1; i--) {
		cnt++;
		if (b[i] == r) {
			break;
		}
	}
	int l = cnt % n;
	int h;
	if (l == 0) {
		l = cnt / n;
		if (l % 2 != 0) {
			h = n;
		}
		else {
			h = 1;
		}
	}
	else {
		int c = l;
		l = cnt / n + 1;
		if (l % 2 != 0) {
			h = c;
		}
		else {
			h = n + 1 - c;
		}
	}
	cout << l << " " << h;
	return 0;
}
