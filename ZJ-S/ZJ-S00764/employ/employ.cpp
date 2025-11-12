#include<bits/stdc++.h>
using namespace std;
const int N=510,mod=998244353;
int n,m,c[N],b[N];
string s;
long long dp[2000000][20];
int f(int x){
	int cnt=0;
	while(x){
		cnt++;
		x=x&(x-1);
	}
	return cnt;
}
int flag;
void dfs(int u,int sum,int cnt){
	if(cnt==flag){
		for(int i=1;i<=n;i++){
			if(sum&(1<<(i-1))){
				for(int j=0;j<flag;j++){//
					if(c[i]>flag-1-j&&s[flag-1]=='1')dp[sum][j+1]=(dp[sum][j+1]+dp[sum-(1<<(i-1))][j])%mod;
					else dp[sum][j]=(dp[sum][j]+dp[sum-(1<<(i-1))][j])%mod;
				}
			}
		}
		return;
	}
	if(u==n+1||n-u+1+cnt<flag){
		return;
	}
	dfs(u+1,sum,cnt);
	dfs(u+1,sum+(1<<(u-1)),cnt+1);
	return;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;
	int cnt0=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];b[i]=i;
		if(c[i]==0)cnt0++;
	}
	if(n<=10){
		int ret=0;
		do{
			int cnt=0,cntm=0;
			for(int i=1;i<=n;i++){
				if(c[b[i]]<=cnt||s[i-1]=='0'){
					cnt++;
				}else cntm++;
			}
			if(cntm>=m)ret++;
		}while(next_permutation(b+1,b+1+n));
		printf("%d",ret);
		return 0;
	}
	if(n<=18){
		dp[0][0]=1;
		for(int i=1;i<=n;i++){
			flag=i;
			dfs(1,0,0);
		}
		long long sum=0;
		for(int i=m;i<=n;i++){
			sum=(sum+dp[(1<<(n))-1][i])%mod;
		}
		printf("%lld",sum);
		return 0;
	}
	if(m==n){
		if(cnt0)printf("0");
		for(int i=0;i<n;i++){
			if(s[i]=='0'){
				printf("0");
				return 0;
			}
		}
		long long sum=n;
		for(int i=n-1;i>=2;i--){
			sum=sum*i%mod;
		}
		printf("%lld",sum);
		return 0;
	}
	if(m==1){
		long long sum=n;
		for(int i=n-1;i>=2;i--){
			sum=sum*i%mod;
		}
		printf("%lld",sum);
		return 0;
	}
	long long sum=n;
	for(int i=n-1;i>=2;i--){
		sum=sum*i%mod;
	}
	printf("%lld",sum);
	return 0;
}
