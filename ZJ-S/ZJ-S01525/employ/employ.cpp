#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int N=500+5;
char st[N];
int c[N];
const int B=(1<<18)+5;

const int mod=998244353;

int dp[20][B][20];
int cnt[N];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",st+1);
	for(int i=0;i<n;i++){
		scanf("%d",c+i);
	}
	if(n<=18){//subtask 1~5
		dp[0][0][0]=1;
		for(int t=1;t<=n;t++){
			for(int u=0;u<n;u++){
				for(int s=0;s<(1<<n);s++){
					if(s&(1<<u)) continue;
					if(st[t]=='0'){
						for(int k=0;k<=t;k++){
							dp[t][s|(1<<u)][k+1]+=dp[t-1][s][k];
							dp[t][s|(1<<u)][k+1]%=mod;
						}
					}
					else{
						for(int k=0;k<c[u];k++){
							dp[t][s|(1<<u)][k]+=dp[t-1][s][k];
							dp[t][s|(1<<u)][k]%=mod;
						}
						for(int k=c[u];k<=t;k++){
							dp[t][s|(1<<u)][k+1]+=dp[t-1][s][k];
							dp[t][s|(1<<u)][k+1]%=mod;
						}
					}
					
				}
			}
		}
		int ful=(1u<<n)-1;
		long long ans=0;
		for(int k=0;k<=n-m;k++){
			ans+=dp[n][ful][k];
			ans%=mod;
		}
		printf("%lld\n",ans);
	}
	else if(m==n){//sub 15
		bool fail=0;
		for(int i=0;i<n;i++){
			if(st[i+1]=='0') fail=1;
			if(c[i]==0) fail=1;
		}
		if(fail) printf("0\n");
		else{
			long long ans=1;
			for(int i=1;i<=n;i++){
				ans=ans*i%mod;
			}
			printf("%lld\n",ans);
		}
	}
	else{
		printf("0\n");
	}
	return 0;
}
//100+100(80?)+25(?)+24
//that's all...
