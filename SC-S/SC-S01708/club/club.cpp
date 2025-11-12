#include<bits/stdc++.h>
using namespace std;
long long t,n;
struct o{
	long long x;
	long long y;
	long long z;
}a[100000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		long long sum=0,dp[4][205][205];
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i].x==0){
					dp[1][i][j]=max(dp[1][i-1][j-1]+dp[1][i][j-1],dp[1][i-1][j]);
				}else dp[1][i][j]=max(dp[1][i-1][j],dp[1][i][j-1]+a[i].x);
				if(dp[1][i-1][j]<dp[1][i][j-1]+a[i].x)a[i].x=0;
			}			
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cout<<dp[1][i][j]<<' ';
//			}
//			cout<<endl;				
//		}cout<<endl;	
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i].y==0){
					dp[2][i][j]=max(dp[2][i-1][j-1]+dp[2][i][j-1],dp[2][i-1][j]);
				}else dp[2][i][j]=max(dp[2][i-1][j],dp[2][i][j-1]+a[i].y);
				if(dp[2][i-1][j]<dp[2][i][j-1]+a[i].y)a[i].y=0;
			}			
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cout<<dp[2][i][j]<<' ';
//			}
//			cout<<endl;				
//		}cout<<endl;	
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i].z==0){
					dp[3][i][j]=max(dp[3][i-1][j-1]+dp[3][i][j-1],dp[3][i-1][j]);
				}else dp[3][i][j]=max(dp[3][i-1][j],dp[3][i][j-1]+a[i].z);
				if(dp[3][i-1][j]<dp[3][i][j-1]+a[i].z)a[i].z=0;
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cout<<dp[3][i][j]<<' ';
//			}
//			cout<<endl;			
//		}cout<<endl;	
			long long maxx=0,f=0;
			for(int i=1;i<=3;i++){
				if(maxx<dp[i][n][n/2]){
					maxx=dp[i][n][n/2];
					f=i;
				}
			}
			sum+=maxx;
			for(int i=1;i<=3;i++){
				if(i!=f){
					sum+=dp[i][n][n/2/2];
				}
			}
				
		cout<<sum<<endl;
	}	
	return 0;
} 
