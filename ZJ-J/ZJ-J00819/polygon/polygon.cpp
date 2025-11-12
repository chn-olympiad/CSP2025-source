#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
int n;
int a[5005];
int dp[5005];
int sum=0,ans=0;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=sum;j>a[i];j--){
			ans=(ans+dp[j])%mod;
		}
		for(int j=sum;j>=1;j--){
			if(j+a[i]>5001){
				dp[5001]=(dp[5001]+dp[j])%mod;
			}
			else{
				dp[j+a[i]]=(dp[j+a[i]]+dp[j])%mod;
			}
		}
		dp[a[i]]=(dp[a[i]]+1)%mod;
		sum+=a[i];
		if(sum>5001) sum=5001;
	}
	cout<<ans;
	return 0;
}
