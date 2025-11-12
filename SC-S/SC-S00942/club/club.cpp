#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[210];
int b[210];
int c[210];
int dp[110][110][110];
int ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int i=1;i<=n;i++){
			for(int x=0;x<=min(n/2,i);x++){
				for(int y=0;y<=min(n/2,i);y++){
					for(int z=0;z<=min(n/2,i);z++){
						if(x+y+z==i){
							if(x==0){
								if(y==0){
									dp[x][y][z]=dp[x][y][z-1]+c[i];
								}else if(z==0){
									dp[x][y][z]=dp[x][y-1][z]+b[i];
								}else{
									dp[x][y][z]=max(dp[x][y-1][z]+b[i],dp[x][y][z-1]+c[i]);
								}
							}else if(y==0){
								if(z==0){
									dp[x][y][z]=dp[x-1][y][z]+a[i];
								}else{
									dp[x][y][z]=max(dp[x-1][y][z]+a[i],dp[x][y][z-1]+c[i]);
								}
							}else if(z==0){
								dp[x][y][z]=max(dp[x-1][y][z]+a[i],dp[x][y-1][z]+b[i]);
							}else{
								dp[x][y][z]=max(max(dp[max(0,x-1)][y][z]+a[i],dp[x][max(0,y-1)][z]+b[i]),dp[x][y][max(0,z-1)]+c[i]);
							}
							ans=max(ans,dp[x][y][z]);
						}
					}
				}
			} 
		}
		cout<<ans<<endl;
		ans=0; 
	}
	return 0;
}