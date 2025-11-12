#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100001][4],b[100001],dp[201][201][201];
ll n,ans=INT_MIN;
void dfs(ll num,ll f,ll s,ll t,ll sum){
	if(dp[f][s][t]>sum){
		return;
	}
	dp[f][s][t]=sum;
	if(num==n+1){
		ans=max(ans,sum);
		return;
	}
	if(f<n/2)
		dfs(num+1,f+1,s,t,sum+a[num][1]);
	if(s<n/2)
		dfs(num+1,f,s+1,t,sum+a[num][2]);
	if(t<n/2)
		dfs(num+1,f,s,t+1,sum+a[num][3]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T;
	cin>>T;
	while(T--){
		memset(dp,0,sizeof dp);
		ans=INT_MIN;
		cin>>n;
		bool f2=1,f3=1;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=3;j++){
				cin>>a[i][j];
				if(i==2&&a[i][2]!=0){
					f2=0;
				}
				if(i==3&&a[i][3]!=0){
					f3=0;
				}
			}
		}
		if(f2&&f3){
			for(ll i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+n+1);
			ans=0;
			for(int i=n;i>=n/2+1;i--){
				ans+=b[i];
			}
			memset(b,0,sizeof b);
		}
//		else if(f3){
//			for(int i=1;i<=n;i++){
//				
//			}
//		}
		else dfs(0,0,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
/*

*/
