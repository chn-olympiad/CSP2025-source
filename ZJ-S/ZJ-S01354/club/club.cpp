#include<bits/stdc++.h>
using namespace std;
int T,n,k;
int dp[205][105][105][105];
int a[100005][4],flag=1;
int x[100005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
				if(a[i][3]!=0||a[i][2]!=0)flag=0;
			}
		}
		if(flag==1){
			for(int i=1;i<=n;i++)x[i]=a[i][1];
			sort(x+1,x+n+1,cmp);
			long long ans=0;
			for(int i=1;i<=n/2;i++)ans+=x[i];
			printf("%lld\n",ans);
		}
		else{
			for(int i=1;i<=n;i++){
				for(int j=0;j<=min(i,n/2);j++){
					for(int k=0;k<=min(i-j,n/2);k++)
						if((i-j-k)<=n/2){
//							printf("%d %d %d\n",j,k,i-k)
							if(j>0)dp[i][j][k][i-j-k]=max(dp[i][j][k][i-j-k],dp[i-1][j-1][k][i-j-k]+a[i][1]);
							if(k>0)dp[i][j][k][i-j-k]=max(dp[i][j][k][i-j-k],dp[i-1][j][k-1][i-j-k]+a[i][2]);
							if(i-j-k>0)dp[i][j][k][i-j-k]=max(dp[i][j][k][i-j-k],dp[i-1][j][k][i-j-k-1]+a[i][3]);
						}
				}
			}
//			for(int i=1;i<=n;i++){
//				printf("\n");
//				for(int j=0;j<=min(i,n/2);j++)
//					for(int k=0;k<=min(i-j,n/2);k++)printf("dp[%d][%d][%d]:%d ",j,k,i-j-k,dp[i][j][k][i-j-k]);
//			}
				
			long long ans=0;
			for(int i=1;i<=n/2;i++)
				for(int j=1;j<=n/2;j++)
					if(n-i-j<=n/2&&ans<dp[n][i][j][n-i-j])ans=dp[n][i][j][n-i-j];
			printf("%lld\n",ans);
		}
		memset(dp,0,sizeof(dp));
	}
}
