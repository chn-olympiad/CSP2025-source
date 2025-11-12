//Fight until the end like I promised to
#include<bits/stdc++.h>
#define AK 0
#define int long long
#define D(x) cout<<#x<<": "<<x<<'\n'
#define De(x) cout<<#x<<": "<<x<<' '
#define ctn continue
#define brk break
#define space putchar(' ')
#define enter putchar('\n')
#define pii pair<int,int>
#define mkp make_pair
#define up(l,r,i) for(int i=l;i<=r;i++)
#define dn(r,l,i) for(int i=r;i>=l;i--)
using namespace std;
inline int read(){
	bool f = 0;
	int x = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') f = 1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + (ch - '0'), ch = getchar();}
	return f ? -x : x;
}
const int N = 2e5 + 7, mod1 = 1e9 + 7, mod2 = 99244353, base1 = 330381, base2 = 251;
int n, m, tot;
#define pcc pair<char, char>
#define PII pair<pii, pii >
inline bool check(int x){
	return x < 'a' || x > 'z';
}
string s1[N], s2[N];
vector<pcc> buf;
struct tree{
	int tot;
	vector<vector<int> > G;
	vector<pcc> p;
	vector<bool> ed;
	vector<int> sum;
	inline void build(){
		tot = 0;
		G.emplace_back(vector<int>());
		p.emplace_back(pcc());
		ed.emplace_back(0);
		sum.emplace_back(0);
	}
	inline void add(int u, int i){
		bool flag = 0;
		if(i == buf.size()){
			sum[u]++;
			return;
		}
		for(auto v : G[u]){
			if(p[v] == buf[i]){
				flag = 1;
				add(v, i + 1);
				brk;
			}
		}
		if(!flag){
			tot++;
			G.emplace_back(vector<int>());
			G[u].emplace_back(tot);
			p.emplace_back(buf[i]);
			ed.emplace_back(0);
			sum.emplace_back(0);
			add(tot, i + 1);
		}
	}
	inline int ask(int u, int i){
//		De(u), De(p[u].first), De(p[u].second), D(sum[u]);
		int res = sum[u];
		if(i == buf.size()) return res;
		for(auto v : G[u]){
			if(p[v] == buf[i] || (p[v].first == buf[i].first && check(p[v].second)) || (p[v].second == buf[i].second && check(p[v].first)) || (check(p[v].first) && check(p[v].second))){
				res += ask(v, i + 1);
			}
		}
		return res;
	}
}a[N];
map<PII, int> vis;
vector<pii> hs[N];
signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	n = read(), m = read();
	up(1, n, i){
		cin >> s1[i] >> s2[i];
		int len = s1[i].size();
		s1[i] = " " + s1[i], s2[i] = " " + s2[i];
		int l = 0, r = 0;
//		De(s1[i]), D(s2[i]);
		up(1, len, j){
			if(s1[i][j] != s2[i][j]){
				if(!l) l = j;
			}
		}
		dn(len, 1, j){
			if(s1[i][j] != s2[i][j]){
				if(!r) r = j;
			}
		}
		pii hs1 = mkp(0, 0);
		up(l, r, j){
			int x = hs1.first, y = hs1.second;
			hs1 = mkp((x * base1 + s1[i][j]) % mod1, (y * base2 + s1[i][j]) % mod2);
		}
		pii hs2 = mkp(0, 0);
		up(l, r, j){
			int x = hs2.first, y = hs2.second;
			hs2 = mkp((x * base1 + s2[i][j]) % mod1, (y * base2 + s2[i][j]) % mod2);
		}
//		De(hs1.first), De(hs1.second), De(hs2.first), D(hs2.second);
		PII hsh = mkp(hs1, hs2);
		buf.clear();
		buf.resize(max(0ll, max(l - 1, len - r)));
		for(int j = l - 1; j >= 1; j--) buf[l - j - 1].first = s1[i][j];
		for(int j = r + 1; j <= len; j++) buf[j - r - 1].second = s1[i][j];
//		for(auto wzb : buf) De(wzb.first), D(wzb.second);
		if(vis.count(hsh)){
			a[vis[hsh]].add(0, 0);
		}
		else{
			tot++;
			vis[hsh] = tot;
			a[tot].build();
			a[tot].add(0, 0);
		}
	}
	up(1, m, i){
		cin >> s1[i] >> s2[i];
		int len = s1[i].size();
//		De(s1[i]), D(s2[i]);
		s1[i] = " " + s1[i], s2[i] = " " + s2[i];
		int l = 0, r = 0;
		up(1, len, j){
			if(s1[i][j] != s2[i][j]){
				if(!l) l = j;
			}
		}
		dn(len, 1, j){
			if(s1[i][j] != s2[i][j]){
				if(!r) r = j;
			}
		}
		pii hs1 = mkp(0, 0);
		up(l, r, j){
			int x = hs1.first, y = hs1.second;
			hs1 = mkp((x * base1 + s1[i][j]) % mod1, (y * base2 + s1[i][j]) % mod2);
		}
		pii hs2 = mkp(0, 0);
		up(l, r, j){
			int x = hs2.first, y = hs2.second;
			hs2 = mkp((x * base1 + s2[i][j]) % mod1, (y * base2 + s2[i][j]) % mod2);
		}
//		De(hs1.first), De(hs1.second), De(hs2.first), D(hs2.second);
		PII hsh = mkp(hs1, hs2);
		if(!vis.count(hsh)){
			puts("0");
			ctn;
		}
		else{
			buf.clear();
			buf.resize(max(0ll, max(l - 1, len - r)));
			for(int j = l - 1; j >= 1; j--) buf[l - j - 1].first = s1[i][j];
			for(int j = r + 1; j <= len; j++) buf[j - r - 1].second = s1[i][j];
//			for(auto wzb : buf) De(wzb.first), D(wzb.second);
			printf("%lld\n", a[vis[hsh]].ask(0, 0));
		}
	}
	return AK;
}
