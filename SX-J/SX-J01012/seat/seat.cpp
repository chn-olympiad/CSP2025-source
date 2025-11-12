#include <bits/stdc++.h>;
using namespace std;
int a[15][15], b[105];

bool f(int x, int y) {
	return x > y;
}

int main() {
	/*freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);*/
	int n, m, na = 1, ma = 1, bb, c = 1, r = 1, z = 0;
	cin >> n >> m;
	int x = 0;
	for (int i = 1; i <= n * m; ++i) {
		cin >> b[i];
		if (i == 1) {
			bb = b[i];
		}
	}
	sort(b + 1, b + n *m + 1, f);
	//cout << b[2] << ' ';
	for (int i = 1; i <= n * m; ++i) {
		//a[na][ma] = b[i];
		if (b[i] == bb) {
			break;
		}
		if (m == 1) {
			n++;
		} else {
			if (ma == 1 && na != 1) {
				na++;
				c++;
				x = 0;
			} else if (ma == m && z == 0) {
				na++;
				c++;
				x = 1;
				z++;
			} else {
				if (x == 0) {
					++ma;
					r++;


				} else {
					--ma;
					r--;
					z = 0;
				}
			}
		}
	}
	printf("%d %d", c, r);
	fclose(stdin);
	fclose(stdin);
	return 0;
}