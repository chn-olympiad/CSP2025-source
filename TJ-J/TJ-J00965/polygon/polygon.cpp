#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cassert>
#include<cstdlib>
#include<ctime>
const int N=505,M=5005,mod=998244353;
int n;
int a[N];
namespace Force{
	void solve(){
		int ans=0;
		for(int s=0;s<(1<<n);s++){
			int maxa=0,sum=0;
			for(int i=1;i<=n;i++){
				if(s>>(i-1)&1) maxa=std::max(maxa,a[i]),sum+=a[i];
			}
			if(sum>2*maxa) ans++;
		}
		printf("%d\n",ans);
	}
}
namespace Better{
	int sm,t=0;
	struct rec{
		int v,cnt;
	}b[N];
	long long C[N][N];
	long long dp[N][M];
	long long get(int x,long long sum){
		if(x>sm) return sum>2ll*b[sm].v;
		return dp[x][sum];
	}
	
	void solve(){
		for(int i=0;i<=n;i++){
			for(int j=0;j<=i;j++){
				if(j==0||j==i) C[i][j]=1;
				else C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
			}
		}
		
		std::sort(a+1,a+n+1);
		for(int i=1,j=1;i<=n&&j<=n;){
			while(j<=n&&a[i]==a[j]) j++;
			j--;
			b[++t].v=a[i],b[t].cnt=j-i+1;
			i=++j;
		}
		long long ans=0;
		for(int m=1;m<=t;m++){
			sm=m;
			for(int j=1;j<=m;j++){
				for(int k=0;k<=5001;k++) dp[j][k]=0;
			}
			for(int x=m;x>=1;x--){
				for(int sum=0;sum<=5001;sum++){
					long long ans=0;
					int k=0;
					if(x==m) k=1;
					for(int i=k;i<=b[x].cnt;i++){
						long long t=std::min(5001ll,(sum+((long long)b[x].v*i)%mod)%mod);
						ans+=(get(x+1,t)*C[b[x].cnt][i])%mod;
						ans%=mod;
					}
					dp[x][sum]=ans;
				}
				
			}
			ans+=get(1,0);
			ans%=mod;
		}
		printf("%lld\n",ans);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n<=10) Force::solve();
	else 
		Better::solve();
	return 0;
}
