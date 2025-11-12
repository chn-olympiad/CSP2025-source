#include <bits/stdc++.h>
using namespace std;
#define int long long

int n , m , a[1009] , tmp , c , r;

signed main() {
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1 ; i <= n * m ; i++) cin >> a[i];
	tmp = a[1];
	sort(a + 1 , a + (n * m) + 1 , [](const int &x , const int &y){return x > y;});
	for (int i = 1 ; i <= n * m ; i++) {
		if (a[i] == tmp) {
			c = (i + n - 1) / n;
			if (c & 1ll) r = (i - 1) % n + 1;
			else r = n + 1 - i % n;
		}
	}
	cout << c << " " << r;
	return 0;
}
