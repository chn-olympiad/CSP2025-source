#include<bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 100005
int t,n,ans;
int a[maxn][5];
int dp[205][105][105];
int s[maxn];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		ans=0;
		scanf("%lld",&n);
		int m=n/2;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		}
		if(n<=200){
			dp[1][1][0]=a[1][1];
			dp[1][0][1]=a[1][2];
			dp[1][0][0]=a[1][3];
			for(int i=2;i<=n;i++){
				for(int A=0;A<=min(m,i);A++){
					for(int B=0;B<=min(m,i);B++){
						dp[i][A][B]=0;
						int C=i-A-B;
						if(C<0||C>m){
							continue;
						}
						if(A>0){
							dp[i][A][B]=max(dp[i-1][A-1][B]+a[i][1],dp[i][A][B]);
						}
						if(B>0){
							dp[i][A][B]=max(dp[i-1][A][B-1]+a[i][2],dp[i][A][B]);
						}
						if(C>0){
							dp[i][A][B]=max(dp[i-1][A][B]+a[i][3],dp[i][A][B]);
						}
//						cout<<i<<" "<<A<<" "<<B<<":"<<dp[i][A][B]<<endl;
					}
				}
			}
			for(int A=0;A<=m;A++){
				for(int B=max((long long)0,m-A);B<=m;B++){
					ans=max(ans,dp[n][A][B]);
				}
			}
			printf("%lld\n",ans);
		}
		else{
			for(int i=1;i<=n;i++){
				s[i]=a[i][1];
			}
			sort(s+1,s+n+1);
			for(int i=n;i>=m+1;i--){
				ans+=s[i];
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
