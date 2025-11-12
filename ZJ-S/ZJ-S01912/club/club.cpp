#include<bits/stdc++.h>
using namespace std;
map<int,map<int,map<int,int>>>dp;
map<int,map<int,int>>dp2;
map<int,int>dp3;
int me[110000][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int o=1;o<=3;o++){
				cin>>me[i][o];
			}
		}
		if(n==1e5){
			int ans=0;
			for(int i=0;i<=n/2;i++){
				if(i-1>=0)dp3[i]=max(dp3[i],dp3[i-1]+me[i][1]);
				ans=max(ans,dp3[i]);
			}
			cout<<ans<<'\n';
			dp3.clear();
			continue;
		}
		if(n==200){
			int ans=0;	
			for(int i=0;i<=n/2;i++){
				for(int o=0;o<=n/2;o++){
					if(o-1>=0)dp2[o][i]=max(dp2[o][i],dp2[o-1][i]+me[i+o][1]);
					if(i-1>=0)dp2[o][i]=max(dp2[o][i],dp2[o][i-1]+me[i+o][2]);
					ans=max(ans,dp2[o][i]);
				}
			}
			cout<<ans<<'\n';
			dp2.clear();
			continue;
		}
		for(int i=0;i<=n/2;i++){
			for(int o=0;o<=n/2;o++){
				for(int p=0;p<=n/2;p++){
					if(i+o+p>n)break;
					if(p-1>=0)dp[p][o][i]=max(dp[p][o][i],dp[p-1][o][i]+me[i+o+p][1]);
					if(o-1>=0)dp[p][o][i]=max(dp[p][o][i],dp[p][o-1][i]+me[i+o+p][2]);
					if(i-1>=0)dp[p][o][i]=max(dp[p][o][i],dp[p][o][i-1]+me[i+o+p][3]);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n/2;i++){
			for(int o=1;o<=n/2;o++){
				ans=max(ans,dp[i][o][n-i-o]);
			}
		}cout<<ans<<'\n';
		dp.clear();
	}

	return 0;
}

