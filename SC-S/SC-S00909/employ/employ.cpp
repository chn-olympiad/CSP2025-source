#include <cstdio>
#include <string>
#include <iostream>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int MAXSZ = 1 << 20;
char ch, buf[MAXSZ], *p1, *p2;
#define ge() (p1 == p2 && (p2 = buf + fread(p1 = buf, 1, MAXSZ, stdin), p1 == p2) ? EOF : *p1++)
template <typename T_T>
inline void read(T_T &x) {
	x = 0;
	
	while (ch < '0' || '9' < ch) ch = ge();
	while ('0' <= ch && ch <= '9') {
		x = x * 10 + (ch ^ 48);
		ch = ge();
	}
}
template <typename T_T>
inline void write(T_T x) {
	if (x > 9) write(x / 10);
	putchar(x % 10 | 48); 
}
template <typename T_T>
inline T_T max(T_T a, T_T b) {return a > b ? a : b;}
template <typename T_T>
inline T_T min(T_T a, T_T b) {return a < b ? a : b;}
template <typename T_T>
inline void swap(T_T &x, T_T &y) {
	x ^= y;
	y ^= x;
	x ^= y; 
}

const int N = 1e5 + 5, mod = 998244353;
int n, m;
std::string s;
int c[N];
ll ans;
bool vis[N];

void dfs(int step, int cnt) {
	if (cnt + n - step + 1 < m) return ;
	if (step > n) {
		++ ans;
		return ;
	}
	
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = true;
			dfs(step + 1, cnt + ((s[step] - '0') == 1 && step - 1 - cnt < c[i]));
			vis[i] = false;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	std::cin >> s;
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	s = ' ' + s;
	 
	if (n <= 20) {
		dfs(1, 0);
		write(ans), putchar('\n');
		return 0;
	}
	return 0;
}