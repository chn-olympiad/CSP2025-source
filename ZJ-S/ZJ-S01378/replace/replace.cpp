#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1, M = 2e3 + 1;
int a[M][N];
map <int, int> g;
int getint () {
	char ch = getchar ();
	int num = 0, fs = 1;
	while ( ( ch < '0' || ch > '9' ) && ch != '-' ) ch = getchar ();
	if (ch == '-') fs = -1, ch = getchar ();
	while ( ch >= '0' && ch <= '9' ) num = num * 10 + ch - '0', ch = getchar ();
	return num * fs;
}
signed main () {
	freopen ( "replace.in", "r", stdin );
	freopen ( "replace.out", "w", stdout );
	int n = getint (), q = getint (), lent = 0, cmd = 0;
		for (int i = 1; i <= n; i ++) {
			int ans1 = 1, ans2 = 1, fw = 0;
			char ch = getchar ();
			while (ch != 'b') ans1 ++, ch = getchar ();
			while (ch != ' ') ch = getchar (), fw ++;
			while (ch != 'b') ans2 ++, ch = getchar ();
			while (ch != '\n') ch = getchar ();
			if (g[ans1 - ans2] != 0) a[g[ans1 - ans2]][++ a[g[ans1 - ans2]][0]] = fw;
			else g[ans1 - ans2] = ++cmd, a[g[ans1 - ans2]][++ a[g[ans1 - ans2]][0]] = fw;
		}
		for (int i = 1; i <= cmd; i ++)
			sort (a[i] + 1, a[i] + 1 + a[i][0]);
		for (int i = 1; i <= q; i ++) {
			int ans1 = 1, ans2 = 1, fw = 0;
			char ch = getchar ();
			while (ch != 'b') ans1 ++, ch = getchar ();
			while (ch != ' ') ch = getchar (), fw ++;
			while (ch != 'b') ans2 ++, ch = getchar ();
			while (ch != '\n') ch = getchar ();
			if(g[ans1- ans2] != 0) {
				int t = 1, w = a[g[ans1 - ans2]][0], ans = w;
				while (t <= w) {
					int mid = (t + w) / 2;
					if (fw < a[g[ans1 - ans2]][mid]) t = mid + 1, ans = mid;
					else w = mid - 1;
				}
				printf ("%d\n", a[g[ans1 - ans2]][0] - ans);
			} 
			else printf ("0\n");
		}
	
	return 0;
}
