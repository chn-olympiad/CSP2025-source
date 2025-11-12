#include <bits/stdc++.h>
using namespace std;
int m, n;
int mp[20][20];
int stk[110];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= m * n; i++) {
		cin >> stk[i];
	}
	int lil_s = stk[1], k = 1;
	sort(stk + 1, stk + 1 + m *n, cmp);
	for (int i = 1; i <= n; i++) {
		if (i % 2 != 0) {
			for (int j = 1; j <= m; j++) {
				mp[j][i] = stk[k];
				k++;
				if (mp[j][i] == lil_s) {
					cout << i << " " << j;
					return 0;
				}
			}
		} else {
			for (int j = m; j >= 1; j--) {
				mp[j][i] = stk[k];
				k++;
				if (mp[j][i] == lil_s) {
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	return 0;
}
