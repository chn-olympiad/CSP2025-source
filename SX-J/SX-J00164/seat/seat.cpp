#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct seat {
	int x, y, id, f;
};
seat st[100000];

bool cmp(seat x, seat y) {
	return x.f > y.f;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> st[i].f;
		st[i].id = i;
	}
	sort(st + 1, st + (n *m) + 1, cmp);
	int cnt = 0;
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			cnt++;
			st[cnt].x = i;
			st[cnt].y = j;
		}
	}
	for (int i = 1; i <= n * m; i++) {
		if (st[i].id == 1) {
			cout << st[i].y << " " << st[i].x;
			return 0;
		}
	}
}