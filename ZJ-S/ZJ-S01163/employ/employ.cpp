#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

inline int read();
void write(int);
void writeln(int);

const int mod = 998244353;
int n, m, c[10005], ans;
bool vis[10005];
char s[10005];
void dfs(int k, int lim, int id) {
	if(k > n) return ans += (id >= m), void();
	if(n - lim + k < m) return ;
	vector <int> p;
	for(int i = 1; i <= n; i++) if(c[i] <= lim && !vis[i]) vis[i] = 1, p.pb(i);
	for(int i = 1; i <= k; i++) 
		if(!vis[i]) {
			vis[i] = 1;
			dfs(k + 1, lim + (s[k] != '1'), id + 1);
			vis[i] = 0;
		}
	for(int i = 0; i < p.size(); i++) vis[p[i]] = 0;	
}

signed main() {

	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	bool fl1 = 1;
	cin >> n >> m >> s + 1;
	for(int i = 1; i <= n; i++) if(s[i] == '0') fl1 = 0;
	for(int i = 1; i <= n; i++) cin >> c[i];
	if(fl1) {
		ans = 1;
		for(int i = 1; i <= n; i++) ans = ans * i % mod;
	}
	else dfs(1, 0, 0);
	cout << ans << '\n';
	
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

