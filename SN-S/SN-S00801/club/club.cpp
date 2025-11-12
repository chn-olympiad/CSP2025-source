#include<bits/stdc++.h>
using namespace std;
int n;
long long dp[205][205][205];
int a[100005][4];
struct node{
	int a,b,c;
}b[100005];
bool cmp(node x,node y){
	return x.a>y.a;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--) {
		memset(dp,0,sizeof(dp));
		cin>>n;
		int flag=1;
		for(int i=1; i<=n; i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=n;i++){
			b[i].a=a[i][1],b[i].b=a[i][2],b[i].c=a[i][3];
			if(a[i][2]!=0||a[i][3]!=0){
				flag=0;
				break;
			}
		}
		if(flag==1&&n>200){
			sort(b+1,b+n+1,cmp);
			long long ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=b[i].a;	
			}
			cout<<ans<<endl;
			continue;
		}
		dp[1][1][0]=a[1][1];
		dp[1][0][1]=a[1][2];
		dp[1][0][0]=a[1][3];
		for(int i=2; i<=n; i++) {
			for(int j=0; j<=i; j++) {
				for(int k=0; k<=i-j; k++) {
					int p=i-j-k;
					if(p<0) break;
					if(j<=n/2&&k<=n/2&&p<=n/2) {
						if(j>=1){
							dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
						}
						if(k>=1){
							dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
						}
						if(p>=1){
							dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
						}
					}
				}
			}
		}
		long long ans=0;
		for(int i=0; i<=n; i++) {
			for(int j=0; j<=n; j++) {
				int k=n-i-j;
				if(k<0) break;
//				cout<<i<<" "<<j<<" "<<k<<" "<<dp[n][i][j][k]<<endl;
				ans=max(ans,dp[n][i][j]);
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
/*
2
4
1 0 0
2 0 0
3 0 0
4 0 0
4
0 1 0
0 1 0
0 2 0
0 2 0
*/
