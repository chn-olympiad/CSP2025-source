#include <bits/stdc++.h>
#define il inline

using namespace std;

const int N = 2e5 + 5;
const int Inf = 2e9;
const int Mod = 998244353;
il int Add(int x, int y) {return x + y >= Mod ? x + y - Mod : x + y;} il void pls(int &x, int y) {x = Add(x, y);}
il int Del(int x, int y) {return x - y < 0    ? x - y + Mod : x - y;} il void sub(int &x, int y) {x = Del(x, y);}
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
	il IO &operator >> (string &s) {
		s = ""; char c = gc();
		while(c == ' ' || c == '\n' || c == '\r') c = gc();
		while(c != ' ' && c != '\n' && c != '\r' && c != EOF) s += c, c = gc();
		return *this;
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

int n, m;
string s;
int c[N];

int dp[1 << 18][20];
il void solve() {
	dp[0][0] = 1;
	for(int i = 0; i < n; i++) {
		for(int S = 0; S < (1 << n); S++) {
			if(__builtin_popcount(S) != i) continue;
			for(int j = 0; j <= i; j++) {
				if(!dp[S][j]) continue;
				for(int p = 1; p <= n; p++) {
					if((S >> p - 1) & 1) continue;
					if(j >= c[p] || s[i] == '0') pls(dp[S ^ (1 << p - 1)][j + 1], dp[S][j]);
					else pls(dp[S ^ (1 << p - 1)][j], dp[S][j]);
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i <= n - m; i++) {
		pls(ans, dp[(1 << n) - 1][i]);
	}
	fout << ans << '\n';
}

il void main() {
	fin >> n >> m >> s;
	for(int i = 1; i <= n; i++) {
		fin >> c[i];
	}
	if(n <= 18) solve();
	else fout << "0\n";
}
}
il void File() {freopen("employ.in", "r", stdin); freopen("employ.out", "w", stdout);}
bool End;
il void Usd() {cerr << (&Beg - &End) / 1024.0 / 1024.0 << "MB " << (double)clock() * 1000 / CLOCKS_PER_SEC << "ms\n";}
int main() {
	File();
	My_Space::main();
	Usd();
	return 0;
}

