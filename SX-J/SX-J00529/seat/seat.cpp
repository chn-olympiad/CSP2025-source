#include <bits/stdc++.h>
using namespace std;
int n, m;

struct Node {
	int fen, hao;
} a[200];

bool cmp(Node xx, Node xy) {
	return (xx.fen > xy.fen);
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int t = m * n;
	for (int i = 1; i <= t; i++) {
		cin >> a[i].fen;
		a[i].hao = i;
	}
	sort(a + 1, a + 1 + t, cmp);
	for (int i = 1; i <= t; i++) {
		if (a[i].hao == 1) {
			if (i % n == 0) {
				if ((i / n) % 2 != 0)
					cout << i / n << " " << n;
				else
					cout << i / n << " " << 1;
				break;
			}
			int y = i / n + 1;
			if (y % 2 != 0) {
				cout << y << " " << (i - (y - 1)*n);
				break;
			} else {
				cout << y << " " << n + 1 - (i - (y - 1)*n);
				break;
			}
		}
	}
	return 0;
}
