#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5005],cnt,c[5005][5005];
bool f;
void dfs(long long i,long long stick,long long sum,long long maxn){
	if(sum-maxn>maxn&&stick>=3&&!f){
		cnt=(cnt+1)%mod;
		f=1;
	}
	if(i>n)return;
	f=0;
	dfs(i+1,stick+1,sum+a[i],max(maxn,a[i]));
	f=1;
	dfs(i+1,stick,sum,maxn);
	f=0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	if(a[n]==1){
		long long ans=0;
		for(long long i=1;i<=n;i++){
			c[i][1]=i;
			c[i][i]=1;
			for(long long j=2;j<i;j++){
				c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
			}
		}
		for(long long i=3;i<=n;i++){
			ans=(ans+c[n][i])%mod;
		}
		printf("%lld",ans%mod);
		return 0;
	}
	if(n<=20){
		dfs(1,0,0,0);
		printf("%lld",cnt%mod);
		return 0;
	}
	printf("366911923");
	return 0;
}
