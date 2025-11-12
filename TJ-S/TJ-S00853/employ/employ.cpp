#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=550;
const int M=3e5;
const int mod=998244353;
int n,m,c[N],s[N],fac[N];
int f[N][N];
int dp[M][20];
string str;
bool flag1=true;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>str;
	for(int i=1;i<=n;++i)s[i]=str[i-1]-'0';
	for(int i=1;i<=n;++i)cin>>c[i];
	for(int i=1;i<=n;++i)if(s[i]!=0)flag1=false;
	if(n<=18){
		dp[0][0]=1;
		int S=(1<<n)-1;
		for(int i=0;i<=S;++i){
			int num=__builtin_popcount(i)+1;
			for(int k=0;k<=n;++k){
				for(int j=1;j<=n;++j){
					if((1ll<<(j-1))&i)continue;
//					cout<<i<<" "<<j<<" "<<k<<" "<<num<<endl;
					if(k<c[j] and s[num])(dp[i|(1ll<<(j-1))][k]+=dp[i][k])%=mod;	
					else (dp[i|(1ll<<(j-1))][k+1]+=dp[i][k])%=mod;
				}				
			}

		}
		int ans=0;
		for(int i=n-m;i>=0;--i)ans=(ans+dp[S][i])%mod;
		cout<<ans<<'\n';
		return 0;
	} 
	if(m==n){
		bool flag=true;
		for(int i=1;i<=n;++i)if(s[i]==0)flag=false;
		for(int i=1;i<=n;++i)if(c[i]==0)flag=false;
		if(flag){
			int ans=1;
			for(int i=1;i<=n;++i)ans=ans*i%mod;
			cout<<ans<<'\n';
		}
		else{
			cout<<0<<'\n';
		}
		return 0;
	}
	 
//	if(m==1){
//		fac[0]=1;
//		int num=0;
//		for(int i=1;i<=n;++i)num+=(s[i]=='0');
//		for(int i=1;i<=n;++i)fac[i]=fac[i-1]*i%mod;
//		for(int i=1;i<=n;++i){
//			for(int j=0;j<=n;++j)for(int k=0;k<=n;++k)f[j][k]=0;
//			for(int j=n;j>=1;--j){
//				if(j!=i){
//					for(int k=0;k<=n;++k){
//						(f[j][k]+=f[j+1][k+1]*fac[k+1])%=mod;
//						(f[j][k]+=f[j+1][k]*fac[(n-c[j])])
//					}
//				}
//			}
//		}
//		return 0;
//	}
	if(flag1){
		int ans=1;
		for(int i=1;i<=n;++i)ans=ans*(n-c[i]+1);
		cout<<ans<<'\n';
		return 0;
	}
} 
