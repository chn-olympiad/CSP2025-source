#include <bits/stdc++.h>
using namespace std;
int n, m;

struct rEN {
	int id;
	int fen;
} a[120];

bool cmp(rEN c, rEN b) {
	return c.fen > b.fen;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i].fen;
		a[i].id = i;
	}
	sort(a + 1, a + n *m, cmp);
	int xx = 1, yy = 1;
	if (a[1].id == 1) {
		cout << 1 << " " << 1;
		return 0;
	}
	bool f = 0;
	for (int i = 2; i <= n * m; i++) {
		if (i == 2) {
			yy++;
		} else if (yy == 1 && f) {
			f = 0;
			xx++;
		} else if (yy == n && !f) {
			xx++;
			f = 1;
		} else if (f == 0) {
			yy++;
		} else if (f == 1) {
			yy--;
		}
//		cout << xx << " " << yy << endl;
		if (a[i].id == 1) {
			cout << xx << " " << yy << endl;
		}


	}
	return 0;
}




