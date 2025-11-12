#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const ll N=505,MOD=998244353;
ll n,m,a[N],num[N],ans=0,dp[N][N];
ll ji[N];
char s[N];
bool f[N];
ll fpow(ll a,ll b){
	ll ret=1;
	while(b){
		if(b&1)
			ret*=a,ret%=MOD;
		a*=a,a%=MOD,b/=2;
	}
	return ret;
}
ll jie(int t){
	if(t==1)
		return 1;
	if(ji[t]>0)
		return ji[t];
	return ji[t]=(t*jie(t-1))%MOD;
}
void dfs(int t){
	if(t>n){
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(a[num[i]]>i-1-cnt&&s[i]=='1')
				cnt++;
		}
		if(cnt>=m)
			ans++;
		return;
	}
	for(int i=1;i<=n;++i){
		if(f[i]==0){
			f[i]=1,num[t]=i;
			dfs(t+1);
			f[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	if(n<=10){
		dfs(1);
		printf("%d\n",ans);
		return 0;
	}
	if(m==1){
		printf("%lld\n",(jie(n-1)*jie(n))%MOD);
		return 0;
	}
	bool special_all_1=1;
	for(int i=1;i<=n;++i){
		if(s[i]=='0'){
			special_all_1=0;
			break;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<i;++j){
			dp[i][j]+=dp[i-1][j],dp[i][j]%=MOD;
			if(s[i]=='1'&&a[i]>i-1-j)
				dp[i][j+1]=1;
		}
	}
	for(int i=m;i<=n;++i)
		ans+=dp[n][i],ans%=MOD;
	printf("%lld\n",ans);
	return 0;
}
