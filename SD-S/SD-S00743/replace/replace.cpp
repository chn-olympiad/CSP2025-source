//think begin 15:00
//write begin 15:30
#include  <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ull = unsigned long long;
using ll = long long;
using i128 = __int128;
#define fi first
#define se second
#define pk push_back

const int N = 5e6 + 5;
const int M = 2e5 + 5;
const int p = 1e9 + 7;
const ll p1 = 20090527;
const ll MOD = 323987351;

struct Trie{
	int son[26];
}t[N];
int idx = 1, dep[N], n, m, q, Fail[N];
vector<int> v[N];
string s1, s2, t1, t2, inst;
ull Hash[N], h[N], P[N];
ll ans;
ll HASH[N], H[N], P1[N];

void ins(string s, int num, int p = 1) {
	for(int i = 0, ch; i < s.size(); i ++) {
		ch = s[i] - 'a';
		if(!t[p].son[ch]) t[p].son[ch] = ++ idx;
		p = t[p].son[ch]; dep[p] = i + 1;
	}
	v[p].pk(num);
}
queue<int> qu;
void Get_Fail() {
	for(int i = 0; i < 26; i ++) t[0].son[i] = 1;
	Fail[1] = 0; qu.push(1);
	while(!qu.empty()) {
		int now = qu.front(); qu.pop();
		for(int i = 0; i < 26; i ++) {
			if(t[now].son[i]) {
				Fail[t[now].son[i]] = t[Fail[now]].son[i];
				qu.push(t[now].son[i]);
			} else t[now].son[i] = t[Fail[now]].son[i];
		}
	}
}
bool check(int a, int b, int c) {
	if(Hash[a] != h[b] - h[b - c] * P[c]) return 0;
	if(HASH[a] % MOD != ((H[b] - H[b - c] * P1[c] % MOD + MOD) % MOD)) return 0;
	return 1;
}
void query(string s, int bg, int lst, int p = 1) {
	for(int i = 0; i < s.size(); i ++) {
		int ch = s[i] - 'a';
		p = t[p].son[ch];
		if(i < lst) continue;
		if(i == lst && dep[p] < lst - bg + 1) break;
		int tmp = p;
		while(tmp > 1) {
			if(dep[tmp] < lst - bg + 1) break;
			if(v[tmp].size())
				for(auto to: v[tmp]) if(check(to, i, dep[tmp])) ans ++;
			tmp = Fail[tmp];
		} 
	}
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	P[0] = 1, P1[0] = 1;
	for(int i = 1; i < N; i ++) P[i] = P[i - 1] * p, P1[i] = P1[i - 1] * p1 % MOD;
	cin >> n >> q;
	for(int i = 1; i <= n; i ++) {
		cin >> s1 >> s2;
		ins(s1, i);
		int len = s1.size();
		for(int j = 0; j < len; j ++) Hash[i] = Hash[i] * p + s2[j],
									  HASH[i] = HASH[i] * p1 + s2[j], HASH[i] %= MOD;
	}
	Get_Fail();
	for(int i = 1; i <= q; i ++) {
		cin >> t1 >> t2;
		ans = 0;
		if(t1.size() != t2.size()) {
			cout << 0 << '\n';
			continue;
		}
		int len = t1.size();
		h[0] = t2[0], H[0] = t2[0];
		for(int j = 1; j < len; j ++) {
			h[j] = h[j - 1] * p + t2[j];
			H[j] = H[j - 1] * p1 + t2[j];
			H[j] %= MOD;
		}
		int lst = 0, bg = 0;
		for(int j = len - 1; ~j; j --) {
			if(t1[j] != t2[j]) {
				lst = j;
				break;
			}
		}
		for(int j = 0; j < len; j ++) {
			if(t1[j] != t2[j]) {
				bg = j;
				break;
			}
		}
		query(t1, bg, lst);
		cout << ans << '\n';
	}
	return 0;
}
//end 16:35
