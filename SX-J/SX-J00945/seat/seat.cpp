#include <bits/stdc++.h>
using namespace std;
long long n, m, a[110], r, x = 1, y = 1, cnt;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> a[1];
	r = a[1];
	for (int i = 2; i <= n * m; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + (n *m), cmp);
	cnt = 1;
	for (int i = 1; i <= n * m; i++) {

		if (a[i] == r) {
			cout << y << " " << x;
			return 0;
		}
		x += cnt;
		if (cnt == 1 && x > n) {
			cnt = -1;
			x = n;
			y++;
		} else {
			if (cnt == -1 && x == 0) {
				cnt = 1;
				x = 1;
				y++;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
