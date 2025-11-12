#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, l, r) for (int i = l; i <= r; i ++)
const int N= 107;
int a[N];
bool cmp(int x, int y) {
	return x > y;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	rep(i, 1, n*m) cin >> a[i];
	int t = a[1];
	sort(a+1, a+n*m+1, cmp);
	int pos;
	rep(i, 1, n*m) {
		if (a[i] == t) pos = i;
	}
	int x = (pos-1)/n+1;
	int y = pos-(pos-1)/n*n;
	cout << x << ' ';
	if (x&1) cout << y;
	else cout << n+1-y;
	return 0;
}
