#include <bits/stdc++.h>
#define kn 503
using namespace std;

int n, m, ans, k;

char s[kn];
int c[kn], a[kn];
bool cmp(int x, int y) {
	return x < y;
}

int main() {
	freopen("employ.in", "w", stdin);
	freopen("employ.out", "r", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%c", &s[i]);
		if (s[i] == '1')
			k++, a[k] = i;
	}

	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	sort(c + 1, c + 1 + n, cmp);
	if (m == n) {
		ans = n, n--;
		for (int i = k; i > 0; i--) {
			ans *= n;
			n--;
		}
	}
	printf("%d", ans);
	return 0;
}