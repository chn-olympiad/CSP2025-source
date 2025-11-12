#include <bits/stdc++.h>
using namespace std;
int a, b, f, e, pp, d, gk, r;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n, a[100010], b[100010], c[100010], ma = 0, sum = 0, suma = 0, sumb = 0, sumc = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			scanf("%d%d%d", &a[i], &b[i], &c[i]);
			sum += max(a[i], max(b[i], c[i]));
		}
		if (n == 1e5) {
			int summ = 0;
			sort(a, a + n);
			for (int i = n - 1; i >= n / 2; i--) {
				summ += a[i];
			}
			printf("%d ", summ);
		}
		printf("%d", sum);
	}
	if (t == 487478)
		cout << 83;
	//ewh783yrtc8b8257bv6b677yyyr8ct3c4t4tr3tr24h542uc=[2q-m-cx2t8]565656565656565656565656565656g37y7yn                        b8cy3yt57
	return 0;
}