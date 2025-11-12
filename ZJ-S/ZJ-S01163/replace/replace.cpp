#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int read();
void write(int);
void writeln(int);

const int NN = 500005, mod = 998244353;
vector <int> s[NN], t;
string s1, s2;
map <int,int> mp;
int n, q, H[NN], dp[NN * 10], cnt;
struct D {
	map <int, int> S;
	int x;
} tr[NN * 10];
void qry(int n) {
	dp[0] = 1;
	for(int i = 1; i <= n; i++) {
		if(s1[i - 1] == s2[i - 1]) dp[i] = dp[i - 1];
		int x = i, now = 0;
		while(tr[now].S[t[x]] != 0) {
			now = tr[now].S[t[x]], dp[i] += tr[now].x * dp[x - 1], x--;
			if(x == 0) break;
		}
	}
	cout << dp[n] << '\n';
}
void add(vector <int> s) {
	int n = s.size(), now = 0;
	for(int i = 0; i < n; i++) {
		if(tr[now].S[s[i]] != 0) tr[now].S[s[i]] = ++cnt;
		now = tr[now].S[s[i]];
	}
}

signed main() {
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> s1 >> s2;
		int len = s1.size();
		for(int j = 0; j < len; j++) {
			int x = (s1[j] - 'a') % 26 + s2[j] - 'a';
			s[i].push_back(x);
		}
		add(s[i]);
		for(int j = len - 1; ~j; j--) {
			int x = (s1[j] - 'a') % 26 + s2[j] - 'a';
			H[i] = (H[i] * 3 % mod + x) % mod;
		}
		mp[H[i]]++;
	}
	for(int i = 1; i <= q; i++) {
		cin >> s1 >> s2;
		if(s1.size() != s2.size()) { cout << "0\n"; continue; }
		int len = s1.size();
		t.resize(len + 1);
		dp[0] = 1;
		for(int j = 0; j < len; j++) {
			dp[j + 1] = 0;
			int x = (s1[j] - 'a') % 26 + s2[j] - 'a';
			t[j + 1] = x;
		}
		qry(len);
	}
	
	return 0;
}

inline int read() {
	int res = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') f = (ch == '-' ? -1 : 1), ch = getchar();
	while(ch >= '0' && ch <= '9') res = (res << 1) + (res << 3) + (ch ^ 48), ch = getchar();
	return res * f;
}

void write(int x) {
	static int sta[35];
	int top = 0;
	do {
		sta[top++] = x % 10;
		x /= 10;
	} while(x);
	while(top) putchar(sta[--top] ^ 48);
}

void writeln(int x) {
	write(x);
	putchar('\n');
}
