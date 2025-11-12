//背包,
#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define i128 __int128
using namespace std;
const int N=1e5+5,inf=1e18,mod=1e9+6;

int dp[N],w[N][10],cnt[10];

signed main(){
    freopen("club.in","r",stdin);
   freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		memset(dp,0,sizeof(dp));
		memset(cnt,0,sizeof(cnt));
		int n;
		//cout<<"cnt:"<<cnt[1]<<endl;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				scanf("%d",&w[i][j]);
		int b;
		for(int i=1;i<=n;i++)
			dp[i]=min(w[i][1],w[i][2]);
			/*for(int j=1;j<=2;j++){

				if(cnt[j]>=n/2){
					if(w[i][j]>w[i-1][j])
						cnt[j]--;//同一组里怎么去比呢？
				}
				if(dp[i]<dp[i-1]+w[i][j]){
					dp[i]=dp[i-1]+w[i][j];
					cnt[b]--;
					cnt[j]++;
					b=j;
				}
			}*/
		sort(dp+1,dp+1+n);
		int ans=0;
		for(int i=1;i<=(n/2);i++) ans+=dp[i];
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);

    return 0;
}

