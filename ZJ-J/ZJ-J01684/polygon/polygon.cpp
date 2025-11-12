#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10;
const int mod=998244353;
int n,ans,sum;
int a[N],f[N],dp[N*N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(1+a,1+a+n);
	for(int i=1;i<=n;i++) f[i]=f[i-1]+a[i];
	dp[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=f[n];j>=a[i];j--){
			dp[j]+=dp[j-a[i]];
			if(j>a[i]*2) ans+=dp[j-a[i]];
			dp[j]%=mod;
			ans%=mod; 
		}
	cout<<ans; 
	return 0;
}