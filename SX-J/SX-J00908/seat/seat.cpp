#include <bits/stdc++.h>
using namespace std;
int s[105];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	cin >> s[0];
	int a = s[0];
	for (int i = 1; i <= n * m - 1; i++) {
		cin >> s[i];
	}
	bool f = 1;
	int c = 1, r = 1;
	sort(s, s + n *m, cmp);
	int i = 0;
	while (a != s[i]) {
		if (f) {
			if (r + 1 <= n)
				r += 1;
			else {
				c += 1;
				r = n;
				f = 0;
			}
		} else {
			if (r - 1 >= 1)
				r -= 1;
			else {
				c += 1;
				r = 1;
				f = 1;
			}
		}
		i++;
	}
	cout << c << " " << r;
	return 0;
}
