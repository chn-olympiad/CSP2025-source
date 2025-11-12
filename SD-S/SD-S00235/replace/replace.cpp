#include <bits/stdc++.h>
#define endl '\n'
#define debug(x) std::cerr << #x << " = " << x << ", LINE " << __LINE__ << endl;
#define split(x) std::cerr << "------------------------------------ SPLIT LINE ------------------------------------" << endl;
typedef long long ll;

const int MOD = 1e9 + 7, N = 2005;
std::string s1[N], s2[N];
std::set<std::string> s, ss;

ll qpow(ll a, ll b) { ll ans = 1; while (b) { if (b & 1) ans = ans * a % MOD; a = a * a % MOD; b >>= 1; } return ans; }

ll read() {
	ll res = 0; short f = 1; char ch = getchar();
	while (!('0' <= ch && ch <= '9')) { if (ch == '-') f = -f; ch = getchar(); }
	while ('0' <= ch && ch <= '9') { res = res * 10 + ch - 48; ch = getchar(); }
	return res * f;
}

std::string readstr() {
	std::string ret; char ch = getchar();
	while (ch <= 32) ch = getchar();
	while (ch > 32) { ret += ch; ch = getchar(); }
	return ret;
}

char readch() {
	char ch = getchar();
	while (ch < 32) ch = getchar();
	return ch;
}

void write(ll x) {
	if (x < 0) { putchar('-'); write(-x); }
	else if (x <= 9) { putchar(x + 48); }
	else { write(x / 10); putchar(x % 10 + 48); }
}

void write(std::string x) {
	for (char ch : x) putchar(ch);
}

void writeln(ll x) { write(x); putchar('\n'); }

void writeln(std::string x) { write(x); putchar('\n'); }

void writes(ll x) { write(x); putchar(' '); }

void writes(std::string x) { write(x); putchar(' '); }

void solve() {
	int n = read(), q = read();
	for (int i = 1; i <= n; i++) {
		s1[i] = readstr();
		s2[i] = readstr();
		s.insert(s1[i]);
		ss.insert(s2[i]);
	}
	
	while (q--) {
		std::string t1 = readstr(), t2 = readstr();
		int cnt = 0;
		if (s.find(t1) != s.end() && ss.find(t2) != ss.end()) cnt++;
		for (int len = 1; len <= n; len++) {
			for (int l = 0; (l + len - 1) < t1.size(); l++) {
				if (s.find(t1.substr(len, l)) != s.end() && ss.find(t2.substr(len, l)) != ss.end()) {
					bool flag = false;
					for (int i = 0; i < l; i++) {
						if (t1[i] != t2[i]) {
							flag = true;
							break;
						}
					}
					if (flag) continue;
					for (int i = l + len; i < n; i++) {
						if (t1[i] != t2[i]) {
							flag = true;
							break;
						}
					} 
					if (flag) continue;
//					writeln(t1.substr(len, l));
					cnt++;
				}
			}
		}
		writeln(cnt);
	}
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int t = 1;
	// t = read();
	while (t--) {
		solve();
	} return 0;
}

