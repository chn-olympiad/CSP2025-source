#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int a[N];
int n, k;
int sum[N];

struct node {
	int l, r;
} edge[4 * N];
int num = 0;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		sum[i] ^= sum[i - 1] ^ a[i];
		//cout << sum[i] << " ";
	}
	int cnt = 0;
	int ans = 0;
	while (cnt < n) {
		cnt++;
		for (int j = 1; j <= cnt; j++) {

			for (int i = j; i <= n; i += cnt) {
//				if (i + cnt - 1 <= n)
//					cout << i << " " << (sum[i + cnt - 1]^sum[i - 1] ) << endl;
				if (i + cnt - 1 > n)
					break;
				if ((sum[i + cnt - 1]^sum[i - 1]) == k && i + cnt - 1 <= n) {
					//	cout << i << " " << i + cnt << endl;
					bool flag1 = true;
					for (int t = 1; t <= num; t++) {
						if (!(i + cnt - 1 < edge[t].l || i > edge[t].r)) {
							flag1 = false;
							break;
						}
					}
					if (flag1) {
						ans++;
						edge[++num].l = i;
						edge[num].r = i + cnt - 1;
					}
				}
			}
			if (cnt == n)
				break;
		}
	}
	printf("%d", ans);
	return 0;
}
