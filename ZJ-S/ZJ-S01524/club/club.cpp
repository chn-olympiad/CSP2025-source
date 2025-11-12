#include<bits/stdc++.h>
using namespace std;
#define ll int
ll t,n,ans,dp[105][105][105],f[105][105];
struct node{
	ll x,y,z;
}a[100005];
void dfs(ll x,ll sum,ll cnt1,ll cnt2,ll cnt3){
	if(cnt1>n/2||cnt2>n/2||cnt3>n/2)return;
	if(x==n+1){
		ans=max(ans,sum);
		return;
	}
	dfs(x+1,sum+a[x].x,cnt1+1,cnt2,cnt3);
	dfs(x+1,sum+a[x].y,cnt1,cnt2+1,cnt3);
	dfs(x+1,sum+a[x].z,cnt1,cnt2,cnt3+1);
}
bool cmp(node a,node b){
	return a.x>b.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ll sum1=0,sum2=0;
		for(ll i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			sum1+=a[i].y+a[i].z;
			sum2+=a[i].z;
		}
		if(n<=10){
			ans=-2e9;
			dfs(1,0,0,0,0);
			cout<<ans<<'\n';
			continue;
		}
		if(sum1==0){
			sort(a+1,a+1+n,cmp);
			ans=0;
			for(ll i=1;i<=n/2;i++)ans+=a[i].x;
			cout<<ans<<'\n';
			continue;
		}
		if(sum2==0){
			memset(f,0,sizeof f);
			for(ll i=0;i<=n/2;i++){
				for(ll j=0;j<=n/2;j++){
					sum1=0,sum2=0;
					if(i>0)sum1=f[i-1][j]+a[i+j].x;
					if(j>0)sum2=f[i][j-1]+a[i+j].y;
					f[i][j]=max(sum1,sum2);
				}
			}
			cout<<f[n/2][n/2]<<'\n';
			continue;
		}
		if(n<=200){
			ans=-2e9;
			for(ll i=0;i<=n/2;i++){
				for(ll j=0;j<=n/2;j++){
					for(ll k=0;k<=min(n/2,n-i-j);k++){
						sum1=0,sum2=0;
						ll sum3=0;
						if(i>0)sum1=dp[i-1][j][k]+a[i+j+k].x;
						if(j>0)sum2=dp[i][j-1][k]+a[i+j+k].y;
						if(k>0)sum3=dp[i][j][k-1]+a[i+j+k].z;
						dp[i][j][k]=max(sum1,max(sum2,sum3));
					}
				}
			}
			for(ll i=0;i<=n/2;i++){
				for(ll j=0;j<=n/2;j++){
					ll k=n-i-j;
					if(k<=n/2)ans=max(ans,dp[i][j][k]);
				}
			}
			cout<<ans<<'\n';
			continue;
		}
	}
	return 0;
}
