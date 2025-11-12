#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],ans,dp[25000010],ma,hyk;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=ma;j>=0;j--){
			if(dp[j]==0){
				continue;
			}
			dp[j+a[i]]+=dp[j];
			dp[j+a[i]]%=998244353;
			if(j+a[i]>a[i+1] && i>=2 && i!=n){
				ans+=dp[j+a[i]];
				ans%=998244353;
			}	
		}
		ma+=a[i];
	}
	cout<<ans;
	return 0;
}

