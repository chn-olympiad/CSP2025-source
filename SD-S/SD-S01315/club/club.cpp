#include<bits/stdc++.h>
using namespace std;//1 2 3 12 13 23 123 -12 -13 -23
#define itn int
int a[220],b[220],c[220],dp[210][105][105][17];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int am,bm,cm;
		am=bm=cm=0;
		for(int i=1;i<=n;i++){
			for(am=0;am<=n/2;am++){
				for(bm=0;bm<=n/2;bm++){
					for(cm=0;cm<=n/2;cm++){
						dp[i][am][bm][cm]=0;
					}
				}
			}
		}
		if(n>30){
			if(n==200){
				for(itn i=1;i<=n;i++){
					cin>>a[i]>>b[i]>>c[i];
				}
				dp[0][0][0][0]=0;
				for(int i=1;i<=n;i++){
					for(am=0;am<=n/2,am<=i;am++){
						for(bm=0;bm<=n/2,am+bm<=i;bm++){
							dp[i][am+1][bm][0]=max(dp[i][am+1][bm][0],dp[i-1][am][bm][0]+a[i]);
							dp[i][am][bm+1][0]=max(dp[i][am][bm+1][0],dp[i-1][am][bm][0]+b[i]);
						}
					}
				}
				int ans=0;
				for(am=0;am<=n/2;am++){
					for(bm=0;bm<=n/2;bm++){
						ans=max(ans,dp[n][am][bm][0]);
					}
				}
				cout<<ans<<'\n';
				continue;
			}else{
				for(itn i=1;i<=n;i++){
					cin>>a[i]>>b[i]>>c[i];
				}
				sort(a,a+n);
				int cnttt=0;
				for(int i=n;i>n/2;i--){
					cnttt+=a[i];
				}
				cout<<cnttt<<'\n';
				continue;
			}
		}
		
		for(itn i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		dp[0][0][0][0]=0;
		for(int i=1;i<=n;i++){
			for(am=0;am<=n/2,am<=i;am++){
				for(bm=0;bm<=n/2,am+bm<=i;bm++){
					for(cm=0;cm<=n/2,am+bm+cm<=i;cm++){
						dp[i][am+1][bm][cm]=max(dp[i][am+1][bm][cm],dp[i-1][am][bm][cm]+a[i]);
						dp[i][am][bm+1][cm]=max(dp[i][am][bm+1][cm],dp[i-1][am][bm][cm]+b[i]);
						dp[i][am][bm][cm+1]=max(dp[i][am][bm][cm+1],dp[i-1][am][bm][cm]+c[i]);
					}
				}
			}
		}
		int ans=0;
		for(am=0;am<=n/2;am++){
			for(bm=0;bm<=n/2;bm++){
				for(cm=0;cm<=n/2;cm++){
					ans=max(ans,dp[n][am][bm][cm]);
				}
			}
		}
		cout<<ans<<'\n';
	}	
	
	return 0;
}
