#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
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

const int N = 205;
struct Ryan {
	ll x, y, z;
}a[N];
int n;
ll f[N][N >> 1][N >> 1];

void solve() {
	read(n);
	bool flag = true;
	for (int i = 1; i <= n; i++) {
		read(a[i].x), read(a[i].y), read(a[i].z);
		flag &= (a[i].y == a[i].z && a[i].y == 0);
	}
	if (flag) {
		std::sort(a + 1, a + n + 1, [](const Ryan &x, const Ryan &y) {
			return x.x < y.x;
		});
		ll ans = 0;
		for (int i = n; i > (n >> 1); i++)
			ans += a[i].x;
		write(ans), putchar('\n');
		return ;
	}
	
	if (n <= 200) {
		ll ans = 0;
		memset(f, 0, sizeof f);
		
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= min(i, n >> 1); j++) {
				for (int k = 0; k <= min(i - j, n >> 1); k++) {
					int ck = i - j - k;
					if (ck > (n >> 1)) continue;
					
					if (ck > 0) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k] + a[i].z);
					if (j > 0) f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k] + a[i].x);
					if (k > 0) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - 1] + a[i].y);
					
					if (i == n)
						ans = max(ans, f[i][j][k]);
				}
			}
		}
		
		write(ans), putchar('\n');
		return ;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int T; read(T);
	while (T --) solve();
	
	fclose(stdin), fclose(stdout);
	return 0;
}