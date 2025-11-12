#include <bits/stdc++.h>
using namespace std;
int n, m, c, r, cnt;
int s[15][15], num[105];

int cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= (n * m); i++)
		cin >> num[i];
	int sum = num[1];
	sort(num + 1, num + 1 + (n *m), cmp);
	for (int i = 1; i <= m; i += 2) {
		for (int j = 1; j <= n; j++) {
			cnt++;
			if (num[cnt] == sum) {
				c = i;
				r = j;
				break;
			}
		}
		for (int j = n; j >= 1; j--) {
			cnt++;
			if (num[cnt] == sum) {
				c = i + 1;
				r = j;
				break;
			}
		}
	}
	cout << c << " " << r;
	return 0;
}
