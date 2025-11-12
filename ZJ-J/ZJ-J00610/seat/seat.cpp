#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 110;
int n, m, a[N];

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n * m;++ i) cin >> a[i];
	int x = a[1];
	sort(a + 1, a + 1 + n * m, greater<int>());
	int r = 1, c = 1, d = 1;
	for(int i = 1;i <= n * m;++ i){
		if(a[i] == x) {
			cout << c << ' ' << r;
			return 0;
		}
		if(d) {
			if(r + 1 > n) {
				c++;
				d = 0;
			} else {
				r++;
			}
		} else {
			if(r - 1 < 1) {
				c++;
				d = 1;
			} else {
				r--;
			}
		}
	}
	return 0;
}