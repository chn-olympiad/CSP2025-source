#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int T,a[N][4],n;
int ans;
bool f=1,l=1;
int A[N];
void dfs(int x,int cnt,int cnt2,int cnt3,int sum) {
	if(cnt2>n/2||cnt>n/2||cnt3>n/2||n>20) {
		return ;
	}
	if(x==n+1) {
		ans=max(ans,sum);
		return ;
	}
	dfs(x+1,cnt+1,cnt2,cnt3,sum+a[x][1]);
	dfs(x+1,cnt,cnt2+1,cnt3,sum+a[x][2]);
	dfs(x+1,cnt,cnt2,cnt3+1,sum+a[x][3]);
}
int dp[3][N];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		f=1;
		ans=0;
		memset(dp,0,sizeof dp);
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=3; j++) {
				cin>>a[i][j];
			}
			if(a[i][2]!=a[i][3]&&a[i][2]!=0) {
				f=0;
			}
		}
		if(n<=30) {
			dfs(1,0,0,0,0);
			cout<<ans<<"\n";
		} else if(f==1) {
			for(int i=1; i<=n; i++) {
				A[i]=a[i][1];
			}
			sort(A+1,A+1+n);
			for(int i=n; i>n/2; i--) {
				ans+=A[i];
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
