#include<bits/stdc++.h>
#define int long long int
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
int t,n,a[100005][5],dp[205][205][205],maxn,ans,k,b[100005];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	IOS
	cin>>t;
	while(t--){
		ans=0;
		k=1;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n;j++){
				for(int k=0;k<=n;k++){
					dp[i][j][k]=0;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			b[i]=a[i][1];
			if(a[i][2]!=0||a[i][3]!=0){
				k=0;
			}
		}
		if(k){
			sort(b+1,b+1+n);
			for(int i=n;i>n/2;i--){
				ans+=b[i];
			}
			cout<<ans<<"\n";
			continue;
		}
		dp[1][1][0]=a[1][1],dp[1][0][1]=a[1][2],dp[1][0][0]=a[1][3];
		for(int i=2;i<=n;i++){
			for(int j=0;j<=i;j++){
				for(int k=0;k<=i-j;k++){
					if(j==0){
						if(k==0){
							dp[i][j][k]=dp[i-1][j][k]+a[i][3];
						}
						else{
							dp[i][j][k]=max(dp[i-1][j][k-1]+a[i][2],dp[i-1][j][k]+a[i][3]);
						}
					}
					else if(k==0){
						if(j==0){
							dp[i][j][k]=dp[i-1][j][k]+a[i][3];
						}
						else{
							dp[i][j][k]=max(dp[i-1][j-1][k]+a[i][1],dp[i-1][j][k]+a[i][3]);
						}
					}
					else{
						dp[i][j][k]=max(dp[i-1][j-1][k]+a[i][1],max(dp[i-1][j][k-1]+a[i][2],dp[i-1][j][k]+a[i][3]));
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n;j++){
				for(int k=0;k<=n;k++){
					if(k<=n/2&&j<=n/2&&(n-k-j)<=n/2){
						ans=max(ans,dp[i][j][k]);
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
