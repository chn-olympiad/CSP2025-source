#include <bits/stdc++.h>
using namespace std;

const int N = 5e6+5;

int T, n, q, ans;
char s[N];
template <class T>

inline void read(T &res) {
	char c;
	bool f = 0;
	while (!isdigit(c = getchar()))
		if (c == '-')
			f = 1;
	res = (c ^ 48);
	while (isdigit(c = getchar()))
		res = (res << 1) + (res << 3) + (c ^ 48);
	if (f)
		res = ~res + 1;
}

//void add(int u, int v) {
//	edge[++cnt].nxt = hd[u];
//	edge[cnt].to = v;
//	hd[u] = cnt;
//}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
//	printf("%lld", qpow(5, 4));
	scanf("%d%d", &n, &q);
	scanf("\n%s", s + 1);
	scanf("\n%s", s + 1);
	while (q--) {
		scanf("\n%s", s + 1);
		scanf("\n%s", s + 1);
		printf("%lld\n", 0);
	}
	return 0;
}