#include <bits/stdc++.h>
using namespace std;
int s[110];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int ans = n * m;
	for (int i = 1; i <= ans; i++) {
		cin >> s[i];
	}
	int num = s[1], w;
	sort(s + 1, s + 1 + ans, cmp);
	for (int i = 1; i <= ans; i++) {
		if (s[i] == num) {
			w = i;
			break;
		}
	}
	int c = w / n, r = w % n;
	if (r != 0) {
		c = c + 1;
	}
	if (c % 2 == 1) {
		if (r == 0) {
			r = n;
		}
		cout << c << " " << r;
	} else {
		cout << c << " " << n - r + 1;
	}
	return 0;
}
