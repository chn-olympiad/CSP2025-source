#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,a[100005][3],ans,dp[100005][3][3][4];
void dfs(int i,int x,int y,int z,ll sum){
	if(x>n/2||y>n/2||z>n/2)return;
	if(i==n+1){
		ans=max(ans,sum);
		return;
	}
	dfs(i+1,x+1,y,z,sum+a[i][0]);
	dfs(i+1,x,y+1,z,sum+a[i][1]);
	dfs(i+1,x,y,z+1,sum+a[i][2]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%lld",&n);
		if(n>10){
			for(int i=1;i<=n;i++){
				for(int j=0;j<=2;j++){
					scanf("%lld",&a[i][j]);
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=0;j<=2;j++){
					for(int k=0;k<=2;k++){
						for(int l=0;l<=3;l++){
							dp[i][j][k][l]=0;
						}
					}
				}
			}
			for(int j=0;j<=2;j++){
				for(int k=0;k<=2;k++){
					dp[1][j][k][0]=a[1][j];
					dp[1][j][k][j+1]=1;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=0;j<=2;j++){
					for(int k=0;k<=2;k++){
						ll ma=dp[i-1][k][0][0],c[4]{0},id=0;
						for(int l=0;l<=2;l++){
							if(dp[i-1][k][l][j+1]+1<=n/2){
								if(ma<dp[i-1][k][l][0]){
									ma=dp[i-1][k][l][0];
									c[1]=dp[i-1][k][l][1];
									c[2]=dp[i-1][k][l][2];
									c[3]=dp[i-1][k][l][3];
									id=l;
								}
							}
							if(ma==dp[i-1][k][l][0]){
								if(dp[i-1][k][l][j+1]<dp[i-1][k][id][j+1]){
									ma=dp[i-1][k][l][0];
									c[1]=dp[i-1][k][l][1];
									c[2]=dp[i-1][k][l][2];
									c[3]=dp[i-1][k][l][3];
									id=l;
								}
							}
						}
						dp[i][j][k][0]=ma+a[i][j];
						for(int l=1;l<=3;l++){
							dp[i][j][k][l]=c[l];
						}
						dp[i][j][k][j+1]++;
					}
				}
			}
			ll ma=0;
			for(int j=0;j<=2;j++){
				for(int k=0;k<=2;k++){
					ma=max(dp[n][j][k][0],ma);
				}
			}
			printf("%lld\n",ma);
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=2;j++){
				scanf("%lld",&a[i][j]);
			}
		}
		dfs(1,0,0,0,0);
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
