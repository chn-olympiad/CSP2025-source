#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[110];
int r, s, ans;

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if (i == 1) {
			r = a[i];
		}
	}
	sort(a + 1, a + n *m + 1, greater<int>());
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == r) {
			s = i;
			break;
		}
	}
	if (s % n == 0) {
		if (s / n % 2 == 1)
			cout << s / n << " " << n;
		else
			cout << s / n << " " << 1;
	} else {
		if (s / n % 2 == 1)
			cout << s / n + 1 << " " << n - (s % n) + 1;
		else
			cout << s / n + 1 << " " << s % n;
	}
	return 0;
}
