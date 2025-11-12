#include<bits/stdc++.h>
#define int long long
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
#define pb push_back
using namespace std;
typedef pair<int, int> pii;
typedef pair<string, string> pss;
const int N = 2e5 + 29;

int n, q;
struct node {
	bool lr;
	int d;
	int left;
	int right;
} a[N];
vector<int> l, r;

void tbcsolve() {
	cin >> n >> q;
	rep (i, 1, n) {
		string s1, s2;
		cin >> s1 >> s2;
		int len = s1.size();
		int pos1, pos2;
		rep (j, 0, len - 1) if(s1[j] == 'b') pos1 = j;
		rep (j, 0, len - 1) if(s2[j] == 'b') pos2 = j;
		if (pos1 < pos2) {
			a[i] = {1, pos2 - pos1, pos1, len - 1 - pos2};
			r.pb(i);
		}
		else {
			a[i] = {0, pos1 - pos2, pos2, len - 1 - pos1};
			l.pb(i);
		}
	}
	while (q--) {
		string t1, t2;
		cin >> t1 >> t2;
		int len = t1.size();
		int pos1, pos2;
		rep (j, 0, len - 1) if(t1[j] == 'b') pos1 = j;
		rep (j, 0, len - 1) if(t2[j] == 'b') pos2 = j;
		int ans = 0;
		if (pos1 < pos2) {
			for (auto i : r) {
				if (a[i].d == pos2 - pos1 && a[i].left <= pos1 && a[i].right <= len - 1 - pos2) ans++; 
			}
		}
		else {
			for (auto i : l) {
				if (a[i].d == pos1 - pos2 && a[i].left <= pos2 && a[i].right <= len - 1 - pos1) ans++; 
			}
		}
		cout << ans << '\n';
	}
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int SHEN = 1;
//	cin >> SHEN;
	while (SHEN--) {
		tbcsolve();
	}
	return 0;
}
/*
17:12 推了一会儿 T4 的 dp 式子发现没什么思路，所以先来写 T3 的 特殊性质 B（整整 25pts！！！） 
17:39 忘了怎么用 fc 了，人眼比对了一下几百行样例 4 应该过了，就当 25pts 到手了吧 
*/
