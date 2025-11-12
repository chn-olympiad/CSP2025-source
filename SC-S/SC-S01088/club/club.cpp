#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int t,n,a[100010][4],dp[100010][4],cnt[100010][4][4];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i][1]>>a[i][2]>>a[i][3];
//			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
//		cout<<"-----------------------------"<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				int mxv=0,mxi=0;
				for(int k=1;k<=3;k++)
					if(dp[i-1][k]>mxv&&cnt[i-1][k][j]+1<=n/2){
						mxv=dp[i-1][k];
						mxi=k;
					}
				dp[i][j]=mxv+a[i][j];
				cnt[i][j][1]=cnt[i-1][mxi][1];
				cnt[i][j][2]=cnt[i-1][mxi][2];
				cnt[i][j][3]=cnt[i-1][mxi][3];
				cnt[i][j][j]++;
//				cout<<dp[i][j]<<" ";
			}
//			cout<<endl;
		}
		ans=max(dp[n][1],max(dp[n][2],dp[n][3]));
		for(int i=n;i>=1;i--){
			for(int j=1;j<=3;j++){
				int mxv=0,mxi=0;
				for(int k=1;k<=3;k++)
					if(dp[i+1][k]>mxv&&cnt[i+1][k][j]+1<=n/2){
						mxv=dp[i+1][k];
						mxi=k;
					}
				dp[i][j]=mxv+a[i][j];
				cnt[i][j][1]=cnt[i+1][mxi][1];
				cnt[i][j][2]=cnt[i+1][mxi][2];
				cnt[i][j][3]=cnt[i+1][mxi][3];
				cnt[i][j][j]++;
			}
		}
		ans=max(max(ans,dp[1][1]),max(dp[1][2],dp[1][3]));
		cout<<ans<<endl;
	}
	return 0;
}
