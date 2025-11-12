#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5010,mod=998244353;
int n,a[N];
ll dp[N],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int k=a[n]+1;
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=a[i]+1;j<=k;j++)ans=(ans+dp[j])%mod;
		for(int j=k;j>=0;j--)dp[min(k,j+a[i])]=(dp[min(k,j+a[i])]+dp[j])%mod;
	}cout<<ans;
	return 0;
}
