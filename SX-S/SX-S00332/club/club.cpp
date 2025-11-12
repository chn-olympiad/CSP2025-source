#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
int t,n;
int f[205][105][105][105];
bool f1,f2;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int kk=1;kk<=t;kk++){
		f1=0,f2=0;
		memset(f,0,sizeof f);
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]>0||c[i]>0){
				f1=1;
			}
		}
		if(!f1){
			sort(a+1,a+n+1);
			for(int i=n;i>=n/2;i--){
				ans+=a[i];
			}
			cout<<ans<<endl;
			continue;
		}
//		if(!f2){
//			for(int i=0;i<=n;i++){
//				for(int j=0;j<=n/2;j++){
//					for(int k=0;k<=n/2;k++){
//						dp[i][j][k]=max(dp[i-1][j-1][k]+a[i],dp[i-1][j][k-1]+b[i]);
//					}
//				}
//			}
//			cout<<dp[n][n/2][n/2]<<endl;
//			for(int i=1;i<=n;i++){
//				for(int j=0;j<=n/2;j++){
//					for(int k=0;k<=n/2;k++){
////						if(a[i]>b[i])
////						f[i][j][k][0]=max(f[i][j][k][0],f[i-1][j-1][k][0]+a[i]);
////						else{
////						f[i][j][k][0]=max(f[i][j][k][0],f[i-1][j][k-1][0]+b[i]);
////							
////						}
//						f[i][j][k][0]=max(f[i][j][k][0],max(f[i-1][j][k-1][0]+b[i],f[i-1][j-1][k][0]+a[i]));
//					}
//				}
//			}
//			cout<<f[n][n/2][n/2][0];
//			continue;
//		}
		for(int l=1;l<=n;l++){
			for(int i=0;i<=min(l,n/2);i++){
				for(int j=0;j<=min(l,n/2);j++){
					for(int k=0;k<=min(l,n/2);k++){
						if(i>0){
							f[l][i][j][k]=max(f[l][i][j][k],f[l-1][i-1][j][k]+a[l]);
						}
						if(j>0){
							f[l][i][j][k]=max(f[l][i][j][k],f[l-1][i][j-1][k]+b[l]);
						}
						if(k>0){
							f[l][i][j][k]=max(f[l][i][j][k],f[l-1][i][j][k-1]+c[l]);
						}
						if(i+j>=n/2)
							ans=max(ans,f[n][i][j][n-i-j]);
						}
//						f[l][i][j][k]=max(f[l-1][i-1][j][k]+a[l],max(f[l-1][i][j-1][k]+b[l],f[l-1][i][j][k-1]+c[l]));
					}	
				}
			}cout<<ans<<endl;
		}
//		for(int i=0;i<=n/2;i++){
//			for(int j=0;j<=n/2;j++){
//						if(i+j>=n/2)
//							ans=max(ans,f[n][i][j][n-i-j]);
						
	
	return 0;
}
