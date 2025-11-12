#include <bits/stdc++.h>
using namespace std;
int b[105][105];

struct node {
	int num;
	int s;
	int biaoji = 0;
} a[1005];

bool cmp(node x, node y) {
	return x.num > y.num;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int c = n * m;
	for (int i = 0; i < c; i++) {
		cin >> a[i].num;
	}
	a[0].biaoji = 1;
	sort(a, a + c, cmp);
	for (int i = 0; i < c; i++) {
		a[i].s = i;
	}
	int hang, lie;
	hang = 0;
	lie = 0;
	for (int i = 0; i < c; i++) {
		if (hang > n || lie > m)
			break;
		else {
			if (a[i].biaoji == 1) {
				cout << lie + 1 << ' ' << hang + 1;
				return 0;
			} else {
				if ((a[i].s + 1) % n == 0) {
					lie++;
				} else {
					if ((lie + 1) % 2 == 0)
						hang--;
					else
						hang++;
				}
			}
		}
	}
	return 0;
}
