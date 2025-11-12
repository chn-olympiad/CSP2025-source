//SN-S00649 袁浩文 西安辅轮中学
#include <bits/stdc++.h> 
#define int long long
using namespace std;
int t,n,a[200005][4],a1,a2,a3;
int solve(int x,int y,int z,int p){
	if(p==n){
		if(x+1>n/2){
			return max(a[n][2],a[n][3]); 
		}
		if(y+1>n/2){
			return max(a[n][1],a[n][3]);			
		}
		if(z+1>n/2){
			return max(a[n][1],a[n][2]);
		}
		return max(a[n][1],max(a[n][2],a[n][3]));
	}
	if(x+1<=n/2){
		//1
		a1+=solve(x+1,y,z,p+1);
		
	}
	if(y+1<=n/2){
		//2
		a2+=solve(x,y+1,z,p+1);
		
	}
	if(z+1<=n/2){
		//3
		a3+=solve(x,y,z+1,p+1);
		
	}
//	cout<<"debug"<<x<<" "<<y<<" "<<z<<" "<<p<<":"<<max(a1,max(a2,a3))<<"\n";
	return max(a1,max(a2,a3));
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
//		int dp[n/2+1][n/2+1][n/2+1][n+1];
		for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
//		//上一轮选到p，现在有i,j,k个人
//		for(int i=1;i<=n/2;i++){
//			for(int j=1;j<=n/2;j++){
//				for(int k=1;k<=n/2;k++){
//					for(int p=1;p<=n;p++){
//						dp[i][j][k][p]+=max(dp[i-1][j][k][p-1]+a[p][1],max(dp[i][j-1][k][p-1]+a[p][2],dp[i][j][k-1][p-1]+a[p][3]));
//					}
//				}
//			}
//		}
//		cout<<dp[n/2][n/2][n/2][n]<<"\n";
		cout<<solve(0,0,0,0)<<"\n";
	}
}
