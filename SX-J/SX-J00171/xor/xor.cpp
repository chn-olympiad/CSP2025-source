#include<bits/stdc++.h>
#define int unsigned int
using namespace std;
const int N=5e5+10;
int a[N],sum[N],dp[N];

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=i;j>=1;j--){
			if(sum[i]==(k^sum[j-1])){
				dp[i]=max(dp[i],dp[j-1]+1);
				break;
			}
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}