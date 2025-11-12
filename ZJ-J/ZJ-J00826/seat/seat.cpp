#include <bits/stdc++.h>
using namespace std;
const int N = 105; int n, m, k, a[N];
signed main(){
	freopen("seat.in", "r", stdin); freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++) cin >> a[i]; k = a[1];
	sort(a + 1, a + n*m + 1, [](int x, int y){
		return x > y;
	});
	for (int i = 1, j = 1, u = 1, o = 1; u <= n*m; u++){
		if (a[u] == k) return cout << j << " " << i, 0;
		if (o) i++; else i--;
		if (i > n || i < 1) j++, i = (o ? n : 1), o ^= 1;
	}
	return 0;
}

