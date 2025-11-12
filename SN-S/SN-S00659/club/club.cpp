#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=1e5+5;
int T,ans;
int n,a[N][4];
int dp[N][4];
struct node{
	int p[4];
}s[N][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=0;
		memset(dp,0,sizeof(dp));
		memset(s,0,sizeof(s));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
		}
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				for(int k=1;k<=3;k++){
					if(dp[i-1][j]+a[i][k]>=dp[i][k]&&s[i-1][j].p[k]<n/2){
						dp[i][k]=dp[i-1][j]+a[i][k];
						s[i][k]=s[i-1][j];
						s[i][k].p[k]++;
//						for(int z=1;z<=3;z++){
//							printf("%d+%d \n",dp[i-1][j],a[i][k]);
//							printf("%d %d %d=%d",s[i][k].p[1],s[i][k].p[2],s[i][k].p[3],dp[i][k]);
//							cout<<endl;
//						}
					}
//					dp[i][k]=max(dp[i-1][j]+a[i][k],dp[i][k]);
					
					
				}
			}	
		}
		ans=max(dp[n][1],max(dp[n][2],dp[n][3]));
		printf("%d\n",ans);
		
	}
	return 0;
}
