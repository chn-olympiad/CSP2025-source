#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int dp[150][150][150],mx;
int d[100010][5],a[100010],n,t;
signed main(){
	ios
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>d[i][1]>>d[i][2]>>d[i][3];
		}
		mx=0;
		if(n<=2){
			memset(dp,0,sizeof dp);
			for(int i=0;i<=n/2;i++){
				for(int j=0;j<=n/2;j++){
					for(int k=0;k<=n/2;k++){
						if(i+j+k>n)break;
						dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]+d[i+j+k][1]);
						dp[i][j+1][k]=max(dp[i][j+1][k],dp[i][j][k]+d[i+j+k][2]);
						dp[i][j][k+1]=max(dp[i][j][k+1],dp[i][j][k]+d[i+j+k][3]);
						if(i+1<=n/2)mx=max(mx,dp[i+1][j][k]);
						if(j+1<=n/2)mx=max(mx,dp[i][j+1][k]);
						if(k+1<=n/2)mx=max(mx,dp[i][j][k+1]);
					}
				}
			}
			cout<<mx<<"\n";
		}else{
			for(int i=1;i<=n;i++){
				a[i]=d[i][1];
			}
			sort(a+1,a+n+1,greater<int>());
			for(int i=1;i<=n/2;i++)mx+=a[i];
			cout<<mx<<"\n";
		}
	}
	return 0;
}