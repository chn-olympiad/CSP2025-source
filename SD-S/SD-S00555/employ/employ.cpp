#include<iostream>
#include<cstdio>
#include<cstring> 
#define mod 998244353

using namespace std;

const int N=510;
const int S=300010;

int n,m;
char aa[N];
bool a[N];
int c[N];
long long dp[N][S];
long long fac[N];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	
	fac[0]=1;
	for(int i=1;i<=n;++i){
		fac[i]=(fac[i-1]*1ll*i)%mod;
	}
	
	scanf("%s",aa+1);
	
	bool ff=true;
	for(int i=1;i<=n;++i){
		a[i]=aa[i]-'0';
		if(a[i]==0) ff=false;
	}
	
	for(int i=1;i<=n;++i){
		scanf("%d",&c[i]);
	}
	
//	if(ff){
//		
//		
//		
//		return 0;
//	}
	
	if(n<=18){
		dp[0][0]=0;
		long long ans=0;
		if(a[1]){
			for(int j=1;j<=n;++j){
				if(c[j]>0) dp[1][(1<<j-1)]=1;
				else ++dp[1][0];
			}
		}
		else {
			dp[1][0]=n;
		}
		
		
		for(int i=1;i<=n;++i){
			for(int s=0;s<(1<<n);++s){
				
				if(a[i]==0){
					dp[i][s]=dp[i-1][s];
					continue;
				}
				int num=0;
				for(int j=1;j<=n;++j){
					if(s&(1<<j-1)){
						++num;
					}
				}
				
				if(num>i) continue;
				
				for(int j=1;j<=n;++j){
					if(s&(1<<j-1)){
						if(c[j]>(i-num)) dp[i][s]=(dp[i][s]+dp[i-1][s-(1<<j-1)])%mod;
						if(c[j]<=(i-num)) dp[i][s]=(dp[i][s]+dp[i-1][s])%mod;
					}
//					else{
//						
//					}
				}
//				cout<<dp[i][s]<<" ";
			}
//			cout<<endl;
		}
		for(int s=0;s<(1<<n);++s){
			int num=0;
			for(int j=1;j<=n;++j){
				if(s&(1<<j-1)){
					++num;
				}
			}
			if(num>=m) ans=(ans+dp[n][s])%mod;
		}
		printf("%lld\n",ans);
//		printf("%lld",((fac[n]-ans)%mod+mod)%mod);
		return 0;
	}
	else{
		
		printf("%lld",fac[n]);
	}
	
	
	
	
	return 0;
}
/*

3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

nonononononono!

*/
