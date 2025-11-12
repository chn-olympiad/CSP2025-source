#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e2+10;
const int M=1e5+10;
struct node {
	int x,y,z;
} a[M];
node b[M];
int t,n;
int dp[N][N][N];
bool cmp1(node x,node y) {
	return x.x>y.x;
}
bool cmp2(node x,node y) {
	return x.y-x.x>y.y-y.x;
}
bool cmp3(node x,node y){
	return x.x+x.y-x.z>y.x+y.y-y.z;
}
bool cmp4(node x,node y){
	return x.y-x.z>y.y-y.z;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		int ans=-114514,flag1=0,flag2=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y!=0||a[i].z!=0)flag1=1;
			if(a[i].z!=0)flag2=1;
		}
		if(n<=1000) {
			for(int i=0; i<=n; i++)
				for(int j=0; j<=n; j++)
					for(int k=0; k<=n; k++)dp[i][j][k]=0;
			for(int i=1; i<=n; i++)
				for(int j=0; j<=n/2&&j<=i; j++)
					for(int k=0; k<=n/2&&j+k<=i; k++) {
						if(i-j-k<=n/2) {
							dp[i][j][k]=dp[i-1][j][k]+a[i].z;
							if(j>0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i].x);
							if(k>0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i].y);
							ans=max(ans,dp[i][j][k]);
						}
					}
		} else if(flag1==0) {
			sort(a+1,a+n+1,cmp1);
			ans=0;
			for(int i=1; i<=n/2; i++)ans+=a[i].x;
		} else if(flag2==0) {
			sort(a+1,a+n+1,cmp2);
			ans=0;
			for(int i=1; i<=n/2; i++)ans+=a[i].y;
			for(int i=n/2+1; i<=n; i++)ans+=a[i].x;
		} else {
			sort(a+1,a+n+1,cmp3);
			int sum1=0,sum2=0,sum3=0;
			for(int i=1; i<=n; i++) {
				if(a[i].x>=a[i].y&&a[i].x>=a[i].z&&sum1<n/2) {
					ans+=a[i].x;
					sum1++;
				} else if(a[i].y>=a[i].z&&sum2<n/2){
					ans+=a[i].y;
					sum2++;
				}else{
					ans+=a[i].z;
					sum3++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
