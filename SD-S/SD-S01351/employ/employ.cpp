#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;
	char c=0;
	while(!isdigit(c)){if(c=='-')	f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c&15);c=getchar();}
	return x*f;
}
const int mod=998244353;
int n,m,s[510],a[510];
namespace sub1{
	bool check(){
		if(n<=18)
			return 1;
		return 0;
	}
	int dp[1<<18][20];
	void calc(){
		dp[0][0]=1;
		for(int i=0;i<(1<<n);i++)
			for(int j=0;j<n;j++){
				if(!dp[i][j])	continue;
				int nn=__builtin_popcount(i),die=nn-j;
				for(int k=0;k<n;k++){
					if(i>>k&1)	continue;
					if(s[nn+1]&&a[k+1]>die)
						dp[i+(1<<k)][j+1]=(dp[i+(1<<k)][j+1]+dp[i][j])%mod; 
					else dp[i+(1<<k)][j]=(dp[i+(1<<k)][j]+dp[i][j])%mod; 
				}
			}
		int ans=0;
		for(int i=m;i<n;i++)
			ans+=dp[(1<<n)-1][i];
		cout<<ans%mod;
	}
}
namespace sub2{
	bool check(){
		if(n==m)	return 1;
		return 0;
	}
	void calc(){
		for(int i=1;i<=n;i++)
			if(!s[i]||!a[i]){
				cout<<0<<"\n";
				return ;
			}
		int ans=1;
		for(int i=1;i<=n;i++)
			ans=ans*i%mod;
		cout<<ans;
	} 
}
namespace sub3{
	bool check(){
		if(m==1)	return 1;
		return 0;
	}
	int dp[510],sum[510],num[510];
	int Fac(int n){
		int ans=1;
		for(int i=1;i<=n;i++)
			ans=ans*i%mod;
		return ans;
	}
	void calc(){
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+s[i];
			num[a[i]]++; 
		}
		for(int i=1;i<=n;i++)
			num[i]=num[i-1]+num[i];
		dp[0]=1;
		for(int i=1;i<=n;i++){
			if(!s[i])
				dp[i]=dp[i-1];
			else
				dp[i]=dp[i-1]*(num[i-1]-sum[i-1])%mod;
		}
		cout<<(Fac(n)-dp[n]*Fac(n-sum[n])%mod+mod)%mod;
	} 
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		scanf("%1lld",&s[i]);
	for(int i=1;i<=n;i++)
		a[i]=read();
	if(sub1::check())
		sub1::calc();
	else if(sub2::check())
		sub2::calc();
	else if(sub3::check())
		sub3::calc();
	return 0;
}


