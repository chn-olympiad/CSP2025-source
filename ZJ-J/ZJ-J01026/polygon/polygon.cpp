#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=5005,mod=998244353;
int n,sum,res,MAX_A;
int a[N],cnt[N];
int dp[N][N],ans[N];
int fac[N],infac[N],pow_2[N];
int f[N][205][105];

int dfs(int x,int sum,int maxx){
	if(x>n){
		if(sum>2*maxx) return 1;
		return 0;
	}
	if(f[x][sum][maxx]==-1)
		f[x][sum][maxx]=(dfs(x+1,sum,maxx)+dfs(x+1,min(sum+a[x],1ll*201),max(maxx,a[x])))%mod;	
	return f[x][sum][maxx];
}

int C(int x,int y){
	return fac[x]*infac[y]%mod*infac[x-y]%mod;
}

int mpow(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=ans*x%mod;
		y>>=1,x=x*x%mod;
	}
	return ans;
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	if(n<=500){
		memset(f,-1,sizeof(f));
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		printf("%lld",dfs(1,0,0));
		return 0;
	}
	fac[0]=infac[0]=pow_2[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=fac[i-1]*i%mod;
		infac[i]=mpow(fac[i],mod-2);
		pow_2[i]=pow_2[i-1]*2%mod;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		cnt[a[i]]++;
		MAX_A=max(MAX_A,a[i]);
	}
	for(int i=1;i<=MAX_A;i++){
		for(int j=0;j<=5000;j++){
			for(int t=0;t<=cnt[i];t++){
				if(j-t*i<0) dp[i][j]=(dp[i][j]+(dp[i-1][0]+1)*C(cnt[i],t)%mod)%mod;
				else dp[i][j]=(dp[i][j]+dp[i-1][j-t*i]*C(cnt[i],t)%mod)%mod;
			}
		}
	}
	for(int i=1;i<=MAX_A;i++){
		if(cnt[i]) ans[i]=(dp[i-1][i]*cnt[i]%mod+(pow_2[cnt[i]]+mod-cnt[i]-1)%mod*dp[i-1][0]%mod)%mod;
		if(cnt[i]>=3) ans[i]=(ans[i]+pow_2[cnt[i]]-1-cnt[i]-C(cnt[i],2)+3*mod)%mod;
		sum+=cnt[i];
		res=(res+ans[i])%mod;
	}
	printf("%lld",res);
	return 0;
}
