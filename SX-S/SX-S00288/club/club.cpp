#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

constexpr int N = 1e5 + 5;

int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')
			f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}

int T, n, ans;

struct node {
	int num, id;
	bool operator < (const node &p)const {
		if (num != p.num)
			return num > p.num;
		return id < p.id;
	}
} a[N][5];
multiset<int> s[5];

void Clean() {
	n = ans = 0;
	memset(a, 0, sizeof a);
	for (int i = 1; i <= 3; i++)
		s[i].clear();
}

void _main() {
	n = read();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++)
			a[i][j].num = read(), a[i][j].id = j;
		sort(a[i] + 1, a[i] + 4);
		s[a[i][1].id].insert(a[i][1].num - a[i][2].num);
		ans += a[i][1].num;
	}
	for (int i = 1; i <= 3; i++) {
		while ((int)s[i].size() > (n >> 1)) {
			ans -= (*s[i].begin());
			s[i].erase(s[i].begin());
		}
	}
	printf("%d\n", ans);
	Clean();
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	T = read();
	while (T--)
		_main();
	return 0;
}
