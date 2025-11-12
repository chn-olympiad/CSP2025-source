#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N][4],b[4];
struct node {
	int date,a[4];
} dp[N][4];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1; i<=t; i++) {
		cin>>n;
		for(int j=1; j<=n; j++) {
			dp[j][1].date=0,dp[j][2].date=0,dp[j][3].date=0,b[j]=0;
			for(int g=1; g<=3; g++) dp[j][g].a[1]=0,dp[j][g].a[2]=0,dp[j][g].a[3]=0;
		}
		int k=n>>1;
		for(int j=1; j<=n; j++)
			cin>>a[j][1]>>a[j][2]>>a[j][3];
		for(int j=1; j<=n; j++)
			for(int g=0; g<j; g++) {
				for(int s=1; s<=3; s++) {
					int m;
					bool zx=0;
					if(dp[g][1].date+a[j][s]>dp[j][s].date&&dp[g][1].a[s]<k)
						dp[j][s].date=dp[g][1].date+a[j][s],m=1,zx=1;
					if(dp[g][2].date+a[j][s]>dp[j][s].date&&dp[g][2].a[s]<k)
						dp[j][s].date=dp[g][2].date+a[j][s],m=2,zx=1;
					if(dp[g][3].date+a[j][s]>dp[j][s].date&&dp[g][3].a[s]<k)
						dp[j][s].date=dp[g][3].date+a[j][s],m=3,zx=1;
					if(zx==0)
						if(dp[g][1].a[s]<k)
							m=1;
						else if(dp[g][2].a[s]<k)
							m=2;
						else if(dp[g][3].a[s]<k)
							m=3;
					dp[j][s].a[1]=dp[g][m].a[1];
					dp[j][s].a[2]=dp[g][m].a[2];
					dp[j][s].a[3]=dp[g][m].a[3];
					dp[j][s].a[s]++;
				}
//				for(int j=1; j<=n; j++) {
//					cout<<dp[j][1].date<<' '<<dp[j][2].date<<' '<<dp[j][3].date<<"  "<<dp[j][1].a[1]<<' '<<dp[j][1].a[2]<<' '<<dp[j][1].a[3]<<"  "<<dp[j][2].a[1]<<' '<<dp[j][2].a[2]<<' '<<dp[j][2].a[3]<<"  "<<dp[j][3].a[1]<<' '<<dp[j][3].a[2]<<' '<<dp[j][3].a[3]<<endl;
//				}
//				cout<<endl;
			}
		cout<<max(dp[n][1].date,max(dp[n][2].date,dp[n][3].date))<<endl;
	}
	return 0;
}