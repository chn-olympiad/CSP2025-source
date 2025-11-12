#include<bits/stdc++.h>
using namespace std;
long long a[100005][5];
long long b[5];
long long t,n,ans=-1e9;
void dfs(long long p,long long sum) {
	if(p==n) {
		ans=max(ans,sum);
		return ;
	}
	for(long long i=1; i<=3; i++) {
		if((b[i]+1)<=(n/2)) {
			b[i]++;
			dfs(p+1,sum+a[p+1][i]);
			b[i]--;
		}
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(long long l=1; l<=t; l++) {
		cin>>n;
		for(long long i=1; i<=n; i++) {
			for(long long j=1; j<=3; j++) {
				cin>>a[i][j];
			}
		}
		dfs(0,0);
		cout<<ans;
		if(l!=t) {
			cout<<"\n";
		}
		ans=-1e9;
		for(long long i=1; i<=3; i++) {
			b[i]=0;
		}
	}
	return 0;
}