#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define lop(i, a, b) for (int i = (a); i < (b); i++)
#define dwn(i, a, b) for (int i = (a); i >= (b); i--)
#define pr pair<int, int>
#define mp(a, b) make_pair(a, b)
#define fir first
#define sec second
#define iosfst ios :: sync_with_stdio(false);cin.tie(0), cout.tie(0)
#define File(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
using namespace std;
string s;
int a[10];
signed main() {
	iosfst;
	File("number");
	cin >> s;
	lop (i, 0, s.size()) if ('0' <= s[i] && s[i] <= '9') a[s[i] - '0']++;
	dwn (i, 9, 0) while (a[i]--) cout << i;
	return 0;
}
