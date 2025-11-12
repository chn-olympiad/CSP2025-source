#include <bits/stdc++.h>
#define endl '\n'
#define debug(x) std::cerr << #x << " = " << x << ", LINE " << __LINE__ << endl;
#define split(x) std::cerr << "------------------------------------ SPLIT LINE ------------------------------------" << endl;
typedef long long ll;

const int MOD = 998244353;

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
	int n = read(), m = read(); m = n;
	std::string s = readstr();
	for (int i = 1; i <= n; i++) {
		if (read() == 0) m--;
	}
	ll mul = 1;
	for (int i = 2; i <= m; i++) {
		mul = mul * i % 998244353;
	}
	writeln(mul);
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int t = 1;
	// t = read();
	while (t--) {
		solve();
	} return 0;
}

