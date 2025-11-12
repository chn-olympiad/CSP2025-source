#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll N=1e5+10,M=210;
ll n;
struct node{
	ll x,y,z;
}a[N];
vector<ll>g;
ll dp[M][110][110];
void solve(){
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	if(n<=200){
		ll ans=0;
		for(ll i=1;i<=n;i++){
			for(ll j=0;j<=n/2;j++){
				for(ll k=0;k<=n/2;k++){
					if(j)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i].x);
					if(k)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i].y);
					if(n-i-j<=n/2)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i].z);
					ans=max(ans,dp[i][j][k]);
				}
			}
		}
		memset(dp,0,sizeof dp);
		cout<<ans<<endl;
		return ;
	}
	else{
		ll flag=0;
		for(ll i=1;i<=n;i++){
			if(a[i].z!=0){
				flag=1;
				break;
			}
		}
		if(!flag){
			ll ans=0,zuo=0,you=0;
			for(ll i=1;i<=n;i++){
				if(a[i].x>=a[i].y){
					zuo++;
					ans+=a[i].x;
				}
				else{
					you++;
					ans+=a[i].y;
				}
			}
			if(zuo>n/2){
				for(ll i=1;i<=n;i++){
					if(a[i].x>=a[i].y){
						g.push_back(a[i].x-a[i].y);
					}
				}
			}
			if(you>n/2){
				for(ll i=1;i<=n;i++){
					if(a[i].x<a[i].y){
						g.push_back(a[i].y-a[i].x);
					}
				}
			}
			sort(g.begin(),g.end());
			for(ll i=0;i<max(zuo,you)-(n/2);i++){
				ans-=g[i];
			}
			cout<<ans<<endl;
			return ;
		}
		if(flag){
			ll ans=0;
			for(ll i=1;i<=n;i++){
				ans+=max(max(a[i].x,a[i].y),a[i].z);
			}
			cout<<ans<<endl;
			return ;
		}
	}
}
signed main(){
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout);
	ll T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
//5 3 1
//4 2 4
//4 1 2
//3 1 4


