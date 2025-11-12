#include <bits/stdc++.h>
using namespace std;
struct IO {
	IO() {
		freopen("employ.in", "r", stdin);
		freopen("employ.out", "w", stdout);
	}
	~IO() {
		fclose(stdin);
		fclose(stdout);
	}
};
IO io;
const int N = 510;
int n, m;
char str[N];
int a[N], c[N], s[N];
namespace BFfacn {
	int p[15];
	void Main() {
		for (int i = 1; i <= n; i++) p[i] = i;
		int ans = 0;
		do {
			int cnt = 0;
			for (int i = 1; i <= n; i++)
				if (c[p[i]] > i - 1 - cnt && a[i])
					cnt++;
			ans += cnt >= m;
		} while (next_permutation(p + 1, p + n + 1));
		printf("%d\n", ans);
	}
}
int main() {
	scanf("%d%d%s", &n, &m, str + 1);
	for (int i = 1; i <= n; i++) {
		a[i] = str[i] - '0';
		s[i] = s[i - 1] + (a[i] == 0);
	}
	for (int i = 1; i <= n; i++) scanf("%d", c + i);
	if (n <= 10) {
		BFfacn::Main();
		return 0;
	}
	return 0;
}