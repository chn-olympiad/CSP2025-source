#include<bits/stdc++.h>
using namespace std;
int T,n,dp[105][105][105],maxx;
struct node {
	int a,b,c;
} z[100005];
bool cmp1(node x,node y) {
	return x.a>y.a;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n;
		if(n<=205) {
			memset(dp,0,sizeof(dp));
			maxx=0;
			for(int i=1; i<=n; ++i) cin>>z[i].a>>z[i].b>>z[i].c;
			for(int i=0; i<=n/2; ++i)
				for(int j=0; j<=n/2; ++j)
					for(int k=0; k<=min(n-i-j,n/2); ++k) {
						if(i+j+k>n) continue;
						if(i+1<=n/2) {
							dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]+z[i+j+k+1].a);
							maxx=max(maxx,dp[i+1][j][k]);
						}
						if(j+1<=n/2) {
							dp[i][j+1][k]=max(dp[i][j+1][k],dp[i][j][k]+z[i+j+k+1].b);
							maxx=max(maxx,dp[i][j+1][k]);
						}
						if(k+1<=n/2) {
							dp[i][j][k+1]=max(dp[i][j][k+1],dp[i][j][k]+z[i+j+k+1].c);
							maxx=max(maxx,dp[i][j][k+1]);
						}
					}
			cout<<maxx<<' '<<'\n';
		} else {
			int aa=0,aaa=0;
			for(int i=1; i<=n; ++i)
				cin>>z[i].a>>z[i].b>>z[i].c,aa=max(aa,z[i].b),aaa=max(aaa,z[i].c);
			if(aa==0 && aaa==0) {
				sort(z+1,z+n+1,cmp1);
				int anss=0;
				for(int i=1; i<=n/2; ++i) anss+=z[i].a;
				cout<<anss<<'\n';
			} else if(aa && aaa==0) {
				for(int i=0; i<=n/2; ++i)
					for(int j=0; j<=n/2; ++j) {
						if(i+1<=n/2) {
							dp[i+1][j][0]=max(dp[i+1][j][0],dp[i][j][0]+z[i+j+1].a);
							maxx=max(maxx,dp[i+1][j][0]);
						}
						if(j+1<=n/2) {
							dp[i][j+1][0]=max(dp[i][j+1][0],dp[i][j][0]+z[i+j+1].b);
							maxx=max(maxx,dp[i][j+1][0]);
						}
					}
				cout<<maxx<<'\n';
			}
		}
	}
	return 0;
}
