/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2025-11-01 14:10
    说明:
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;
int T,n,a[210][4],dp[2][210][210][210];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
		memset(dp,0,sizeof dp);
		dp[1][0][0][0]=0;
		dp[1][1][0][0]=a[1][1];
		dp[1][0][1][0]=a[1][2];
		dp[1][0][0][1]=a[1][3];
		for(int i=2;i<=n;i++){
			for(int x=0;x<=n/2;x++){
				for(int y=0;y<=n/2;y++){
					for(int z=0;z<=n/2;z++){
						if(x+y+z>i)break;
						if(x>=1)dp[i%2][x][y][z]=max(dp[i%2][x][y][z],dp[(i+1)%2][x-1][y][z]+a[i][1]);
						if(y>=1)dp[i%2][x][y][z]=max(dp[i%2][x][y][z],dp[(i+1)%2][x][y-1][z]+a[i][2]);
						if(z>=1)dp[i%2][x][y][z]=max(dp[i%2][x][y][z],dp[(i+1)%2][x][y][z-1]+a[i][3]);
					}
				}
			}
		}
		int ans=0;
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				for(int l=0;l<=n/2;l++){
					ans=max(ans,dp[n%2][i][j][l]);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0


*/