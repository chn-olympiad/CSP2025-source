#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.txt","r",stdin);
	freopen("club.txt","w",stdout);
	int t,n,k;cin>>t;
	while(t--){
		cin>>n;k=n/2;
		vector<vector<int> > a(n,vector<int>(3));
		for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
		vector<vector<int> > dp(k+1,vector<int>(k+1,-1));
		dp[0][0]=0;
		for(int i=0;i<n;i++){
			vector<int>p=a[i];
			for(int x=k;x>=0;x--){
		    	
		    	 for(int y=k;y>=0;y--){
		        	if(dp[x][y]!=-1) continue;{
		            	x+1<=k&&(dp[x+1][y]=max(dp[x+1][y],dp[x][y]+p[0]));
		            	y+1<=k&&(dp[x][y+1]=max(dp[x][y+1],dp[x][y]+p[1]));
		            	dp[x][y]=max(dp[x][y],dp[x][y]+p[2]);
					}
					
			}  
				}
		}	   
		int ans=0;
		for(int x=0;x<=k;x++)
		    for(int y=0;y<=k;y++)
		         if(n-x-y<=k) ans=max(ans,dp[x][y]);
		cout<<ans<<endl;
	}
	return 0;
}
