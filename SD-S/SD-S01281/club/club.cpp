#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int> 
using namespace std;
const int inf=0x3f3f3f3f;
int t,n,a[10005][5],dp[202][102][102][5],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		}memset(dp,-0x3f3f3f3f,sizeof(dp));
		dp[1][1][0][1]=a[1][1];
		dp[1][0][1][2]=a[1][2];
		dp[1][0][0][3]=a[1][3];
		ans=max(ans,max(a[1][1],max(a[1][2],a[1][3])));
		for(int i=2;i<=n;i++){
			for(int a1=0;a1<=min(i,n>>1);a1++){
				for(int a2=0;a2<=min(i,n>>1);a2++){
					int a3=i-a1-a2;
					if(a3>(n<<1)) continue;
					dp[i][a1][a2][1]=max(dp[i-1][a1-1][a2][1],max(dp[i-1][a1-1][a2][2],dp[i-1][a1-1][a2][3]))+a[i][1];
					dp[i][a1][a2][2]=max(dp[i-1][a1][a2-1][1],max(dp[i-1][a1][a2-1][2],dp[i-1][a1][a2-1][3]))+a[i][2];
					dp[i][a1][a2][3]=max(dp[i-1][a1][a2][1],max(dp[i-1][a1][a2][2],dp[i-1][a1][a2][3]))+a[i][3];
					ans=max(ans,max(dp[i][a1][a2][1],max(dp[i][a1][a2][2],dp[i][a1][a2][3])));
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
