#include <bits/stdc++.h>
#define ll long long
#define Fcin; ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n, m;
int a[105], s[105][105];
bool cmp (int x, int y) {
	return x > y;
}
void solve () {
	int ans = 1;
	int t = n * 2 - 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (j == 1) s[i][j] = i;
			else {
				if (j % 2 == 0) s[i][j] = s[i][j - 1] + t;
				else s[i][j] = s[i][j - 1] + n * 2 - t;
			}
		}
		t -= 2;
	}
	return;
}
int main () {
	Fcin;
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	cin >> n >> m;
	int p = 0;
	for (int i = 1; i <= n * m; i++) cin >> a[i], p = a[1];
	sort (a + 1, a + n * m + 1, cmp);
	solve ();
	int o = 0;
	for (int i = 1; i <= n * m; i++)
	  if (a[i] == p) {
	  	o = i;
	  	break;
	  }
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
		  if (s[i][j] == o) {
		  	cout << j << ' ' << i;
		  	return 0;
		  }
	}
	return 0;
}

