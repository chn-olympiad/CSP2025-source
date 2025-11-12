#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int a[100100], t, o, x;
bool cmp(int x, int y) {return x > y;}
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n * m; i ++) cin >> a[i];
	
	int p = a[1];
	
	sort(a + 1, a + 1 + n * m, cmp);
	
	for(int i = 1; i <= n * m; i ++) {
		if(t == n + 1) {
			x ++;
			o ^= 1;
			t = n;
		}
		else if(!t) {
			x ++;
			o ^= 1;
			t = 1;
		}
		if(a[i] == p) {
			cout << x << ' ' << t;
			return 0;
		}
		if(o) t ++;
		else t --;
	}
	
	
	return 0;
}
