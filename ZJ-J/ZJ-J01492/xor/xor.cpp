#include<bits/stdc++.h>
using namespace std;
#define ll int
ll n,k,dp[105][105],a[500005],tag1,tag2,cnt,ans;
void dfs(ll last,ll sum){
	if(last==n+1){
		ans=max(ans,sum);
		return;
	}
	dfs(last+1,sum);
	for(ll i=last;i<=n;i++){
		if(dp[last][i]==k)dfs(i+1,sum+1);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)tag1=1;
		if(a[i]!=1&&a[i]!=0)tag2=1;
	}
	if(k==0&&tag1==0){
		cout<<n/2;
		return 0;
	}
	if(tag2==0){
		if(k==0){
			for(ll i=1;i<=n+1;i++){
				if(a[i]==1)cnt++;
				else{
					ans=ans+(i!=n+1)+cnt/2;
					cnt=0;
				}
			}
		}else{
			for(ll i=1;i<=n;i++)ans+=a[i];
		}
		cout<<ans;
		return 0;
	}
	for(ll i=1;i<=n;i++){
		dp[i][i]=a[i];
		for(ll j=i+1;j<=n;j++){
			dp[i][j]=dp[i][j-1]^a[j];
		}
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
