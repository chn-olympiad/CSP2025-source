#include <bits/stdc++.h>
using namespace std;

struct peo {
	int chengji;
	int Rtag;
} a[105];
int b[15][15];

bool cmp(peo c, peo d) {
	return c.chengji > d.chengji;
}

int main() {
	//单数从上往下，双数从下往上
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int len = n * m;
	for (int i = 1; i <= len; i++) {
		cin >> a[i].chengji;
	}
	a[1].Rtag = 1;
	int rn = 1;
	sort(a + 1, a + len + 1, cmp);
	for (int i = 1; i <= len; i++) {
		if (a[i].Rtag == 1) {
			rn = i;
			break;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if ((i + 1) % 2 == 0) {
				b[j][i] = n * i + n - j;
			} else {
				b[j][i] = n * i + j + 1;
			}
		}
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << b[i][j] << " ";
		}
		cout << endl;
	}*/
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (b[i][j] == rn) {
				cout << j + 1 << " " << i + 1;
			}
		}
	}
	//cout << x << " " << y;
	return 0;
}