#include <bits/stdc++.h>
using namespace std;
int a[100][100];

struct PII {
	int id, sz;
} b[10009];

bool cmp(PII p1, PII p2) {
	return p1.sz > p2.sz;
}

int main() {
	//freopen("seat.in", "r", stdin);
	//freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> b[i].sz;
	}
	b[1].id = 1;
	int t = n * m;
	int h = 0;
	sort(b + 1, b + t + 1, cmp);
	for (int j = 1; j <= m; j++) {
		if (j % 2 == 1) {
			for (int i = 1; i <= n; i++) {
				h++;
				if (b[h].id == 1) {
					cout << j << " " << i;
					return 0;
				}
			}
		} else {
			for (int i = n; i >= 1; i--) {
				h++;
				if (b[h].id == 1) {
					cout << j << " " << i;
					return 0;
				}
			}
		}
	}
	return 0;
}
