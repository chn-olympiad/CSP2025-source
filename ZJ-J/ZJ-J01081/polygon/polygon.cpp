#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[10010],k=0;
bool vis[10010];
ll a[10010];
const ll mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll ans=0;
	ll maxn=min(5000*1ll,a[1]+a[2]);
	dp[a[1]]++;
	dp[a[2]]++;
	vis[a[1]]=vis[a[2]]=1;
	if(a[1]+a[2]>5000){
		k++;
	}
	else{
		dp[maxn]++;
		vis[maxn]=1;
	}
	for(int i=3;i<=n;i++){
		ans=(ans+k)%mod;
		k=(k*2)%mod;
		for(int j=maxn;j>=1;j--){
			if(vis[j]){
				if(j>a[i]){
					ans=(ans+dp[j])%mod;
				}
				if(a[i]+j>5000){
					k=(k+dp[j])%mod;
				}
				else{
					dp[a[i]+j]=(dp[a[i]+j]+dp[j])%mod;
					vis[a[i]+j]=1;
				}
			}
		}
		vis[a[i]]=1;
		dp[a[i]]=(dp[a[i]]+1)%mod;
		maxn=min(5000*1ll,maxn+a[i]);
	}
	cout<<ans<<'\n';
	return 0;
}
