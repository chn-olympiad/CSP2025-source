#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, a[105], xm, ind;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n*m;i++) {
		cin >> a[i];
		if (i == 1) xm = a[i];
	}
	sort(a + 1, a + n*m + 1, cmp);
	for (int i = 1;i <= n*m;i++) {
		if (a[i] == xm) {
			ind = i;
			break;
		}
	}
	int lie = ind / n, hang = ind % (2 * n);
	if (ind % n > 0) {
		lie++; 
	}
	if (hang > n) {
		hang = 2 * n - hang + 1;
	} else if (hang == 0) {
		hang = 1;
	}
	cout << lie << " " << hang;
	return 0;
}
