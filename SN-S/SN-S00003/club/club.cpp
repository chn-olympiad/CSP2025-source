#include <bits/stdc++.h>
#define il inline

using namespace std;

const int N = 2e5 + 5;
const int Inf = 2e9;
template <typename T> il void chkmin(T &x, T y) {x = min(x, y);}
template <typename T> il void chkmax(T &x, T y) {x = max(x, y);}
bool Beg;
namespace My_Space {
struct IO {
	static const int Size = (1 << 21);
	char buf[Size], *p1, *p2; int st[105], Top;
	~IO() {clear();}
	il void clear() {fwrite(buf, 1, Top, stdout); Top = 0;}
	il char gc() {return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, Size, stdin), p1 == p2) ? EOF : *p1++;}
	il void pc(const char c) {Top == Size && (clear(), 0); buf[Top++] = c;}
	il IO &operator >> (char &c) {while(c = gc(), c == ' ' || c == '\n' || c == '\r'); return *this;}
	template <typename T> il IO &operator >> (T &x) {
		x = 0; int flg = 0; char c = gc();
		while(c < '0' || c > '9') {if(c == '-') flg = 1; c = gc();}
		while(c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = gc();
		flg ? x = -x : 0; return *this;
	}
	il IO &operator << (const char c) {pc(c); return *this;}
	template <typename T> il IO &operator << (T x) {
		if(x < 0) pc('-'), x = -x;
		do st[++st[0]] = x % 10, x /= 10; while(x);
		while(st[0]) pc('0' + st[st[0]--]);
		return *this;
	}
	il IO &operator << (const char *s) {for(int i = 0; s[i]; i++) pc(s[i]); return *this;}
}fin, fout;

int T;
int n, a[N][4], id[4];
int cnt[4];

priority_queue <int> q[4];
il void solve() {
	fin >> n; int m = (n >> 1);
	for(int i = 1; i <= n; i++) fin >> a[i][1] >> a[i][2] >> a[i][3];
	int ans = 0;
	while(q[1].size()) q[1].pop(); cnt[1] = 0;
	while(q[2].size()) q[2].pop(); cnt[2] = 0;
	while(q[3].size()) q[3].pop(); cnt[3] = 0;
	for(int i = 1; i <= n; i++) {
		id[1] = 1, id[2] = 2, id[3] = 3;
		sort(id + 1, id + 4, [=](int x, int y){return a[i][x] > a[i][y];});
		ans += a[i][id[1]];
		cnt[id[1]]++; q[id[1]].push(max(a[i][id[2]], a[i][id[3]]) - a[i][id[1]]);
	}
	if(cnt[1] <= m && cnt[2] <= m && cnt[3] <= m) {
		fout << ans << '\n'; return ;
	}
	for(int i = 1; i <= 3; i++) {
		if(cnt[i] > m) {
			while(cnt[i] > m) {
				ans += q[i].top(); q[i].pop();
				cnt[i]--;
			}
			break;
		}
	}
	fout << ans << '\n';
}

il void main() {
	fin >> T;
	while(T--) solve();
}
}
il void File() {freopen("club.in", "r", stdin); freopen("club.out", "w", stdout);}
bool End;
il void Usd() {cerr << (&Beg - &End) / 1024.0 / 1024.0 << "MB " << (double)clock() * 1000 / CLOCKS_PER_SEC << "ms\n";}
int main() {
	File();
	My_Space::main();
	Usd();
	return 0;
}

