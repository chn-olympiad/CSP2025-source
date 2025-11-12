#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, j, p;
	int s[105];
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> s[i];
	}
	int sum = 0;
	for (int i = 1; i < n * m; i++) {
		if (s[i] > s[0]) {
			sum++;
		}
	}
	if (sum / n == 0) {
		j = 1;
	} else {
		j = sum / n;
	}
	p = sum % n + 1;
	cout << p << " " << j;
	return 0;
}
