#include <bits/stdc++.h>
using namespace std;
int m, n;
int a[10005], a1;

bool cmp(int x, int y) {
	return x > y;
}

//列为奇数行++;
//列为偶数行--
int main() {

	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	cin >> n >> m >> a1;
	for (int i = 1; i <= m * n - 1; i++) {
		cin >> a[i];
	}
	a[n * m + 1] = a1;
	sort(a + 1, a + m *n + 2, cmp);
	int indx;
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == a1) {
			indx = i;
			break;
		}
	}
	//n行m列
	int iu = 1;
	int ju = 0;
	while (indx > 0) {
		ju++;
		if (ju % 2 == 0) {
			indx--;
			iu++;
		}
		if (ju % 2 != 0) {
			indx--;
			iu--;
		}
	}
	cout << iu << " " << ju;
	return 0;
}
