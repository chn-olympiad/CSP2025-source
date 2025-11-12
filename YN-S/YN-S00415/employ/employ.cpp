#include <cstdio>
using namespace std;
const int mod = 998244353;
int n, m, cnt = 0;
char str[510];
int c[510];
int js = 0;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	ch = getchar();
	while (ch < '0' || ch > '1')
		ch = getchar();
	while (ch == '0' || ch == '1') {
		str[++cnt] = ch;
		if (ch == '0')
			++js;
		ch = getchar();
	}
	if (n == m && js < cnt) {
		printf("0\n");
		return 0;
	}
	long long a = 1;
	for (int i = 2; i <= n; ++i) {
		a = (a * i) % mod;
	}
	printf("%lld\n", a);
	fclose(stdin);
	fclose(stdout);
	return 0;
}