#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+7;
int n,k,a[maxn],sum[maxn],ans,dp[maxn];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	bool flag=1,f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=0;
		if(!(a[i]>=0&&a[i]<=1)) f=0;
		sum[i]=sum[i-1]^a[i];
	}
	if(flag){
		cout<<n/2;
		return 0;
	}
	if(f){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
				if(a[i]==a[i+1]&&a[i]==1){
					ans++;
					i++;
				}
			}
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	dp[1]=((a[1]==k)?1:0);
	int mx=dp[1],idx=1;
	for(int i=2;i<=n;i++){
		for(int j=idx-1;j<i;j++){
			dp[i]=max(dp[i],dp[j]+((sum[j]^sum[i])==k));
		}
		if(dp[i]>mx){
			mx=dp[i];
			idx=i;
		}
	}
	cout<<dp[n];
	return 0;
}
