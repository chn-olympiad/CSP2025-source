#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
typedef double lf;
const int maxn = 505, maxN = 1 << 20;
const ll mod = 998244353;
int lowbit(const int &x) { return x & -x; }
int CountBit(int x) {
	int reply = 0;
	for (; x; x -= lowbit(x)) ++reply;
	return reply;
}

int n, N, m, c[maxn];
char s[maxn];
ll f[maxN][25];
ll DP() {
	ll reply = 0;
	N = 1 << n;
	f[0][0] = 1;
	for (int S = 1, siz; S < N; ++S) {
		siz = CountBit(S);
		for (int i = 0; i <= siz; ++i) {
			for (int x = 1, U; x <= n; ++x) {
				if (!(S & (1 << (x - 1)))) continue;
				U = S - (1 << (x - 1));
				if (s[siz] == '1' && siz - i < c[x]) (f[S][i] += i ? f[U][i - 1] : 0) %= mod; //able
				if (s[siz] == '0' || siz - 1 - i >= c[x]) (f[S][i] += f[U][i]) %= mod; //unable
			}
		}
	}
	for (int i = m; i <= n; ++i) reply += f[N - 1][i];
	return reply;
}

bool A = 1, B = 1;
int cntB = 0;


ll C[maxn][maxn];
void Init() {
	for (int i = 0; i <= n; ++i) C[i][0] = C[i][i] = 1;
	for (int i = 0; i <= n; ++i) 
		for (int j = 1; j < i; ++j) {
			(C[i][j] += C[i - 1][j] + C[i - 1][j - 1]) %= mod;
		}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d %s", &n, &m, s + 1);
	for (int i = 1; i <= n; ++i) {
		if (s[i] != '1') A = 0;
		if ((cntB += s[i] == '1') > 18) B = 0;
	}
	for (int i = 1; i <= n; ++i) scanf("%d", c + i);
	if (n <= 18) {
		printf("%lld", DP());
	} else if (A) {
		
	} else if (B) {
		
	}
	return 0;
}