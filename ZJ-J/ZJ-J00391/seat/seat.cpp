#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define io ios::sync_with_stdio(0), cin.tie(), cout.tie()
#define open(_io) freopen(_io".in", "r", stdin), freopen(_io".out", "w", stdout)
const ll _nm = 10 * 10 + 1;
ll n, m, c, r, s = 1, a[_nm];
int main(){
	io;
	open("seat");
	cin >> n >> m >> a[1];
	for (ll i = 2; i <= n * m; i++){
		cin >> a[i];
		if (a[i] > a[1]) s++;
	}c = (s - 1) / n + 1;
	if (c & 1) r = (s - 1) % n + 1;
	else r = n - (s - 1) % n;
	cout << c << ' ' << r;
	return 0;
}

