#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N];
bool f = 0;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, x, c, r, s;
	cin >> n >> m;
	s = n * m;
	for (int i = 1; i <= s; i++)
		cin >> a[i];
	x = a[1];
	sort(a + 1, a + s + 1);

	for (int i = 1; i <= m; i++) {
		if (f == 0) {
			for (int j = 1; j <= n; j++) {
				if (a[s] == x) {
					c = i, r = j;
				}
				s--;
				//cout << i << " " << j << "    ";
			}
			//cout << endl;
			f = 1;
		} else if (f == 1) {
			for (int j = n; j >= 1; j--) {
				if (a[s] == x) {
					c = i, r = j;
				}
				s--;
				///cout << i << " " << j << "    ";
			}
			//	cout << endl;
			f = 0;
		}
	}
	cout << c << " " << r;
	return 0;
}