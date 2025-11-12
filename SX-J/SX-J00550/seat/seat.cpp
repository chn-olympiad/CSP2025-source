#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
int a[MAXN];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int nm = n * m;
	for (int i = 1; i <= nm; i++) {
		cin >> a[i];
	}
	int r = a[1];
	sort(a + 1, a + 1 + nm, cmp);
	int num = 0;
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= n; j++) {
				num++;
				if (a[num] == r) {
					cout << i << " " << j;
					return 0;
				}
			}
		} else {
			for (int j = n; j >= 1; j--) {
				num++;
				if (a[num] == r) {
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	return 0;
}
