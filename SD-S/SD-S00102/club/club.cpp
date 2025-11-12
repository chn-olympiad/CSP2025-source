#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
const ll N=1e5+5;
ll T,n;
ll a[N],b[N],c[N];
ll maxn;
ll cnt1,cnt2,cnt3;
ll ans1,ans2,ans3;
ll dp[1000][1000];
ll ans[N][3];
ll num[N][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>n;
		maxn=0;
		memset(dp,0,sizeof dp);
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=3;j++){
				cin>>num[i][j];
			}
		}
		dp[1][1]=num[1][1];
		dp[1][2]=num[1][2];
		dp[1][3]=num[1][3];
		for(ll i=2;i<=n;i++){
			if(cnt1<=n/2){
				cnt1++;
				dp[i][1]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+num[i][1];
			}else{
				dp[i][1]=max(dp[i-1][2],dp[i-1][3])+num[i][1];
			}
			if(cnt2<=n/2){
				cnt2++;
				dp[i][2]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+num[i][2];
			}else{
				dp[i][2]=max(dp[i-1][1],dp[i-1][3])+num[i][2];
			}
			if(cnt3<=n/2){
				cnt3++;
				dp[i][3]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+num[i][3];
			}else{
				dp[i][3]=max(dp[i-1][1],dp[i-1][2])+num[i][3];
			}
		}
		maxn=max(dp[n][1],max(dp[n][2],dp[n][3]));
		cout<<maxn<<endl;
	}
	return 0;
}
