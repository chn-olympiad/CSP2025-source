#include<bits/stdc++.h>
using namespace std;

struct node {
	long long x;
	long long y;
	long long z;
} a[205];
long long dp[100005],i,j,k,n,t,ans,f,b[205][205];
void dfs(long long x,long long y,long long z,long long s,long long u) {
	if(x+y+z==n) {
		ans=max(ans,s);
		return ;
	}
	if(u>n) {
		return ;
	}
	if(x<n/2) {
		dfs(x+1,y,z,s+a[u].x,u+1);
	}
	if(y<n/2) {
		dfs(x,y+1,z,s+a[u].y,u+1);
	}
	if(z<n/2) {
		dfs(x,y,z+1,s+a[u].z,u+1);
	}
	return ;
}
bool cmp(node a,node b) {
	return a.x>b.x;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		ans=0;
		cin>>n;
		f=0;
		for(i=1; i<=n; i++) {
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].z>0) {
				f=2;
			} else {
				if(a[i].y>0) {
					f=1;
				}
			}
		}
		if(n>30) {
			if(f==0) {
				sort(a+1,a+n+1,cmp);
				for(i=1; i<=n/2; i++) {
					ans+=a[i].x;
				}
				cout<<ans<<"\n";
			} else {
				if(f==1) {
					for(i=1; i<=n; i++) {
						for(j=1; j<=min(i,n/2); j++) {
							if(j<=i-1) {
								b[i][j]=max(b[i-1][j-1]+a[i].x,b[i-1][j]+a[i].y);
							} else {
								b[i][j]=b[i-1][j-1]+a[i].x;
							}
//							cout<<b[i][j]<<" "<<i<<" "<<j<<"\n";
						}
					}
					cout<<b[n][n/2]<<"\n";
				} else {
					for(i=1; i<=n; i++) {
						ans+=max(a[i].x,max(a[i].y,a[i].z));
					}
					cout<<ans<<"\n";
				}
			}
		} else {
			dfs(0,0,0,0,1);
			cout<<ans<<"\n";
		}
	}
	return 0;
}
//#include<bits/stdc++.h>
//using namespace std;
//
//struct node{
//	long long  x;
//	long long  y;
//	long long  z;
//}a[205];
//long long t,n,dp[205][105][105],i,j,k,ans;
//int main() {
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
//	cin>>t;
//	while(t--) {
//		cin>>n;
//		ans=LLONG_MIN;
//		for(i=1; i<=n; i++) {
//			cin>>a[i].x>>a[i].y>>a[i].z;
//		}
//		dp[1][1][0]=a[1].x;
//		dp[1][0][1]=a[1].y;
//		dp[1][0][0]=a[1].z;
//		for(i=1; i<=n; i++) {
//			for(j=1; j<=n/2; j++) {
//				for(k=1; k<=n/2; k++) {
//					if(j+k>i){
//						continue;
//					}
//					if(j<1&&k<1) {
//						dp[i][j][k]=dp[i-1][j][k]+a[i].z;
//					} else {
//						if(j<1) {
//							dp[i][j][k]=max(dp[i-1][j][k]+a[i].z,dp[i-1][j][k-1]+a[i].y);
//						} else {
//							if(j<1) {
//								dp[i][j][k]=max(dp[i-1][j][k]+a[i].z,dp[i-1][j][k-1]+a[i].y);
//							} else {
//								dp[i][j][k]=max(dp[i-1][j][k]+a[i].z,max(dp[i-1][j-1][k]+a[i].x,dp[i-1][j][k-1]+a[i].y));
//							}
//						}
//					}
//				}
//			}
//		}
//		for(i=1; i<=n/2; i++) {
//			for(j=1; j<=n/2; j++) {
//				if(n-i-j>n/2){
//					continue;
//				}
////				cout<<i<<" "<<j<<" "<<dp[n][i][j]<<"\n";
//				ans=max(ans,dp[n][i][j]);
//			}
//		}
//		cout<<ans<<"\n";
//	}
//	return 0;
//}