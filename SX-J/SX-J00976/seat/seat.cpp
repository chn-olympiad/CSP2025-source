#include <bits/stdc++.h>
using namespace std;

#define For(i,x,y,...) for(int i=(x),##__VA_ARGS__;i<=(y);++i)
#define foR(i,x,y,...) for(int i=(x),##__VA_ARGS__;i>=(y);--i)
#define Rep(i,x,y,...) for(int i=(x),##__VA_ARGS__;i<(y);++i)
typedef long long ll;
#define fi first
#define se second
#define me(s,x) memset(s,x,sizeof s)
#define pb emplace_back
const int N = 105;
int a[N], s, p;

void MAIN() {
	int n, m;
	cin >> n >> m;
	For(i, 1, n *m) cin >> a[i];
	int s = a[1];
	sort(a + 1, a + n *m + 1, greater<int>());
	For(i, 1, n *m) {
		if (a[i] == s) {
			p = i;
			break;
		}
	}
//	cout << p << endl;
	int c = p % n == 0 ? p / n : p / n + 1;
//	cout << p << " " << n << " " << p / n << endl;
	cout << c << " ";
	if (c & 1) {
		p -= p / n * n;
		cout << (p == 0 ? n : p) << endl;
	} else {
		p -= p / n * n;
		cout << (p == 0 ? 1 : n + 1 - p) << endl;
	}
}

signed main() {
	freopen("seat.in", "r", stdin), freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(nullptr);
	int t = 1;
	while (t--) {
		MAIN();
	}
	return 0;
}
