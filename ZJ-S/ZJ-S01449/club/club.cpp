#include <bits/stdc++.h>
using namespace std;
int T,n,a[1000010][10];
long long dp[210][210][210],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
		long long  sum=0;
		for(int i=1;i<=n;i++)sum+=a[i][2]+a[i][3];
		if(sum==0){
			int k[100010];
			memset(k,0,sizeof k);
			for(int i=1;i<=n;i++)k[i]=a[i][1];
			sort(k+1,k+1+n);
			for(int i=n;i>n/2;i--)sum+=k[i];
			cout<<sum<<"\n";
			continue;
		}
		for(int i=0;i<210;i++){
			for(int j=0;j<210;j++){
				for(int k=0;k<210;k++){
					dp[i][j][k]=0;
				}
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int x=0;x<=i;x++){
				for(int y=0;y<=i-x;y++){
					int z=i-x-y;
					if(z<0||y<0||x+y+z!=i)continue;
					if(x>0&&x<=n/2)dp[x][y][z]=max(dp[x-1][y][z]+a[i][1],dp[x][y][z]);
					if(y>0&&y<=n/2)dp[x][y][z]=max(dp[x][y-1][z]+a[i][2],dp[x][y][z]);
					if(z>0&&z<=n/2)dp[x][y][z]=max(dp[x][y][z-1]+a[i][3],dp[x][y][z]);
					ans=max(ans,dp[x][y][z]);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
