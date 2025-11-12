#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
const long long mod=998244353;
long long n,k,a[maxn],s,sum,vis[maxn],b[maxn],dp[maxn];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		k=max(a[i],k);
	}
	k=2*k+1;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=a[i]+1;j<=k;j++){
			dp[i]=(dp[i]+vis[j])%mod;
			//if(i==5 && vis[j]) cerr<<j<<" "<<vis[j]<<"\n";
		}
		dp[i]=(dp[i]+s)%mod;
		s=(s*2)%mod;
		for(int j=k;j>=1;j--){
			if(j+a[i]>k){
				s=(s+vis[j]+b[j])%mod;
			}
			else vis[j+a[i]]=(vis[j+a[i]]+vis[j]+b[j])%mod;
		}
		b[a[i]]=(b[a[i]]+1)%mod;
	}
	for(int i=1;i<=n;i++){
		sum=(sum+dp[i])%mod;
	}
	cout<<sum<<"\n";
	return 0;
}