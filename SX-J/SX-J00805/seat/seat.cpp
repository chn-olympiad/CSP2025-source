#include <bits/stdc++.h>
using namespace std;

struct {
	int cj;
	bool i = 0;
}
int a[100001];

bool cmp(s a, s b) {
	return a.cj > b.cj;
}

int main() {
	//freopen("seat.in", "r", stdin);
	//freopen("seat.out", "w", stdout);
	int n, m, rr, rcj;
	cin >> n >> m;
	int v[n][m];
	for (int i = 1; i <= n * m; i++) {
		cin >> a[1].cj;
	}
	a[1].r = 1;
	sort(a + 1, a + 1 + n *m, cmp);
	int rm = 0, rn = 0;
	for (int i = 1; i <= n * m; i++) {
		if (a[i].r == 1) {
			rr = i;
			break;
		}
	}
	int rn = rr / n, rr % n, ansn, ansm;
	if (rn % 2 == 0 && rn != 0) {
		ansm = n - rm + 1;
	} else {
		ansm =
	}
	//fclose(stdin);
	//fclose(stdout);
	return
}
