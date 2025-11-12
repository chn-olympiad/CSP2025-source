#include<bits/stdc++.h>
#define forUp(i,a,b) for(int i=(a);i<=(b);++i)
#define forUP(i,a,b) for(int i=(a);i<(b);++i)
#define forDown(i,a,b) for(int i=(a);i>=(b);--i)
constexpr int N=5000+10,mod=998244353;using namespace std;
int n,A[N],dp[N],ans,sum;
int qp(int x,int y){int ans=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)ans=1ll*ans*x%mod;return ans;}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	forUp(i,1,n)cin>>A[i];
	sort(A+1,A+n+1);
	dp[0]=1;
	forUp(i,1,n){
		sum=0;
		forUp(j,0,A[i])sum=(sum+dp[j])%mod;
		ans=(ans+qp(2,i-1))%mod;
		ans=(ans+mod-sum)%mod;
		forDown(j,5000,A[i])dp[j]=(dp[j]+dp[j-A[i]])%mod;
	}
	cout<<ans;
	return 0;
}