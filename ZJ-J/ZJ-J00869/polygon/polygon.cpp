#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
int l[5005],n;
namespace CASE1{
	void solve(){
		if(n<3){cout<<0<<endl;return;}
		int ans=0,a=l[1],b=l[2],c=l[3];
		if(a+b>c && a+c>b && b+c>a) ans++;
		//cout<<a<<' '<<b<<' '<<c<<endl;
		cout<<ans<<endl;
	}
}
// please deleted it
namespace CASE2{ // dp idx max sum
	int dp[4][22][202][2002];
	int dfs(int choosenum,int nd,int maxx,int sum){
		if(nd==n+1){
			//cout<<choosenum<<' '<<nd<<' '<<maxx<<' '<<sum<<endl;
			return choosenum>=3 && sum>maxx*2; 
		}
		if(dp[choosenum][nd][maxx][sum]!=-1){
			return dp[choosenum][nd][maxx][sum];
		}
		int res=0;
		res+=dfs(choosenum,nd+1,maxx,sum);
		res+=dfs(min(choosenum+1,3ll),nd+1,max(maxx,l[nd]),sum+l[nd]);
		res%=MOD;return dp[choosenum][nd][maxx][sum]=res;
	}
	void solve(){
		memset(dp,-1,sizeof(dp));
		int ans=dfs(0,1,0,0);
		cout<<ans%MOD<<endl;
	}
}
namespace CASE3{ // dp idx max sum
	int dp[502][502];
	int dfs(int choosenum,int nd){
		if(nd==n+1){
			return choosenum>=3;
		}
		if(dp[choosenum][nd]!=-1){
			return dp[choosenum][nd];
		}
		int res=0;
		res+=dfs(choosenum,nd+1);
		res+=dfs(choosenum+1,nd+1);
		res%=MOD;return dp[choosenum][nd]=res;
	}
	void solve(){
		memset(dp,-1,sizeof(dp));
		int ans=dfs(0,1);
		cout<<ans%MOD<<endl;
	}
}
namespace CASE4{
	int dp[502][502];
	int dfs(int choosenum,int nd,int maxx,int sum){
		if(nd==n+1){
			return choosenum>=3 && sum>maxx*2; 
		}
		if(dp[choosenum][nd]!=-1){
			return dp[choosenum][nd];
		}
		int res=0;
		res+=dfs(choosenum,nd+1,maxx,sum);
		res+=dfs(min(choosenum+1,3ll),nd+1,max(maxx,l[nd]),sum+l[nd]);
		res%=MOD;return dp[choosenum][nd]=res;
	}
	void solve(){
		memset(dp,-1,sizeof(dp));
		int ans=dfs(0,1,0,0);
		cout<<ans%MOD<<endl;
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;int maxx=0,m=1;
	for(int i=1;i<=n;i++){
		cin>>l[i];l[i]%=MOD;maxx=max(maxx,l[i]),m*=l[i],m%=MOD;
	}
	if(n<=3) CASE1::solve();
	else if(n<=500 && maxx==1) CASE3::solve();
	else if(n<=20 && maxx<=100) CASE2::solve();
	else if(n<=500) CASE4::solve();
	else cout<<m<<endl;
	return 0;
}

