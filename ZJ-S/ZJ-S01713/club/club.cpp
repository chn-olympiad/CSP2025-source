#include<bits/stdc++.h>
using namespace std;
int T;
int arr[100010][5];
int judge[100010][5];
int dp[100010][5];
void over(){
	for(int i=1;i<=100010;i++){
		for(int j=1;j<=5;j++){
			arr[i][j]=0;
			judge[i][j]=0;
		}
	}
}
void solve(){
	int n;
	over();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i][1]>>arr[i][2]>>arr[i][3];
	}
	int limit=n/2;
	int idx_last=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			if(judge[i-1][j]<limit){
				dp[i][j]=max(dp[i-1][1]+arr[i][j],max(dp[i-1][2]+arr[i][j],dp[i-1][3]+arr[i][j]));
			}
			else{
				if(j==1){
					dp[i][j]=max(dp[i-1][2]+arr[i][j],dp[i-1][3]+arr[i][j]);
				}
				else if(j==2){
					dp[i][j]=max(dp[i-1][1]+arr[i][j],dp[i-1][3]+arr[i][j]);
				}
				else if(j==3){
					dp[i][j]=max(dp[i-1][2]+arr[i][j],dp[i-1][1]+arr[i][j]);
				}
			}
		}
		int idx=0;
		for(int j=1;j<=3;j++){
			if(dp[i][idx]<dp[i][j]){
				idx=j;
			}
		}
		judge[i][idx]=judge[i-1][idx]+1;
		for(int j=1;j<=3;j++){
			if(j!=idx){
				judge[i][j]=judge[i-1][j];
			}
		}
	}
	int ans=0;
	for(int i=1;i<=3;i++){
		ans=max(ans,dp[n][i]);
	}
	cout<<ans<<endl;
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

