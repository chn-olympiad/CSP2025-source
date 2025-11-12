#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int a[N], n, m;

bool cmp(int c, int b) {
	return c > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	int num = a[1];
	sort(a + 1, a + 1 + n *m, cmp);
	int n1 = 1, m1 = 1;
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == num) {
			cout << n1 << " " << m1;
			return 0;
		}
		if (n1 % 2)
			m1++;
		else
			m1--;
		if (m1 > n) {
			m1--;
			n1++;
		} else if (m1 == 0) {
			m1++;
			n1++;
		}
	}
	return 0;
}
