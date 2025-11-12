#include <bits/stdc++.h>
using namespace std;
struct node {
	int x, y;
} s[105];
bool cmp(node a, node b) {
	return a.x > b.x;
}
int n, m;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> s[i].x;
		s[i].y = i;
	}
	sort (s + 1, s + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (s[i].y == 1) {
			int tx, ty;
			tx = ceil(double(i) / n);
			if (tx % 2 == 0) {
				ty = (n - i % n) + 1;
			} else {
				ty = i % n;
				if (ty == 0) ty = n;
			}
			cout << tx << " " << ty;
			return 0;
		}
	}
	return 0;
}
