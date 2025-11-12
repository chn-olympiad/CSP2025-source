#include<bits/stdc++.h>
using namespace std;
int a[1001][4];
int dp[1001][4];
int now[4];
int np[1001];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n=0;
		cin>>n;
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		memset(now,0,sizeof(now));
		memset(np,0,sizeof(np));
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(np[i]==0){
					if(a[i][j]+dp[i-1][j]>dp[i][j]&&now[j]+1<=n/2){
						now[j]++;
						dp[i][j]=a[i][j]+dp[i-1][j];
						np[i]=j;
					}else{
						dp[i][j]=dp[i][j-1];
					}
				}else{
					int nowm=-a[i][np[i]];
					int nown;
					for(int k=1;k<=3;k++){
						if(k==j){
							nowm+=a[i][j]+dp[i][j-1],nown+=dp[i][j-1];
						}else if(k>j){
							nowm+=dp[i][j-1],nown+=dp[i][j-1];
						}else{
							nowm+=dp[i][j],nown+=dp[i][j];
						}
					}
					if(nowm>nown&&now[j]+1<=now[i]/2){
						now[j]++;
						dp[i][j]=a[i][j]+dp[i][j-1];
						dp[i][np[i]]-=a[i][np[i]];
						np[i]=j;
					}else{
						dp[i][j]=dp[i][j-1];
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			cout<<np[i]<<" ";
		}
		
	}
	return 0;
}