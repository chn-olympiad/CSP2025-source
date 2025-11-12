#include <bits/stdc++.h>
using namespace std;
int n, m, x, a[101];

bool cmp(int a, int b) {
	if (a < b)
		return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if (i == 1)
			x = a[i];
	}
	sort(a + 1, a + n *m + 1, cmp);
	int i = 1, j = 1;
	bool flag = 0;
	for (int s = 1; s <= n * m; s++) {
		if (a[s] == x) {
			cout << j << " " << i;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
		if (i * j == 1)
			flag = 1;
		if (i < n && i > 1 || flag) {
			if (flag)
				flag = 0;
			if (j % 2 == 1)
				i ++;
			else
				i--;
		} else {
			j++;
			flag = 1;
		}
	}
}