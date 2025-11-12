#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int T, n;
int z[N][5];
int ans = 0;
int a, b, c;
int g = 0;

int za(int x) { //a
	a++;
	if (a > g)
		return 0;
	return z[x][1];
}

int zb(int x) { //a
	b++;
	if (b > g)
		return 0;
	return z[x][2];
}


int zc(int x) { //a
	c++;
	if (c > g)
		return 0;
	return z[x][3];
}

int d(int x) {
	if (x == n)
		return max(za(x), max(zb(x), zc(x)));
	return d(x + 1) + max(za(x), max(zb(x), zc(x)));
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		ans = 0;
		cin >> n;
		g = n / 2;
		for (int i = 1; i <= n; i++) {
			cin >> z[i][1] >> z[i][2] >> z[i][3];
		}
		ans = d(1);
		cout << ans;
	}
	return 0;
}
//
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
