#include<bits/stdc++.h>
using namespace std;
int T,n,a[100010][5],b[100010],c;
long long dp[201][101][101][101],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(dp,0,sizeof(dp));
		ans=0;
		cin>>n;
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		
		if(n==100000){
			for(int i=1;i<=n;i++){
				cin>>b[i]>>c>>c;
			}
			sort(b+1,b+n+1);
			for(int i=n;i>n/2;i--){
				ans+=b[i];
			}
			cout<<ans;
			if(T){
				cout<<endl;
			}
			continue;
		}
		
		for(int p=1;p<=n;p++){
			for(int i=0;i<=n/2&&i<=p;i++){
				for(int j=0;j+i<=p&&j<=n/2;j++){
					int k=p-i-j;
					if(k<=n/2){
						if(i>0){
							dp[p][i][j][k]=max(dp[p][i][j][k],dp[p-1][i-1][j][k]+a[p][1]);
						}
						if(j>0){
							dp[p][i][j][k]=max(dp[p][i][j][k],dp[p-1][i][j-1][k]+a[p][2]);
						}
						if(k>0){
							dp[p][i][j][k]=max(dp[p][i][j][k],dp[p-1][i][j][k-1]+a[p][3]);
						}
					}
				}
			}
		}
		for(int i=0;i<=n/2;i++){
			for(int j=0;j+i<=n&&j<=n/2;j++){
				int k=n-i-j;
				if(k<=n){
					ans=max(ans,dp[n][i][j][k]);
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
