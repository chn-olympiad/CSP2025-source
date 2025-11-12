#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,ma,i,j,k,x,y,z,fl,ans,a[100010][4],b[100010],dp[210][210][210];
bool cmp(int t,int w){return t>w;}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while (T--){
		cin>>n;ma=0;
		for (i=1;i<=n;i++)
			for (j=1;j<=3;j++) cin>>a[i][j];
		
		fl=0;
		for (i=1;i<=n;i++)
			for (j=2;j<=3;j++)
				if (a[i][j]!=0) fl=1;
		if (fl==0){
			ans=0;
			for (i=1;i<=n;i++) b[i]=a[i][1];
			sort(b+1,b+1+n,cmp);
			for (i=1;i<=n/2;i++) ans+=b[i];
			cout<<ans<<"\n";
			continue;
		}
		
		for (i=1;i<=n;i++)
			for (j=0;j<=n/2;j++)
				for (k=0;k<=n/2;k++) dp[i][j][k]=0;
		for (i=1;i<=n;i++)
			for (j=0;j<=n/2;j++)
				for (k=0;k<=n/2;k++){
					if (i-j-k>n/2||i-j-k<0) continue;
					x=y=z=0;
					if (j>0) x=dp[i-1][j-1][k]+a[i][1];
					if (k>0) y=dp[i-1][j][k-1]+a[i][2];
					if (i-j-k>0) z=dp[i-1][j][k]+a[i][3];
					dp[i][j][k]=max(x,max(y,z));
				}
		for (i=0;i<=n/2;i++)
			for (j=0;j<=n/2;j++){
				if (n-i-j>n/2) continue;
				ma=max(ma,dp[n][i][j]);
			}
		cout<<ma<<"\n";
	}
	return 0;
}
