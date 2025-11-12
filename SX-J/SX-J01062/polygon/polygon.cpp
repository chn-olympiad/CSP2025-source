#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
long long dp[5005*5005],ans,pw=1;
int n,a[5005],sum;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		if(i>=3){
			int tmp=0;
			for(int j=0;j<=a[i];j++) (tmp+=dp[j])%=mod;
			(ans+=pw-tmp+mod)%=mod;
		}
		sum+=a[i];
		for(int j=5000;j>=a[i];j--) (dp[j]+=dp[j-a[i]])%=mod;
		(pw*=2)%=mod;
	}
	cout<<ans;
	return 0;
}
