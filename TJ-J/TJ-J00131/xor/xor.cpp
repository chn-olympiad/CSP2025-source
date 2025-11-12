#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],c[1100005],dp[500005][2];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	int V=pow(2,20);
	for(int i=1;i<V;i++){
		c[i]=-1;
	}
	for(int i=1;i<=n;i++){
		if(c[b[i]^k]!=-1){
			dp[i][1]=max(dp[c[b[i]^k]][0],dp[c[b[i]^k]][1])+1;
		}
		dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
		c[b[i]]=i;
	}
	cout<<max(dp[n][1],dp[n][0]);
	return 0;
}
