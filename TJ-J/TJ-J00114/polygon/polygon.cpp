#include<bits/stdc++.h>
using namespace std;
long long dp[500][50000][3]={0};
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		for(int j=n;j>=0;j--){
			for(int k=n*100;k>0;k--){
				for(int l=0;l<3;l++){
					if(dp[j][k][l]){
						dp[max(j,t)][k+t][min(l+1,2)]+=dp[j][k][l];
						dp[max(j,t)][k+t][min(l+1,2)]%=998244353;
						clog<<dp[max(j,t)][k+t][min(l+1,2)]<<" "<<max(j,t)<<" "<<(k+t)<<" "<<(l+1)<<endl;
					}
				}
			}
		}
		dp[t][t][0]++;
	}
	//clog<<dp[5][13][2];
	long long ans=0;
	for(int j=0;j<=n;j++){
		for(int k=0;k<n*100;k++){
			if(j*2<k&&dp[j][k][2]){
				//clog<<dp[j][k][2]<<" "<<j<<" "<<k<<endl;
				ans+=dp[j][k][2];
				ans%=998244353;
			}
		}
	}
	cout<<ans;
	fclose(stdin); 
	fclose(stdout);
	return 0;
}
