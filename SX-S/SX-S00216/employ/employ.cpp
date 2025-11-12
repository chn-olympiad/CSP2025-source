#include <bits/stdc++.h>
using namespace std;
int s[505], a[505], b, m, n, flag;

int jiecheng(int n) {
	int ans;
	for (int i = 1; i <= n; i++) {
		ans *= i;
		ans = ans % 998244353;
	}
	return ans;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++) {
		scanf("%c", &cha);
		s[i] = cha - 48;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b);
		a[b]++;
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		if (s[i])
			flag++;
	}
	if (m == n) {
		if (flag != n) {
			printf("0");
			return 0;
		} else {
			printf("%d", jiecheng(n));
			return 0;
		}
	}
	if (m > flag) {
		printf("0");
		return 0;
	}
	if (m == 1) {

	}
	if (flag == n) {
		printf("%d", jiecheng(n));
		return 0;
	}
	return 0;
}