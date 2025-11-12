#include <bits/stdc++.h>

using namespace std;

int n, m, a[105];

int main () {
	freopen ("seat.in", "r", stdin);
	freopen ("seat.in", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	int t = a[1];
	sort (a + 1, a + 1 + n * m);
	int l = 0, r = 1;
	bool f = true;
	for (int i = n * m; i >= 1; i--) {
		//cout << l << " " << r << " " << f << " " << a[i] << " " << t << endl;
		if (l == n && f) {
			r++;
			l = n, f = false;
		} else if (l == 1 && !f) {
			r++;
			l = 1, f = true;
		} else if (f) l++;
		else l--; 
		if (a[i] == t) cout << r << " " << l, exit (0);
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
}
