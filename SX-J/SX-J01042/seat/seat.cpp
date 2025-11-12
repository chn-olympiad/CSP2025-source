#include <bits/stdc++.h>
using namespace std;
int n, m;
int s[105];
int c = 0, t = 1;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> s[i];
	}
	int a = s[0];
	sort(s, s + n *m, cmp);
	for (int i = 0; i < n * m; i++) {
		if (s[i] != a) {
			if (c + 1 > n && t + 1 % 2 == 0) {
				c = n;
				t++;
			} else {
				if (c < n && t + 1 % 2 != 0)
					c++;
				else if (c < n && t % 2 == 0)
					c--;
			}
		} else {
			if (c + 1 > n && t % 2 != 0) {
				c = n;
				t++;
			} else {
				if (c < n && t % 2 != 0)
					c++;
				else if (c < n && t % 2 == 0)
					c--;
			}
			cout << t << " " << c;
		}

	}
	return 0;
}
