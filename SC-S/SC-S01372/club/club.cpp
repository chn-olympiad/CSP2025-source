#include<bits/stdc++.h>
using namespace std;
const int N=2e2+10;

int T;
int n;
long long a[N][3];
long long dp[N][N][N],ans;

long long maxx(long long x,long long y,long long z,long long k){
	return max(max(x,y),max(z,k));
}

int main(){
	freopen("club.in","r",stdin);
//	freopen("club2.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		ans=0;
		cin>>n;
		int n2=n/2;
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
		}
		dp[1][1][0]=a[1][0];
		dp[1][0][0]=a[1][1];
		dp[1][0][1]=a[1][2];
		
		for(int i=2;i<=n;i++){
			for(int j=0;j<=i;j++){
				for(int k=0;k<=i;k++){
					if(k+j<=i&&j<=n2&&k<=n2&&i-j-k<=n2){
						dp[i][j][k]=maxx(dp[i][j][k],
									(j-1>=0 ? dp[i-1][j-1][k]+a[i][0] : 0),
									j+k<=i-1 ? dp[i-1][j][k]+a[i][1] : 0,
									(k-1>=0 ? dp[i-1][j][k-1]+a[i][2] : 0));
					}

				}
			}
		}

		for(int j=0;j<=n/2;j++){
			for(int k=0;k+j<=n;k++){
				if(j<=n2&&k<=n2&&n-j-k<=n2)ans=max(ans,dp[n][j][k]);
			}
		}
		cout<<ans<<"\n";
		
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



1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/