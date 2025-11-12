#include<bits/stdc++.h>
using namespace std;
long long t,n,m;
struct k{
	long long m,x,y,z;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		m=n/2;
		k dp[3][n];
		for(long long i=1;i<=n;i++)cin>>dp[0][i].m>>dp[1][i].m>>dp[2][i].m;
		for(long long i=2;i<=n;i++){
			k ma,th;
			if(dp[0][i-1].m>=dp[1][i-1].m&&dp[1][i-1].m>=dp[2][i-1].m){
				ma=dp[0][i-1];
				th=dp[1][i-1];
			}
			if(dp[0][i-1].m>=dp[2][i-1].m&&dp[2][i-1].m>=dp[1][i-1].m){
				ma=dp[0][i-1];
				th=dp[2][i-1];
			}
			if(dp[1][i-1].m>=dp[0][i-1].m&&dp[0][i-1].m>=dp[2][i-1].m){
				ma=dp[1][i-1];
				th=dp[0][i-1];
			}
			if(dp[1][i-1].m>=dp[2][i-1].m&&dp[2][i-1].m>=dp[0][i-1].m){
				ma=dp[1][i-1];
				th=dp[2][i-1];
			}
			if(dp[2][i-1].m>=dp[0][i-1].m&&dp[0][i-1].m>=dp[1][i-1].m){
				ma=dp[2][i-1];
				th=dp[0][i-1];
			}
			if(dp[2][i-1].m>=dp[1][i-1].m&&dp[1][i-1].m>=dp[0][i-1].m){
				ma=dp[2][i-1];
				th=dp[1][i-1];
			}
			if(ma.x>=m){
				dp[0][i].m+=th.m;
				dp[0][i].x=th.x+1;
				dp[0][i].y=th.y;
				dp[0][i].z=th.z;
			}else{
				dp[0][i].m+=ma.m;
				dp[0][i].x=ma.x+1;
				dp[0][i].y=ma.y;
				dp[0][i].z=ma.z;
			}
			if(ma.y>=m){
				dp[1][i].m+=th.m;
				dp[1][i].x=th.x;
				dp[1][i].y=th.y+1;
				dp[1][i].z=th.z;
			}else{
				dp[1][i].m+=ma.m;
				dp[1][i].x=ma.x;
				dp[1][i].y=ma.y+1;
				dp[1][i].z=ma.z;
			}
			if(ma.z>=m){
				dp[2][i].m+=th.m;
				dp[2][i].x=th.x;
				dp[2][i].y=th.y;
				dp[2][i].z=th.z+1;
			}else{
				dp[2][i].m+=ma.m;
				dp[2][i].x=ma.x;
				dp[2][i].y=ma.y;
				dp[2][i].z=ma.z+1;
			}
		}
		cout<<max(dp[0][n].m,max(dp[1][n].m,dp[2][n].m))<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}  
