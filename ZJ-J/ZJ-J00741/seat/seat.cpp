#include <bits/stdc++.h>
#define int long long
#define rep(i, l, r) for(int i = l; i <= r; ++i)
#define per(i, r, l) for(int i = r; i >= l; --i)
using namespace std;
const int N = 15;
int n, m, a[N * N], tmp, x = 1, y = 1, op = 1;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	rep(i, 1, n * m) cin >> a[i];
	tmp = a[1];
	sort(a + 1, a + n * m + 1, greater <int>());
	rep(i, 1, n * m){
		int tx = x + op, ty = y;
		if (tx < 1 || tx > n){
			tx = x;
			ty = y + 1;
			op = -op;
		}
		if (a[i] == tmp){
			cout << y << ' ' << x << '\n';
			return 0;
		}
		x = tx, y = ty;
	}
	return 0;
}
