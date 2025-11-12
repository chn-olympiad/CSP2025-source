#include <bits/stdc++.h>
using namespace std;
int a[10010];
int n, m;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int num = m * n;
	for (int i = 1; i <= num; i++)
		cin >> a[i];
	int k = a[1], ans;
	sort(a + 1, a + num + 1, cmp);
	for (int i = 1; i <= num; i++) {
		if (a[i] == k) {
			ans = i;
			break;
		}
	}
	int c = (ans + n - 1) / n, r;
	if (c % 2 == 1) {
		if (ans % n == 0)
			r = n;
		else
			r = ans % n;
	} else {
		if (ans % n == 0)
			r = 1;
		else
			r = n + 1 - ans % n;
	}
	cout << c << " " << r;
	return 0;
}
