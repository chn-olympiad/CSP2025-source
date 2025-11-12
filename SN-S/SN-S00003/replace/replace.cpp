#include <bits/stdc++.h>
#define il inline
 
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
const int N = 2e5 + 5, M = 5e6 + 5;
const int Inf = 2e9;
const ull Mod = 1e9 + 9, base = 13331;
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
	il IO &operator << (const string s) {for(auto c : s) pc(c); return *this;}
}fin, fout;

int n, q;
string s[N][2];

#define puu pair<ull, ull>
#define mk make_pair
#define fi first
#define se second
int cnt;
struct My_Hash {
	il size_t operator () (const puu &t) const {
		return t.fi * base + t.se;
	}
};
unordered_map <puu, int, My_Hash> mp;

struct node {
	ull hs1, hs2; string s;
};
il node calc(string s1, string s2) {
	int l = 0, r = s1.size() - 1;
	string t1 = "", t2 = "";
	while(s1[l] == s2[l]) t1 += s1[l], l++;
	while(s1[r] == s2[r]) t2 += s2[r], r--;
	reverse(t2.begin(), t2.end());
	t1 += (char)('z' + 1), t1 += t2;
	ull hs1 = 0, hs2 = 0;
	for(int i = l; i <= r; i++) {
		hs1 = (hs1 * base % Mod + s1[i] - 'a' + 1) % Mod;
		hs2 = (hs2 * base % Mod + s2[i] - 'a' + 1) % Mod;
	}
	return {hs1, hs2, t1};
}

struct Dat {
	string s; int id;
};
vector <Dat> S[N], T[N];
ll ans[N];

namespace AC {
	struct node {
		int son[27], fail; ll sum;
	}t[M];
	int tot = 1;
	il void init() {
		for(int i = 1; i <= tot; i++) {
			for(int j = 0; j < 27; j++) t[i].son[j] = 0;
			t[i].fail = t[i].sum = 0;
		}
		tot = 1;
	}
	il void insert(string s) {
		int u = 1;
		for(int i = 0; i < s.size(); i++) {
			int ch = s[i] - 'a';
			if(!t[u].son[ch]) t[u].son[ch] = ++tot;
			u = t[u].son[ch];
		}
		t[u].sum++;
	}
	il void build() {
		queue <int> q;
		for(int i = 0; i < 27; i++) {
			t[0].son[i] = 1;
		}
		t[1].fail = 0; q.push(1);
		while(!q.empty()) {
			int x = q.front(); q.pop();
			int fa = t[x].fail; t[x].sum += t[fa].sum;
			for(int i = 0; i < 27; i++) {
				int v = t[x].son[i];
				if(v) {
					t[v].fail = t[fa].son[i];
					q.push(v);
				}
				else {
					t[x].son[i] = t[fa].son[i];
				}
			}
		}
	}
	il ll query(string s) {
		int u = 1; ll ans = 0;
		for(int i = 0; i < s.size(); i++) {
			int ch = s[i] - 'a'; u = t[u].son[ch];
			ans += t[u].sum;
		}
		return ans;
	}
}

il void solve(int x) {
	AC::init();
	for(auto p : S[x]) AC::insert(p.s);
	AC::build();
	for(auto p : T[x]) ans[p.id] = AC::query(p.s);
}

il void main() {
	fin >> n >> q;
	for(int i = 1; i <= n; i++) {
		fin >> s[i][0] >> s[i][1];
		if(s[i][0] == s[i][1]) continue;
		node ret = calc(s[i][0], s[i][1]); puu res = mk(ret.hs1, ret.hs2);
		if(mp.find(res) == mp.end()) mp[res] = ++cnt;
		int id = mp[res]; S[id].push_back({ret.s, 0});
	}
	for(int i = 1; i <= q; i++) {
		string t1, t2; fin >> t1 >> t2;
		if(t1.size() != t2.size()) {
			ans[i] = 0; continue;
		}
		node ret = calc(t1, t2); puu res = mk(ret.hs1, ret.hs2);
		if(mp.find(res) == mp.end()) {
			ans[i] = 0; continue;
		}
		int id = mp[res]; T[id].push_back({ret.s, i});
	}
	for(int i = 1; i <= cnt; i++) solve(i);
	for(int i = 1; i <= q; i++) fout << ans[i] << '\n';
}
}
il void File() {freopen("replace.in", "r", stdin); freopen("replace.out", "w", stdout);}
bool End;
il void Usd() {cerr << (&Beg - &End) / 1024.0 / 1024.0 << "MB " << (double)clock() * 1000 / CLOCKS_PER_SEC << "ms\n";}
int main() {
	File();
	My_Space::main();
	Usd();
	return 0;
}

