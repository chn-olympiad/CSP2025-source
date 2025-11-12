#include <bits/stdc++.h>
using namespace std;
long long n, m, b[114514], c, d = 0, o = 0, s = 1;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	c = n * m;
	for (int i = 1; i <= c; i++)
		cin >> b[i];
	d = b[1];
	sort(b + 1, b + c + 1);
	for (int i = c; i >= 1; i--) {
		if (s % 2 != 0) {
			o++;
			if (o > n) {
				s++;
				o--;
			}
			if (b[i] == d) {
				cout << s << " " << o;
				return 0;
			}

		}
		if (s % 2 == 0) {
			if (o == n)
				i--;
			o--;
			if (o < 1) {
				s++;
				o++;
			}
			if (b[i] == d) {
				cout << s << " " << o;
				return 0;
			}
		}
	}
	return 0;
}
