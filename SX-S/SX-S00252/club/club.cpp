#include <bits/stdc++.h>
using namespace std;
int T, n, sum = 0;

int x, y, z;
int a_1[100010];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		memset(a_1, 0, sizeof(a_1));
		sum = 0;
		cin >> n;
		int ha_n = n / 2;
		for (int j = 1; j <= n; j++) {
			cin >> x >> y >> z;
			if (z == 0 && y == 0) {
				a_1[j] = x;
			}
		}
		sort(a_1 + 1, a_1 + 1 + n, cmp);
		for (int i = 1; i <= ha_n; i++) {
			sum += a_1[i];
		}
		cout << sum << endl;
	}
	return 0;
}
