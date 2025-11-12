#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=555,mod=998244353;
int n,m,c[N],use[N];
namespace subtask1{
	int dp[20][262160];//dp[i][s] 招了 i 个人，面试过的子集为 j。 
	inline void solve(){
	  dp[0][0]=1;
	  int limit=(1<<n);
	  for(int s=1;s<limit;++s){
	  	int len=__builtin_popcountll(s);
		for(int i=1;i<=n;++i){
		  if(!((s>>(i-1))&1))continue;
		  int s2=s^(1<<(i-1));
		  for(int j=0;j<len;++j){
		  	int no=len-1-j;
			if(no>=c[i]||!use[len])dp[j][s]=(dp[j][s]+dp[j][s2])%mod;
			else dp[j+1][s]=(dp[j+1][s]+dp[j][s2])%mod;
		  }
		}
	  }
	  int ans=0;
	  for(int i=m;i<=n;++i)ans=(ans+dp[i][limit-1])%mod;
	  cout<<ans<<"\n";
	}
}
namespace subtask2{
	inline void solve(){
	  int sum=1;
	  for(int i=1;i<=n;++i)
		sum=sum*i%mod;
	  bool flag=1;
	  for(int i=1;i<=n;++i){
		if(!use[i]||!c[i])
		  flag=0;
	  }
	  if(flag)cout<<sum<<"\n";
	  else cout<<"0\n";
	}
}
namespace subtask3{
	int p[N],siz[N];
	inline void solve(){
	  for(int i=1;i<=n;++i)++siz[c[i]];
	  for(int i=1;i<=n;++i)siz[i]+=siz[i-1];
	  int res=1,cnt=0,delta=0;
	  for(int i=1;i<=n;++i){
		if(!use[i]){
		  ++cnt;
		  continue;
		}
		res=res*max(0ll,(siz[i-1]-delta))%mod;
		++delta;
	  }
	  int sum=1;
	  for(int i=1;i<=cnt;++i)sum=sum*i%mod;
	  res=res*sum%mod;
	  sum=1;
	  for(int i=1;i<=n;++i)sum=sum*i%mod;
	  cout<<((sum-res)%mod+mod)%mod<<"\n";
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	char qwq;
	int cnt=0;
	for(int i=1;i<=n;++i){
	  cin>>qwq;
	  use[i]=qwq-'0';
	  cnt+=use[i];
	}
	for(int i=1;i<=n;++i)
	  cin>>c[i];
	if(n<=18)subtask1::solve();
	else if(m==n)subtask2::solve();
	else subtask3::solve();
	return 0;
}