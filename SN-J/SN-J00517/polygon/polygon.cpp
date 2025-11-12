#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005],sum[5005]={0},dp[5005]={0};
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	int d1[sum[n]+1]={0},d2[sum[n]+1]={0};
	
	for(int i=2;i<=n;i++){
		for(int j=1;j<=sum[i];j++)d1[j]=0;
		for(int j=1;j<=sum[i];j++){
			if(j>a[i]){
				dp[i]+=d2[j];
				dp[i]%=mod;
			}
			d1[j+a[i]]+=d2[j];
			d1[j+a[i]]%=mod;
		}
		for(int j=1;j<=sum[i];j++){
			d2[j]=d1[j];
			d2[j]%=mod;
		}
		for(int j=1;j<i;j++){
			d2[a[j]+a[i]]++;
			d2[a[j]+a[i]]%=mod;
		}
	}
	
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=dp[i];
		ans%=mod;
	}
	cout<<ans;
	
	return 0;
}
