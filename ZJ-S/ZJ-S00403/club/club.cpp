#include <bits/stdc++.h>
using namespace std;
long long t,n,ans;
int a[114514][4];
int dp[114514][4][4];
void dfs(int x,int y,int z,int s,long long sum){
	if(s==n+1){
		ans=max(ans,sum);
		return;
	}
	if(x*2<n)dfs(x+1,y,z,s+1,sum+a[s][1]);
	if(y*2<n)dfs(x,y+1,z,s+1,sum+a[s][2]);
	if(z*2<n)dfs(x,y,z+1,s+1,sum+a[s][3]);
}
int v[114514];
long long f(){
	for(int i=1;i<=n;i++)v[i]=a[i][1];
	sort(v+1,v+1+n);
	long long sum=0;
	for(int i=n/2+1;i<=n;i++)sum+=v[i];
	return sum;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		ans=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
			scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
		if(n<=10){
			dfs(0,0,0,1,0);
			printf("%lld\n",ans);
			continue;
		}
		for(int i=1;i<=3;i++)
			dp[0][i][0]=0,dp[0][i][1]=0,dp[0][i][2]=0,dp[0][i][3]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
//				printf("(%d,%d):",i,j);
				for(int k=1;k<=3;k++){
//					printf("check %d:",k);
					if(dp[i-1][k][j]*2<n&&dp[i-1][k][0]>=dp[i][j][0]){//less than n/2 & more
						dp[i][j][0]=dp[i-1][k][0];//data
						dp[i][j][1]=dp[i-1][k][1];//x
						dp[i][j][2]=dp[i-1][k][2];//y
						dp[i][j][3]=dp[i-1][k][3];//z
						dp[i][j][j]++;//add
					}
				}
				dp[i][j][0]+=a[i][j];
//				printf("%d,%d,%d,%d.  ",dp[i][j][0],dp[i][j][1],dp[i][j][2],dp[i][j][3]);
			}
//			printf("\n");
		}
		long long ans=0;
		for(int i=1;i<=3;i++){
			ans=max(ans,(long long)dp[n][i][0]);
		}
		ans=max(f(),ans);
		printf("%lld\n",ans);
	}
	return 0;
}
