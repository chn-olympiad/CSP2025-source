#include <bits/stdc++.h>
using namespace std;

const int N = 505;

int n , m , p[N] , ans , c[N];

char s[N];

int check () {
	int ys = 0;
	for (int i = 1;i <= n;i ++) {
		if (i - ys - 1 >= c[p[i]] || s[i] == '0') continue;
		ys ++;
	}
	return ys >= m;
}

signed main () {
	freopen ("employ.in" , "r" , stdin);
	freopen ("employ.out" , "w" , stdout);
	cin >> n >> m >> (s + 1);
	for (int i = 1;i <= n;i ++) cin >> c[i];
	for (int i = 1;i <= n;i ++) p[i] = i;
	do {
		ans += check();
	} while (next_permutation (p + 1 , p + 1 + n));
	cout << ans;
	return 0;
}