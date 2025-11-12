//SN-J00797 王者淳 西安辅轮中学
#include<bits/stdc++.h>
using namespace std;
int n,a[500001],k,x[500001],h[500001],dp[500001][2];
map<int,int>m;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x[i]=x[i-1]^a[i];
		int q=k^x[i];
		if(m[q]!=0||q==0)h[i]=m[q];
		else h[i]=-1;
		m[x[i]]=i;
	}
	for(int i=1;i<=n;i++){
		dp[i][0]=dp[i-1][0];
		dp[i][1]=dp[i-1][1];
		if(h[i]!=-1&&dp[i-1][1]<=h[i])
		dp[i][0]++,dp[i][1]=i;
	}
	cout<<dp[n][0];
	return 0;
}
