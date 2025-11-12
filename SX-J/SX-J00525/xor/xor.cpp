#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],b[500005],dp[500005],dp_max[500005],last[1100005];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	memset(last,-1,sizeof(last));
	scanf("%d%d", &n, &k);
	for (int i = 1;i <= n;i++)
		scanf("%d", &a[i]);
	for (int i = 1;i <= n;i++)
		b[i] = (b[i - 1] ^ a[i]);
	last[0] = 0;
	for (int i = 1;i <= n;i++){
		if (last[b[i] ^ k] != -1)
			dp[i] = dp_max[last[b[i] ^ k]] + 1;
		last[b[i]] = i;
		dp_max[i] = max(dp_max[i - 1],dp[i]);
	}
	printf("%d\n", dp_max[n]);
	return 0;
}
