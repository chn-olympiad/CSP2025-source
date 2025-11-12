#include<bits/stdc++.h>
using namespace std;
const int N=300;
int dp[N][N][N]; 
int dat[N][3];
long long max1=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,n;
	cin >> T;
	while(T--){
		cin >> n;
		memset(dp,0,sizeof dp);
		memset(dat,0,sizeof dat); 
		max1=0;
		dp[0][0][0]=0;
		for(int i=1;i<=n;i++){
			cin >> dat[i][0] >> dat[i][1] >> dat[i][2];
		}
		dp[1][0][0]=dat[1][0];
		dp[0][1][0]=dat[1][1];
		dp[0][0][1]=dat[1][2];
		int cnt=1;
		for(int i=0;i<=n;i++){
			cnt=i+1;
			for(int j=0;j<=n;j++){
				cnt=i+j+1;
				for(int k=0;k<=n,cnt<=n;k++){
					cnt=i+j+k+1;
					//cout << cnt << endl; 
					dp[i+1][j][k]=max(dp[i][j][k],dp[i+1][j][k]);
					dp[i][j+1][k]=max(dp[i][j][k],dp[i][j+1][k]);
					dp[i][j][k+1]=max(dp[i][j][k],dp[i][j][k+1]);
					if(i<n/2){
						dp[i+1][j][k]=max(dp[i][j][k]+dat[cnt][0],dp[i+1][j][k]);
						if(max1 < dp[i+1][j][k]){
					//		cout << "cnt=" << cnt << endl;
					//		cout << "i plus" << endl;
					//		cout << "max1=" << dp[i+1][j][k] << ":" << i+1 << " " << j << " " << k << endl; 
							max1=dp[i+1][j][k];
						}
					}
					if(j<n/2){
						dp[i][j+1][k]=max(dp[i][j][k]+dat[cnt][1],dp[i][j+1][k]);
						if(max1 < dp[i][j+1][k]){
					//		cout << "cnt=" << cnt << endl;
					//		cout << "j plus" << endl;
					//		cout << "max1=" << dp[i][j+1][k] << " " << i << " " << j+1 << " " << k << endl; 
							max1=dp[i][j+1][k];
						}
					}
					if(k<n/2){
						dp[i][j][k+1]=max(dp[i][j][k]+dat[cnt][2],dp[i][j][k+1]);
						if(max1 < dp[i][j][k+1]){
					//		cout << "cnt=" << cnt << endl;
						//	cout << "k plus" << endl;
					//		cout << "max1=" << dp[i][j][k+1] << " " << i << " " << j << " " << k+1  << endl; 
							max1=dp[i][j][k+1];
						}
					}
				}
			}
		}
		cout << max1 << endl;
	} 
	return 0;
} 
