#include<bits/stdc++.h>
#define ll long long
int const maxn=3*1e7;
using namespace std;
ll b,c,n,m,p,q,t,dp11_1[200][100],dp11_2[200][100],dp11_3[200][100],dpp[200][200];//dp[y][x]  the biggest value(the y student x size)
ll dp1[200],dp2[200],dp3[200],ans[maxn],cnt,a11[100000],sum,s2,s3;
struct myst {
	int c1,c2,c3;
};
myst a[maxn];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","r",stdin);
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n/2; j++) {
				dp1[j]=dp2[j]=dp3[j]=0;
				dp11_1[i][j]=dp11_2[i][j]=dp11_3[i][j]=0;
			}
		}
//		for(int i=1; i<=n; i++) {
//			cin>>a[i].c1>>a[i].c2>>a[i].c3;
//		}
//		for(int i=1; i<=n; i++) {
//			dp1[i][1]=max(dp1[i-1][])
//		}

		for(int i=1; i<=n; i++) {
			cin>>a[i].c1>>a[i].c2>>a[i].c3;
			a11[i]=a[i].c1;
			s2+=a[i].c2;
			s3+=a[i].c3;
		}
		if(s2+s3==0) {
			sort(a11+1,a11+1+n);
			for(int i=n/2; i>=1; i--) {
				sum+=a11[i];
			}
			cout<<sum<<endl;
			continue;
		}
		for(int i=1; i<=n; i++) {
			for(int w=1; w<=n/2; w++) {
				dp11_1[i][w]=max(dp11_1[i-1][w],dp11_1[i-1][w-1]+a[i].c1);
				dp11_2[i][w]=max(dp11_2[i-1][w],dp11_2[i-1][w-1]+a[i].c2);
				dp11_3[i][w]=max(dp11_3[i-1][w],dp11_3[i-1][w-1]+a[i].c3);
				dp1[w]=max(dp1[w],dp11_1[i][w]);
				dp2[w]=max(dp2[w],dp11_2[i][w]);
				dp3[w]=max(dp3[w],dp11_3[i][w]);
			}
		}
//		for(int i=1; i<=n; i++) {
//			for(int j=1; j<=n; j++) {
//				for(int k=1; k<=n; k++) {
//					if(i+j+k!=n) {
//						continue;
//					}
//					ans[++cnt]=dp1[i]+dp2[j]+dp3[k];
//				}
//			}
//		}
		for(int i=1;i<=n;i++){
			for(int j=n;j>=1;j--){
				ans[++cnt]=dp1[i]+dp2[i]+dp3[i];
			}
		}
		sort(ans+1,ans+1+cnt);
		cout<<ans[cnt]<<endl;
		for(int i=1; i<=cnt; i++) {
			ans[i]=0;
		}
		cnt=0;
	}
	return 0;
}
