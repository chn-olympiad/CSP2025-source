#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace kong{bool st;}
namespace zhu{
int n,a[5050],dp[5050][5050],sum[5050],sm[5050];
const int mod=998244353;
int qpow(int x,int y){
	int ans=1;
	while(y){
		if(y&1){
			ans=ans*x%mod;
		}
		x=x*x%mod;
		y>>=1;
	}
	return ans;
}
string main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dp[0][0]=1;
	sum[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=a[i];j<=5000;j++){
			dp[i][j]=(dp[i][j]+sum[j-a[i]])%mod;
		}
		for(int j=0;j<=5000;j++){
			sum[j]=(sum[j]+dp[i][j])%mod;
		}
	}
	int ans=qpow(2,n);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=a[i];j++){
			ans=(ans-sm[j]+mod)%mod;
		}
		for(int j=0;j<=5000;j++){
			sm[j]=(sm[j]+dp[i][j])%mod;
		}
	}
	cout<<(ans-n-1+mod)%mod<<'\n';
	return "J组就是试机111";
}
}
namespace kong{bool ed;double MB(){return (&st-&ed)/1048576.0;}}
signed main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	cerr<<zhu::main()<<'\n'<<kong::MB()<<'\n';
}
