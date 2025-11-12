#include <bits/stdc++.h>
using namespace std;
int a[500005];
int s[500005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s[i] = s[i - 1] ^ a[i];
	}
	int ans = 0;
	for (int len = 0; len < n; len++) {
		int cnt = 0, l = len;
		for (int i = len + 1; i <= n; i++) {
			int x = s[i] ^ s[l];
			if (x == k) {
//				cout << len << ' ' << l << ' ' << i << endl;
				cnt++;
				l = i ;
			}
		}
		ans = max(ans, cnt);
	}
	printf("%d", ans);
	return 0;
}
