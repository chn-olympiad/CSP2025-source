#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
const Int MaxN = 5e5+10;
Int n, k;
Int last = 0;
Int a[MaxN];
Int b[MaxN];
Int dp[MaxN];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld %lld", &n, &k);
	for(Int i = 1; i <= n; i ++){
		scanf("%lld", &a[i]);
		b[i] = b[i-1]^a[i];
	}
	for(Int i = 1; i <= n; i ++){
		dp[i] = dp[last];
		//cout << i << " ";
		for(Int j = i; j > last; j --){
			if((b[i]^b[j-1]) == k){
				dp[i] ++;
				//cout << j << " " << i << endl;
				last = i;
				break;
			}
		}
		//cout << endl;
	}
	printf("%lld",dp[n]);
	return 0;
}

