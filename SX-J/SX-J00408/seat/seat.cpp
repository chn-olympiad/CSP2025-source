#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
int a[110];

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, cj, pm = 1;
	cin >> n >> m;
	int x = n * m;
	fr(i, 1, x) {
		cin >> a[i];
	}
	cj = a[1];
	fr(i, 1, x) {
		if (a[i] > cj) {
			pm += 1;
		}
	}
	int hs, ls;
	ls = pm / n + 1;
	if (pm % n == 0)
		ls--;
	if (ls % 2 == 1) {
		hs = pm % n;
		if (hs == 0)
			hs = n;
	} else {
		hs = n - (pm % n) + 1;
	}
	cout << ls << " " << hs;
	return 0;
}
//行数n 列数m