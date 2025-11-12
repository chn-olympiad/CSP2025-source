#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
const int maxn = 56;
int a[101][4] = {};
int dp[maxn][maxn][maxn];
int t;
int max_cnt;

cin>>t;
while(t--)
{
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	memset(dp,-0x3f,sizeof(dp));
	//dp[0][0][0] = 0;
	for(int i = 0;i<=n+1;i++){
	    for(int j = 0;j<=n+1;j++){
			for(int k = 0;k<=n-j+1;k++){
				if(dp[i-1][j][k]==0x3f3f3f3f)	continue;
				if(j+1<=(n+1)/2){
					dp[i][j+1][k] = max(dp[i][j+1][k],dp[i-1][j][k]+a[i][1]);
					
				}
				if(k+1<=(n+1)/2){
					dp[i][j][k+1] = max(dp[i][j][k+1],dp[i-1][j][k]+a[i][2]);
					
				}
				int cnt= i-1-j-k;
				if(cnt+1<=(n+2)/3){
					dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
				}
				
			}
		}
	}
	int max_satisfaction = 0;
	


	int max_cnt = (n+2)/2;
	for(int j = 2;j<max_cnt;j++){
		for(int k = 2;k<max_cnt;k++){
			for(int i = 2;i<max_cnt;i++){
					int cnt  = n-j-k;
					if(cnt<=max_cnt){
						max_satisfaction = max(max_satisfaction,dp[n][j][k]);
						cout<<max_satisfaction<<endl;
						

			    }
			}
		
			
			
		}
		
	}
	
}

fclose(stdin);
fclose(stdout);
return 0;
}
