#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 1e5 + 10;
int a[N], l = 1;
int n, m, c, r;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i ++) {
		cin >> a[i];
		if(a[i] > a[1]) l ++;
	}
//	cout << l;
	c = ceil(l * 1.0 / n), r = l % (2 * n);
	if(r > n) r = 2 * n - r + 1;
	cout << c << " " << r;
	return 0;
}
