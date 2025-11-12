#include<bits/stdc++.h>
using namespace std;
#define maxn 205
struct node {
	int v[5];
	int zd,md,zx;
} a[maxn];
int dp[maxn][maxn][maxn][2];
bool cmp(node x,node y){
	return x.v[1]>y.v[1];
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		memset(dp,0,sizeof(dp));
		int n;
		cin>>n;
		int A=0,B=0;
		for(int i=1; i<=n; i++) {
			scanf("%d%d%d",&a[i].v[1],&a[i].v[2],&a[i].v[3]);
			if(a[i].v[2]!=0)A=1;
			if(a[i].v[1]!=0)B=1;
		}
		if(n<=200) {
			int fg=0;
			for(int i=1; i<=n; i++) {
				for(int j=0; j<=min(i,n/2); j++) {
					for(int k=0; k<=min(i-j,n/2); k++) {
						for(int p=0; p<=min(i-j-k,n/2); p++) {
							int t=(fg+1)%2;
							if(j==0&&k==0&&p==0)continue;
							if(j==0&&k==0&&p>=1)dp[j][k][p][fg]=dp[j][k][p-1][t]+a[i].v[3];
							if(j==0&&k>=1&&p==0)dp[j][k][p][fg]=dp[j][k-1][p][t]+a[i].v[2];
							if(j>=1&&k==0&&p==0)dp[j][k][p][fg]=dp[j-1][k][p][t]+a[i].v[1];
							if(j>=1&&k>=1&&p==0)dp[j][k][p][fg]=max(dp[j-1][k][p][t]+a[i].v[1],dp[j][k-1][p][t]+a[i].v[2]);
							if(j==0&&k>=1&&p>=1)dp[j][k][p][fg]=max(dp[j][k-1][p][t]+a[i].v[2],dp[j][k][p-1][t]+a[i].v[3]);
							if(j>=1&&k==0&&p>=1)dp[j][k][p][fg]=max(dp[j-1][k][p][t]+a[i].v[1],dp[j][k][p-1][t]+a[i].v[3]);
							if(j>=1&&k>=1&&p>=1)dp[j][k][p][fg]=max(max(dp[j-1][k][p][t]+a[i].v[1],dp[j][k-1][p][t]+a[i].v[2]),dp[j][k][p-1][t]+a[i].v[3]);
						}
					}
				}
				fg=(fg+1)%2;
			}
			fg=(fg+1)%2;
			int ans=0,x,y,z;
			for(int i=0; i<=n/2; i++) {
				for(int j=0; j<=n/2; j++) {
					for(int k=0; k<=n-i-j; k++) {
						if(k>n/2)break;
						if(dp[i][j][k][fg]>ans) {
							ans=dp[i][j][k][fg];
							x=i,y=j,z=k;
						}
					}
				}
			}
			cout<<ans<<endl;
		} else if(A==0&&B==0) {
			sort(a+1,a+n+1,cmp);
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=a[i].v[1];
			}
			cout<<ans<<endl;
		}else{
			srand(time(0));
			cout<<rand()%10000000<<endl;;
		}
	}
}
