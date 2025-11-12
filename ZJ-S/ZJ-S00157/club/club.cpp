#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
bool f1,f2,f;
ll T,n,t,a[100005][4],ans;
ll dp[2][10001][10001];
ll num[100005];
void solve(){
	f=f1=f2=0;
	ans=0;
	cin>>n;
	t=n/2;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=3;j++) cin>>a[i][j];
		if(a[i][1]!=0) f=1;
		if(a[i][2]!=0) f1=1;
		if(a[i][3]!=0) f2=1;
	}
	if(f1==0&&f2==0){
		for(ll i=1;i<=n;i++) num[i]=a[i][1];
		sort(num+1,num+1+n);
		for(ll i=n;i>t;i--) ans+=num[i];
		cout<<ans<<endl;
		return ;
	}
	if(f==0&&f1==0){
		for(ll i=1;i<=n;i++) num[i]=a[i][3];
		sort(num+1,num+1+n);
		for(ll i=n;i>t;i--) ans+=num[i];
		cout<<ans<<endl;
		return ;
	}
	if(f==0&&f2==0){
		for(ll i=1;i<=n;i++) num[i]=a[i][2];
		sort(num+1,num+1+n);
		for(ll i=n;i>t;i--) ans+=num[i];
		cout<<ans<<endl;
		return ;
	}
	for(ll i=0;i<=1;i++)
		for(ll j=0;j<=n;j++)
			for(ll k=0;k<=n;k++)
				dp[i][j][k]=0;
	dp[1][1][0]=a[1][1];
	dp[1][0][1]=a[1][2];
	dp[1][0][0]=a[1][3];
	for(ll i=2;i<=n;i++){
		for(ll j=0;j<=i;j++){
			for(ll k=0;k<=i-j;k++){
				dp[i&1][j][k]=dp[(i-1)&1][j][k]+a[i][3];
				if(j!=0){
					dp[i&1][j][k]=max(dp[i&1][j][k],dp[(i-1)&1][j-1][k]+a[i][1]);
				}
				if(k!=0){
					dp[i&1][j][k]=max(dp[i&1][j][k],dp[(i-1)&1][j][k-1]+a[i][2]);
				}
				
				
			}
		}
	}
	for(ll i=0;i<=t;i++){
		for(ll j=t-i;j<=t;j++){
			ans=max(dp[n&1][i][j],ans);
		}
	}
	cout<<ans<<endl;
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>T;
	while(T--){
		solve();
	}	
	return 0;
}
