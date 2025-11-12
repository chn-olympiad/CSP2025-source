//许明宇 SN-S00653 西安高新第一学校
#include <bits/stdc++.h>
using namespace std;
int t,f[205][102][102][102];
void solve() {
	bool is_A=1,is_B=1;
	memset(f,0,sizeof(f));
	int n,a[1005],b[1005],c[1005],ans=0;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>b[i]>>c[i];
		if(b[i]!=0) {
			is_A=0;
		}
		if(c[i]!=0) {
			is_B=0;
			is_A=0;
		}
	}
	if(is_A) {
		sort(a+1,a+n+1);
		for(int i=ceil(1.0*n/2); i<=n; i++) {
			ans+=a[i];
		}
		cout<<ans<<'\n';
		return;
	}
	if(is_B) {
		for(int i=1; i<=n; i++) {
			for(int j=0; j<=n/2; j++) {
				for(int k=0; k<=min(n-j,n/2); k++) {
					if(j>0) {
						f[i][j][k][0]=max(f[i][j][k][0],f[i-1][j-1][k][0]+a[i]);
					}
					if(k>0) {
						f[i][j][k][0]=max(f[i][j][k][0],f[i-1][j][k-1][0]+b[i]);
					}
					ans=max(ans,f[i][j][k][0]);
				}
			}
		}
		cout<<ans<<'\n';
		return;
	}
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=n/2; j++) {
			for(int k=0; k<=min(n-j,n/2); k++) {
				
				for(int l=0; l<=min(n-j-k,n/2); l++) {
					if(j>0) {
						f[i][j][k][l]=max(f[i][j][k][l],f[i-1][j-1][k][l]+a[i]);
					}
					if(k>0) {
						f[i][j][k][l]=max(f[i][j][k][l],f[i-1][j][k-1][l]+b[i]);
					}
					if(l>0) {
						f[i][j][k][l]=max(f[i][j][k][l],f[i-1][j][k][l-1]+c[i]);
					}
					ans=max(ans,f[i][j][k][l]);
					//f[i][j][k][l]=max(f[i-1][j-1][k][l]+a[i],max(f[i-1][j][k-1][l]+b[i],f[i-1][j][k][l-1]+c[i]));
				}
			}
		}
	}
	cout<<ans<<'\n';
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		solve();
	}
	return 0;
}
