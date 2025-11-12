#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100005],b[100005],c[100005];
long long dp[500005];
long long dp1[205][205][205];
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		bool f=1,ff=1;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]||c[i]){
				f=0;
			}else if(c[i]){
				ff=0;
			}
		}
		memset(dp,0,sizeof(dp));
		memset(dp1,0,sizeof(dp1));
		if(f&&n>=200){
			sort(a+1,a+n+1);
			for(int i=n;i>=n/2;i--){
				ans+=a[i];
			}
			cout<<ans<<'\n';
		}else if(ff&&n>=200){
			for(int i=1;i<=n;i++){
				for(int j=n/2;j>=0;j--){
					if(j==0){
						dp[j]+=b[i];
					}else{
						dp[j]=max(dp[j-1]+a[i],dp[j]+b[i]);
					}
					ans=max(ans,dp[j]);
				} 
			}
			cout<<ans<<'\n';
		}else{
			for(int i=1;i<=n;i++){
				for(int j=n/2;j>=0;j--){
					for(int k=n/2;k>=0;k--){
						for(int t=n/2;t>=0;t--){
							if(j==0&&k==0&&t==0){
								dp1[j][k][t]=0;
							}else if(j==0&&k==0){
								dp1[j][k][t]=max(dp1[j][k][t],dp1[j][k][t-1]+c[i]);
							}else if(j==0&&t==0){
								dp1[j][k][t]=max(dp1[j][k][t],dp1[j][k-1][t]+b[i]);
							}else if(k==0&&t==0){
								dp1[j][k][t]=max(dp1[j][k][t],dp1[j-1][k][t]+a[i]);
							}else if(j==0){
								dp1[j][k][t]=max(dp1[j][k][t],max(dp1[j][k-1][t]+b[i],dp1[j][k][t-1]+c[i]));
							}else if(k==0){
								dp1[j][k][t]=max(dp1[j][k][t],max(dp1[j][k][t-1]+c[i],dp1[j-1][k][t]+a[i]));
							}else if(t==0){
								dp1[j][k][t]=max(dp1[j][k][t],max(dp1[j-1][k][t]+a[i],dp1[j][k-1][t]+b[i]));
							}else{
								dp1[j][k][t]=max(dp1[j][k][t],max(dp1[j-1][k][t]+a[i],max(dp1[j][k-1][t]+b[i],dp1[j][k][t-1]+c[i])));
							}
							ans=max(dp1[j][k][t],ans);
						}
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
} 
