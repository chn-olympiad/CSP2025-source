#include <bits/stdc++.h>

using namespace std;

int n, m;
char s[501];
int a[501];
int c[501];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) 
		a[i] = s[i] - '0';
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	bool ok = true;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0) {
			ok = false;
			break;
		}
	}
	if (!ok) {
		if (n == m) {
			printf("0");
			return 0;	
		}
	} else {
		if (n == m) {
			long long ans = 1;
			while (n != 0) {
				ans *= n;
				n--;
			}
			printf("%lld", ans);
			return 0;
		} else {
			long long ans = 1;
			while (m != 0) {
				ans *= n;
				n--;
				m--;
			}
			printf("%lld", ans);
			return 0;
		}
	}
	return 0;
}
