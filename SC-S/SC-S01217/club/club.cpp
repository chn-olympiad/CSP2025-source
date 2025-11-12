#include<bits/stdc++.h>
#define int long long
using namespace	std;
const int N=505;
int T,n,a[N][4],dp[N][N][N],f[N][4],ans;
bool flagA=1;
int b[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		flagA=1,ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]||a[i][3])flagA=0;
			b[i]=a[i][1];
		}
		if(flagA){
			sort(b+1,b+n+1);
			for(int i=n;i>=n-n/2+1;i--){
				ans+=b[i];
			}
			cout<<ans<<"\n";
			continue;
		}
			for(int i=0;i<=n/2;i++){
				for(int j=0;j<=n/2;j++){
					for(int k=0;k<=min(n/2,n-i-j);k++){
						dp[i][j][k]=0;
						if(i==0&&j==0&&k==0)continue;
						int l=i+j+k;
						if(i>0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[l][1]);
						if(j>0)dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+a[l][2]);
						if(k>0)dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+a[l][3]);
						ans=max(ans,dp[i][j][k]);
					}
					
				}
			}
			cout<<ans<<"\n";
	//	}
		
	}
	return 0;
}

