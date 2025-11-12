#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
ll n,ans,cnt,dp[205][205][205];
struct node{
	int o,p,q;
}a[100005];
bool cmp(node x,node y){
	return x.o-x.p>y.o-y.p;
}
void solve(){
	cin>>n;
	ans=0;
	memset(dp,-0x3f,sizeof(dp));
	dp[0][0][0]=0;
	int ok=1;
	for(int i=1;i<=n;i++){
		cin>>a[i].o>>a[i].p>>a[i].q;
		if(a[i].q!=0){
			ok=0;
		}
	}
	if(ok&&n>200){
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(i<=n/2)ans+=a[i].o;
			else ans+=a[i].p;
		}
		cout<<ans<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		ll x=a[i].o,y=a[i].p,z=a[i].q;
		for(int j=0;j<=min(1LL*i,n/2);j++){
			for(int k=0;k<=min(1LL*i,n/2);k++){
				if(j>=1)dp[i][j][k]=dp[i-1][j-1][k]+y;
				if(k>=1)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+z);
				dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+x);
				if(i==n&&k+j>=n/2)ans=max(ans,dp[i][j][k]);
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}