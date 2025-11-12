#include<bits/stdc++.h>
using namespace std;
const int le=100010;
int t,n;
int a[le][3],dp[210][110][110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				scanf("%d",&a[i][j]);
			}
		}
		if(n<=200){
			memset(dp,128,sizeof(dp));
			dp[0][0][0]=0;
			for(int i=1;i<=n;i++){
				int mxj=min(n/2,i-1);
				for(int j=0;j<=mxj;j++){
					int mxk=min(i-j-1,n/2);
					for(int k=max(0,i-1-j-n/2);k<=mxk;k++){
						//cout<<i<<" "<<j<<" "<<k<<" "<<i-j-k<<endl;
						if(j!=n/2){
							dp[i][j+1][k]=max(dp[i][j+1][k],dp[i-1][j][k]+a[i][0]);
						}
						if(k!=n/2){
							dp[i][j][k+1]=max(dp[i][j][k+1],dp[i-1][j][k]+a[i][1]);
						}
						if(i-1-j-k!=n/2){
							dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][2]);
						}
					}
				}
			}
			int ans=0;
			for(int j=0;j<=n/2;j++){
				for(int k=n/2-j;k<=n/2;k++){
					ans=max(ans,dp[n][j][k]);
				}
			}
			/*for(int i=1;i<=n;i++){
				for(int j=0;j<=n/2;j++){
					for(int k=0;k<=n/2;k++){
						cout<<i<<" "<<j<<" "<<k<<" "<<i-j-k<<" ";
						if(j>=0&&k>=0&&i-j-k>=0)cout<<dp[i][j][k];
						cout<<endl;
					}
					cout<<endl;
				}
				cout<<endl;
			}*/
			cout<<ans<<endl;
		}
		else{
			bool flag1=1,flag2=1;
			for(int i=1;i<=n;i++){
				if(a[i][1]!=0) flag1=0;
				if(a[i][2]!=0) flag2=0;
			}
			if(flag1){
				sort(a[0]+1,a[0]+n+1,cmp);
				int ans=0;
				for(int i=1;i<=n/2;i++){
					ans+=a[i][0];
				}
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}
