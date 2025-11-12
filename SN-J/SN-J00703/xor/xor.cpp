#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace kong{bool st;}
namespace zhu{
int a[500500],n,k,dp[500500],sum[500500],mx[2002000];
string main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	memset(mx,-0x3f,sizeof mx);
	mx[0]=0;
	for(int i=2;i<=n+1;i++){
		dp[i]=max({0ll,mx[sum[i-1]^k]+1,dp[i-1]});
		mx[sum[i-1]]=max(mx[sum[i-1]],dp[i]);
	}
	cout<<dp[n]<<'\n';
	return "J组就是试机111";
}
}
namespace kong{bool ed;double MB(){return (&st-&ed)/1048576.0;}}
signed main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	cerr<<zhu::main()<<'\n'<<kong::MB()<<'\n';
}
