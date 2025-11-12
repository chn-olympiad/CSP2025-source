#include<bits/stdc++.h>
#define REP(i, a, b) for (int i = a; i <= b; i ++)
#define PER(i, a, b) for (int i = a; i >= b; i --)
#define pii pair<int,int>
using namespace std;
const int N = 1e5 + 10;
string s[N][3], t[3];
int cz[N];
int n, q;
void Sub1(){
	while (q --) {
		int cnt = 0;
		cin >> t[1] >> t[2];
		if (t[1].length() != t[2].length()) {
			cout << 0 << '\n';
			continue;
		}
		REP(i, 1, n) {
			REP(st, 0, t[1].length() - 1) {
				if (st + s[i][1].length() > t[1].length()) break;
				bool same = 1;
				
				//qian
				REP(p, 0, st - 1)
					if (t[1][p] != t[2][p]) same = 0;
				if (!same) continue;
				
				//hou
				REP(p, st + s[i][1].length(), t[1].length() - 1)
					if (t[1][p] != t[2][p]) same = 0;
				if (!same) continue;
				
				
				//huan
				REP(p, st, st + s[i][1].length() - 1) {
					if (t[1][p] != s[i][1][p - st]) {
						same = 0;
						break;
					}
				}
				if (same) {
					REP(p, st, st + s[i][1].length() - 1) {
						if (t[2][p] != s[i][2][p - st]) {
							same = 0;
							break;
						}
					}
				}
				if (same) cnt ++;
			}
		}
		cout << cnt << '\n';
	}
}
void Sub2() {

}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	REP(i, 1, n) {
		cin >> s[i][1] >> s[i][2];
	}
	if (n <= 100) Sub1();
	else Sub2();
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

