#include<bits/stdc++.h>
using namespace std;
int const N=6*1e5;
#define ll long long
ll a[N],sum[N],dp[N];
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sum[1]=a[1];
	sum[0]=0;
	for(int i=2;i<=n;i++)
		sum[i]=sum[i-1]^a[i];
	if(sum[1]==k)dp[1]=1;
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=i;j>=1;j--){
			int temp=sum[i]^sum[j-1];
			if(temp==k){
				dp[i]=max(dp[i],1+dp[j-1]);
				break;
			}
		}
	}
	cout<<dp[n];
	return 0;
} 
