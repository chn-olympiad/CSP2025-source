#include <bits/stdc++.h>
using namespace std;
int n, a[5005], b[5005], d[5005], c, c1, s, s1, sum;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	s = 2 * a[n ];
	for (int i = n, j = 1; i >= 3; i--, j++)
		c += j * i;
	while (c--) {
		c1 = 0;
		s1 = 0;
		for (int i = 1; i < n; i++)
			b[i] = 0;
		for (int i = n ; i > 0; i--) {
			if (s1 + a[i] > s && b[i] == 1)
				i--;
			if (i == 0) {
				n --;
				s = 2 * a[n ];
				break;
			}
			if (s1 + a[i] > s && c1 >= 3) {
				sum++;
				b[i]++;
				break;
			}
			s1 += a[i];
			b[i] = 1;
			c1++;
		}
	}
	cout << sum;
}