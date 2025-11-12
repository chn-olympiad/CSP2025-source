#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[100020][100020];
ll a[100050], b[100020], c[100020];

int main() {
	//freopen("club.in","r",stdin);
	//freoprn("club.out","w",stdout);
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(a, 0, sizeof(a));
		memset(dp, 0, sizeof(dp));
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
			a[i] += a[i - 1];
			b[i] += b[i - 1];
			c[i] += c[i - 1];
		}

	}
	for (int len = 1; len <= n / 2; len++) {
		for (int l = 1; l <= n; l++) {
			int r = l + len;
		}
	}
}
retrun 0;
}