#include <bits/stdc++.h>
// #define DEBUG
using namespace std;
int n, m, c, r, a[110], t, mp[15][15], index;
bool cmp(int a, int b){ return a > b; }
int main(){
#ifndef DEBUG
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
#endif
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i)
		cin >> a[i];
	t = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; ++i)
		if (a[i] == t)
			t = i;
	for (int j = 1; j <= m; ++j){
		if (j % 2) for (int i = 1; i <= n; ++i)
			mp[i][j] = ++index;
		else for (int i = n; i >= 1; --i)
			mp[i][j] = ++index;
	}
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j)
		if (mp[i][j] == t)
			cout << j << ' ' << i;
	return 0;
}