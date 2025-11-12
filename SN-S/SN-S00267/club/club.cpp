/*

I Am Always Me. Just Go For It. Run, Kid! 

别崩，兄弟，稳住。一年的艰辛啊，一年的耻辱啊，绝不能因为心态问题白费了。 

我咋觉得我今年又无缘 NOIP 了。。。

别急，我又有了！ 
*/

#include <bits/stdc++.h>
#define il inline

using namespace std;

const int bufsz = 1 << 20;
char ibuf[bufsz], *p1 = ibuf, *p2 = ibuf;
#define getchar() (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, bufsz, stdin), p1 == p2) ? EOF : *p1++)
il int read() {
	int x = 0; char ch = getchar(); bool t = 0;
	while (ch < '0' || ch > '9') {t ^= ch == '-'; ch = getchar();}
	while (ch >= '0' && ch <= '9') {x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
	return t ? -x : x;
}
bool Beg;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;
int n, a[N][3];
struct node {
	int id, v, x, nxt, fl;
	il bool operator < (const node & cmp) const {
		if (!fl) return v != cmp.v ? v > cmp.v : nxt < cmp.nxt;
		else return nxt - v != cmp.nxt - cmp.v ? nxt - v > cmp.nxt - cmp.v : nxt > cmp.nxt;
	}
};
multiset<node> st, s[3];
il node create(int i, int fl) {
	node t; t.id = i, t.fl = fl;
	t.v = max(a[i][0], max(a[i][1], a[i][2]));
	if (t.v == a[i][0]) t.x = 0, t.nxt = max(a[i][1], a[i][2]);
	if (t.v == a[i][1]) t.x = 1, t.nxt = max(a[i][0], a[i][2]);
	if (t.v == a[i][2]) t.x = 2, t.nxt = max(a[i][0], a[i][1]);
	return t;
}
int solve() {
	n = read();
	st.clear();
	for (int i = 1; i <= n; i++) {
		a[i][0] = read(), a[i][1] = read(), a[i][2] = read();
		st.insert(create(i, 0));
	}
	s[0].clear(), s[1].clear(), s[2].clear();
	int ans = 0;
	while (!st.empty()) {
		node f = *st.begin();
		if (s[f.x].size() >= n / 2) {
			node t = *s[f.x].begin();
//			cout << "  " << t.id << " " << t.v << " " << t.nxt << "  " << f.id << " " << f.v << " " << f.nxt << "\n";
			if (ans + f.v - t.v + t.nxt > ans + f.nxt) {
				ans = ans - t.v + f.v;
				a[t.id][t.x] = -INF;
				s[t.x].erase(s[t.x].find(t));
				st.insert(create(t.id, 0));
				f.fl = 1;
//				cout << "B " << f.id << " " << f.x << " " << f.v << "\n";
				s[f.x].insert(f);
				st.erase(st.find(f));
			} else {
				a[f.id][f.x] = -INF;
				st.erase(st.find(f));
				st.insert(create(f.id, 0));
			}
			continue;
		}
		ans += f.v;
//		cout << "A " << f.id << " " << f.x << " " << f.v << "\n";
		f.fl = 1;
		s[f.x].insert(f);
		st.erase(st.find(f));
	}
	printf("%d\n", ans);
	return 0;
}
bool End;
il void Usd() {cerr << "\nUse: " << (&Beg - &End) / 1024.0 / 1024.0 << "MB " << (double)clock() * 1000.0 / CLOCKS_PER_SEC << "ms\n";}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
//	freopen("club5.in", "r", stdin);
//	freopen("mine.out", "w", stdout);
//	system("fc club5.ans mine.out"); return 0;
	int qq = read();
	while (qq--) {
		solve();
	}
//	Usd();
	return 0;
}
