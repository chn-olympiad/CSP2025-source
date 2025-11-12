#include <bits/stdc++.h>
using namespace std;
int temp[1005];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> temp[i];
	}
	int b = temp[1];
	sort(temp + 1, temp + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (temp[i] == b) {
			b = i;
			break;
		}
	}
	if (b % m == 0) {
		if ((b / m) % 2 == 0) {
			cout << b / m << " " << 1;
		} else {
			cout << b / m << " " << m;
		}
	} else {
		if ((b / m) % 2 == 0) {
			cout << b / m + 1 << " " << b % m;
		} else {
			cout << b / m + 1  << " " << m - b % m + 1;
		}
	}
	return 0;
}
