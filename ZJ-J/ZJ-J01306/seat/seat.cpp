// T2 seat
#include <bits/stdc++.h>
using namespace std;
int n, m, w;
struct node {
	int s, id;
} a[110];
bool cmp(node p, node q) {
	return p.s > q.s;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i].s;
		a[i].id = i;
	}
	sort(a + 1, a + 1 + n * m, cmp);
	for (int i = 1; i <= n * m; i++) 
		if (a[i].id == 1) w = i;
	int x = 0;
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= n; j++) {
				x++;
				if (x == w) {
					cout << i << ' ' << j;
					return 0;
				}
			}
		} else {
			for (int j = n; j >= 1; j--) {
				x++;
				if (x == w) {
					cout << i << ' ' << j;
					return 0;
				}
			}
		}
	}
	return 0; 
}