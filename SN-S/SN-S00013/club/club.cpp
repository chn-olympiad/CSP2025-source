#include<bits/stdc++.h>
using namespace std;
int T;
int dp[210][110][110],a[100010][4],u[100010];
struct st{
	int fir,sec;
}uu[100010];
bool cmp(int x,int y){
	return x>y;
}
bool cmp2(st x,st y){
	return (x.fir-x.sec)>(y.fir-y.sec);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(dp,0,sizeof(dp));
		int n;
		cin>>n;
		bool flag1=1,flag2=1;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0||a[i][3]!=0){
				flag1=0;
			}
			if(a[i][3]!=0){
				flag2=0;
			}
		}
		if(flag1){
			int ans=0;
			for(int i=1;i<=n;i++){
				u[i]=a[i][1];
			}
			sort(u+1,u+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=u[i];
			}
			cout<<ans<<"\n";
			continue;
		}
		if(flag2){
			int ans=0;
			for(int i=1;i<=n;i++){
				uu[i].fir=a[i][1];
				uu[i].sec=a[i][2];
			}
			sort(uu+1,uu+1+n,cmp2);
			for(int i=1;i<=n/2;i++){
				ans+=uu[i].fir;
			}
			for(int i=n/2+1;i<=n;i++){
				ans+=uu[i].sec;
			}
			cout<<ans<<"\n";
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=i&&j<=n/2;j++){
				for(int k=0;k+j<=i&&k<=n/2;k++){
					if(i-j-k>n/2){
						continue;
					}
					if(j>0){
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
					}
					if(k>0){
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
					}
					if(i-j-k>0){
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
					}
				}
			}
		}
		for(int j=0;j<=n/2;j++){
			for(int k=0;k+j<=n&&k<=n/2;k++){
				if(n-j-k>n/2){
					continue;
				}
				ans=max(ans,dp[n][j][k]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
