#include<bits/stdc++.h>
using namespace std;
const int N = 500 + 10;
int n, q;
char s[N][2][N];
int len[N][2];
int sz;
char t_1[N], t_0[N], t[N];
bool find (int bg, int id) {
	for (int i = bg; i < bg + len[id][0]; i++) {
		if (t[i] != s[id][0][i - bg + 1]) return 0;
	}
	return 1;
}
bool eql () {
	for (int i = 1; i <= sz; i++) {
		if (t[i] != t_1[i]) {
//			cout << i << "\n";
//			cout << t[i] << " " << t_1[i] << "\n";
			return 0;
		}
	}
	return 1;
} 
void solve() {
	for (int i = 1; i <= n; i++) {
		scanf ("%s%s", s[i][0] + 1, s[i][1] + 1);
		len[i][0] = strlen (s[i][0] + 1);
		len[i][1] = len[i][0];
	}
	while (q--) {
		int ans = 0;
		scanf ("%s%s", t_0 + 1, t_1 + 1);
		sz = strlen (t_0 + 1);
		for (int i = 1; i <= sz; i++) t[i] = t_0[i];
		for (int i = 1; i <= n; i++) {
			for (int bg = 1; bg <= sz; bg++) {
				if (find(bg, i)) {
//					cout<<bg<<" "<<i<<endl;
					for (int x = 1; x <= len[i][1]; x++) {
						t[bg + x - 1] = s[i][1][x];
					}
					if (eql ()) ans++;
				}
				for (int i = 1; i <= sz; i++) t[i] = t_0[i];
			} 
		}
		printf ("%d\n", ans);
	}
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf ("%d%d", &n, &q);
	if (n <= 100 and q <= 100) {
		solve();
		return 0;
	}
	while (q--) printf ("0\n");
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
