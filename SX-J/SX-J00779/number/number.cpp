#include <bits/stdc++.h>
using namespace std;
char a[1000001];
int c[1000001];
int ans = 0;
long long d = 1;

bool cmp (int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin );
	freopen("number.out", "w", stdout );

	cin >> a + 1;
//

	for (int i = 1; i <= 1000001; ++i) {
		if (a[i] == '/0')
			break;
		if (a[i] >= '0' && a[i] <= '9') {
			c[d] = a[i] - '0';

			d++;
		}
	}


	sort( c + 1, c + d, cmp);
	for (int j = 1; j < d; j++) {
//		printf("%d\n", a[1]);

		printf("%d", c[j]);
	}
	return 0;
}
//!= r
//index++;
//if
