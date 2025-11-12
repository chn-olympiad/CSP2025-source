#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,a[N][5],dp[210][110][110],b[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{	
		int ans=0,suma=0,sumb=0;
		cin>>n;
		for(int i=0;i<=n;i++)for(int j=0;j<=min(i,n/2);j++)for(int k=0;k<=min(n/2,i-j);k++)dp[i][j][k]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3],b[i]=a[i][1];
			if(a[i][2]==0)suma++;
			if(a[i][3]==0)sumb++;
		}
		if(suma==n&&sumb==n){
			sort(b+1,b+1+n);
			for(int i=n/2+1;i<=n;i++)ans+=b[i];
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)for(int j=0;j<=min(i,n/2);j++)for(int k=0;k<=min(n/2,i-j);k++){
			int s=i-j-k;
			if(s>n/2)continue;
			if(j)dp[i][j][k]=max(dp[i-1][j-1][k]+a[i][1],dp[i][j][k]);
			if(k)dp[i][j][k]=max(dp[i-1][j][k-1]+a[i][2],dp[i][j][k]);
			if(s)dp[i][j][k]=max(dp[i-1][j][k]+a[i][3],dp[i][j][k]);
			ans=max(ans,dp[i][j][k]);
		}
		cout<<ans<<endl;
	}
	return 0;
}