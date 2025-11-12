#include <bits/stdc++.h>
using namespace std;

struct node {
	int g;
} s[105];

bool cmp(node a, node b) {
	return a.g > b.g;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	cin >> s[1].g;
	int tp = s[1].g;
	for (int i = 2; i <= n * m ; i++) {
		cin >> s[i].g;
	}
	sort(s + 1, s + n *m + 1, cmp);
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		if (i % 2 != 0) {
			for (int j = 1; j <= n; j++) {
				cnt++;
				if (s[cnt].g == tp) {
					cout << i << " " << j;
					break;
				}
			}
		} else {
			for (int j = n; j >= 1; j--) {
				cnt++;
				if (s[cnt].g == tp) {
					cout << i << " " << j;
					break;
				}
			}
		}
	}
	return 0;
}
