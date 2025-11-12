#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, k, a[500010], ans;
bool f;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] == 0) ans++;
		if (a[i] > 1) f = 1;
	}
	if (k == 0 && !f) {
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1 && a[i+1] == 1) {
				ans++;
				i++;
			}
		}
		printf("%d", ans);
	}
	else if (k == 1 && !f) {
		ans = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1) ans++;
		}
		printf("%d", ans);
	}
	return 0;
}
