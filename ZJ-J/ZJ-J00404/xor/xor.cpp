#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500001],sum,ans,bb[1048577],ok;
bool b[1048577];
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	memset(b,0,sizeof b);
	b[k] = 1,bb[k] = 1;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		sum ^= a[i];
		if(b[sum]){
			if(bb[sum] > ok) ++ans,ok = i;
		}
		b[sum ^ k] = 1,bb[sum ^ k] = i + 1;
	}
	printf("%lld",ans);
	return 0;
}
