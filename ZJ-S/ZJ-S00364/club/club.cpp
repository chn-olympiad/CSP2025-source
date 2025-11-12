#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=50;
int t;
int n;
int a[100005][5];

int ans=-1;
void scan(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	return ;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		scan();
		if(n<=500){
			
		
		vector <vector<vector<int> > > dp;
		for(int j=0;j<=n/2+2;j++){
			vector<vector<int> > tt(n/2+3);
			for(int k=0;k<=n/2+2;k++){
				for(int l=0;l<=n/2+2;l++){
					tt[k].push_back(0);
				}
			}
			dp.push_back(tt);
		}
		ans=-1;
		for(int j=0;j<=n/2;j++){
			for(int k=0;k<=n/2;k++){
				if(j+k==n){
					break;
				}
				for(int l=0;l<=n/2;l++){
					int f=j+k+l;
					if(f>n){
						break;
					}
					if(j!=0){
						dp[j][k][l]=max(dp[j][k][l],dp[j-1][k][l]+a[f][1]);
					}
					if(k!=0){
						dp[j][k][l]=max(dp[j][k][l],dp[j][k-1][l]+a[f][2]);
					}
					if(l!=0){
						dp[j][k][l]=max(dp[j][k][l],dp[j][k][l-1]+a[f][3]);
					}
					
					
					
					ans=max(ans,dp[j][k][l]);
				}
			}
		}
		cout<<ans<<endl;
		}else{
			vector <vector<int> > dp(n+3);
		for(int j=0;j<=n/2+3;j++){
			for(int k=0;k<=n/2+3;k++){

				dp[j].push_back(0);
				
			}
		}
		ans=-1;
		for(int j=0;j<=n/2;j++){
			for(int k=0;k<=n/2;k++){
				int f=j+k;
				if(f>n){
					break;
				}
				if(j!=0){
					dp[j][k]=max(dp[j][k],dp[j-1][k]+a[f][1]);
				}
				if(k!=0){
					dp[j][k]=max(dp[j][k],dp[j][k-1]+a[f][2]);
				}
					
					
				ans=max(ans,dp[j][k]);
			}
		}
		
		cout<<ans<<endl;
		}
		
	}
		
	return 0;
}

/*



18
4
13

*/
