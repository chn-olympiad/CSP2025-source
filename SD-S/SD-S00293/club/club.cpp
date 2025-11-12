#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,a[100005][6],ans=0,bj=0,b[100005];
void dfs(int k,int m,int aa,int bb,int cc) {
	if(k==n+1) {
		if(aa<=n/2&&bb<=n/2&&cc<n/2)
			ans=max(ans,m);
		return;
	}
	dfs(k+1,m+a[k][1],aa+1,bb,cc);
	dfs(k+1,m+a[k][2],aa,bb+1,cc);
	dfs(k+1,m+a[k][3],aa,bb,cc+1);
}
int main() {
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=3; j++) {
				cin>>a[i][j];
				if(j==1)b[i]=-a[i][j];
				if(j>=2&&a[i][j]!=0)bj=1;
			}
		}
		ans=0;
		if(bj==0) {
			sort(b+1,b+1+n);
			for(int i=1; i<=n/2; i++) {
				b[i]*=-1;
				ans+=b[i];
			}
			cout<<ans<<'\n';
			continue;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}

