#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n;
int a[5005];
int sum;
int dp[25000005];
int ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int sm=a[i]+1;sm<=sum;sm++){
			ans+=dp[sm];
			ans%=mod;
		}
		sum+=a[i];
		for(int sm=sum;sm>=0;sm--){
			if(sm>=a[i]){
				dp[sm]+=dp[sm-a[i]];
				dp[sm]%=mod;
			}
		}	
	}
	cout<<ans;
	return 0;
}

