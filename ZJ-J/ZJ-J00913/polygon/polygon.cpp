#include<bits/stdc++.h>
using namespace std;
int n;
long long a[5010]= {0},sum[5010]= {0},dp[5010][5010]= {0},c[5010]= {0,1};
long long cc(int x) {
	if(x==0){
		return 0;
	}
	if(c[x]==0) {
		c[x]=cc(x-1)*2+1;
	}
	return c[x];
}
long long dfs(int l,int r,int x,int mmax){
	long long res=0;
	if(x+a[r]>mmax*2) {
		return cc(r-l+1);
	} else {
		for(int i=l;i<=r;i++){
			res=max(res,dfs(l,i-1,x+a[i],mmax)+dfs(i+1,r,x+a[i],mmax));
		}
		return res;
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) {
		sum[i]=a[i]+sum[i-1];
	}
	for(int i=3; i<=n; i++) {
		for(int l=1,r=l+i-1; r<=n; l++,r++) {
			for(int j=l; j<r; j++) {
				dp[l][r]=max(dp[l][r],dp[l][j]+dp[j+1][r]);
			}

			dp[l][r]+=dfs(l+1,r-1,a[l]+a[r],a[r]);
			
		}
	}
	cout<<dp[1][n];
	return 0;
}
