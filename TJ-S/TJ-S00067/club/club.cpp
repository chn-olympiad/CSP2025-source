#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,a[100002][3],p[3],ans,cnt[100002][3][3];
inline void dfs(int x,int an){
	if(x==n+1){
		ans=max(ans,an);
		return;
	}
	if(p[0]<n/2){
		++p[0];
		dfs(x+1,an+a[x][0]);
		--p[0];
	}
	if(p[1]<n/2){
		++p[1];
		dfs(x+1,an+a[x][1]);
		--p[1];
	}
	if(p[2]<n/2){
		++p[2];
		dfs(x+1,an+a[x][2]);
		--p[2];
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		int dp[100002][3]={0},p[3];
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		}
		ans=0;
		
		dp[1][0]=a[1][0];
		dp[1][1]=a[1][1];
		dp[1][2]=a[1][2];
		cnt[1][0][0]=1;
		cnt[1][1][1]=1;
		cnt[1][2][2]=1;
		for(int j=1;j<=n;j++){

			for(int k=0;k<3;k++){
				for(int l=0;l<3;l++){
					
					if(cnt[j][k][l]<n/2){
						//printf("%d %d %d\n",j,k,l);
						dp[j+1][l]=max(dp[j+1][l],dp[j][k]+a[j+1][l]);
						
						
						cnt[j+1][l][l]=max(cnt[j+1][l][l],cnt[j][k][l]+1);
						for(int u=0;u<3;u++){
							if(u!=l){
								cnt[j+1][l][u]=max(cnt[j][k][l],cnt[j+1][l][u]);
							}
						}
					}		
					/*if(cnt[j][1][l]<n/2){
						if(cnt[j][1][k]<n/2){
							dp[j+1][l]=max(dp[j+1][l],dp[j][k]+a[j+1][l]);
						}
						
						cnt[j+1][l][l]=cnt[j][1][l]+1;
						for(int u=0;u<3;u++){
							if(u!=l){
								cnt[j+1][l][u]=min(cnt[j][0][l],cnt[j+1][l][u]);
							}
						}
					}						
					if(cnt[j][2][l]<n/2){
						if(cnt[j][2][k]<n/2){
							dp[j+1][l]=max(dp[j+1][l],dp[j][k]+a[j+1][l]);
						}
						
						cnt[j+1][l][l]=cnt[j][2][l]+1;
						for(int u=0;u<3;u++){
							if(u!=l){
								cnt[j+1][l][u]=min(cnt[j][0][l],cnt[j+1][l][u]);
							}
						}
					}*/						

						
				}

			}
			
		}
		/*for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				printf("%d ",dp[i][j]);
			}
			printf("\n");
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				for(int k=0;k<3;k++){
					printf("%d",cnt[i][j][k]);
				}
				printf("\n");
			}
			puts("\n");
		}
		*/
		printf("%d\n",max(dp[n][0],max(dp[n][1],dp[n][2])));

	}
	return 0;
}

