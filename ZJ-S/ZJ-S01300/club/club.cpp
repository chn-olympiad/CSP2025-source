#include<bits/stdc++.h>
using namespace std;
const int MAXN=210;
int n,dp[MAXN][MAXN][MAXN];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int a1,a2,a3;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a1,&a2,&a3);
			for(int cnt1=0;cnt1<=i-1;cnt1++){
				for(int cnt2=0;cnt1+cnt2<=i-1;cnt2++){
					int cnt3=i-1-cnt1-cnt2;
					if(cnt1<=n/2-1)	dp[cnt1+1][cnt2][cnt3]=max(dp[cnt1+1][cnt2][cnt3],dp[cnt1][cnt2][cnt3]+a1);
					if(cnt2<=n/2-1)	dp[cnt1][cnt2+1][cnt3]=max(dp[cnt1][cnt2+1][cnt3],dp[cnt1][cnt2][cnt3]+a2);
					if(cnt3<=n/2-1)	dp[cnt1][cnt2][cnt3+1]=max(dp[cnt1][cnt2][cnt3+1],dp[cnt1][cnt2][cnt3]+a3);
				}
			}
		}
		int ans=INT_MIN;
		for(int cnt1=0;cnt1<=n;cnt1++){
			for(int cnt2=0;cnt1+cnt2<=n;cnt2++){
				int cnt3=n-cnt1-cnt2;
				ans=max(ans,dp[cnt1][cnt2][cnt3]);
			}
		}
		cout<<ans<<'\n';
		memset(dp,0,sizeof(dp));
	}
	return 0;
}
