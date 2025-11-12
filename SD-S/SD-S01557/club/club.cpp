#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const long long N=35;
long long s,n,a[N][6],ans=0,dp[N][N][N][N],FLAG,sum=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&s);
	while(s--){
		scanf("%lld",&n);
		memset(a,0,sizeof a);
		memset(dp,0,sizeof dp);
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%lld",&a[i][j]);
				if(j==2||j==3){
					if(a[i][j]!=0){
						FLAG=1;
					}
				}
				if(j==1){
					sum+=a[i][j];
				}
			}
		}
		if(FLAG==0){
			printf("%lld\n",sum);
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					for(int u=0;u<=n/2;u++){
					long long maxn=0;
					if(j!=0){
						maxn=max(maxn,dp[i-1][j-1][k][u]+a[i][1]);
					}
					if(k!=0){
						maxn=max(maxn,dp[i-1][j][k-1][u]+a[i][2]);
					}
					if(u!=0){
						maxn=max(maxn,dp[i-1][j][k][u-1]+a[i][3]);
					}
					dp[i][j][k][u]=maxn;
					if((i==n)){
						ans=max(ans,dp[i][j][k][u]);
					}
					}
				} 
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

