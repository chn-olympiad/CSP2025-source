#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005],pre[500005],dp[500005];
int pos[1048580],last[1048580],now[1048580];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],pre[i]=-1;
	int xorr=0;
	for(int i=n;i>0;i--){
		xorr^=a[i];
		last[now[xorr]]=i;
		now[xorr]=i;
		if(!pos[xorr]) pos[xorr]=i;
	}
	xorr=k;
	for(int i=n;i>0;i--){
		if(!pos[xorr]){
			xorr^=a[i];
			continue;
		}
		while(pos[xorr]>i)
			pos[xorr]=last[pos[xorr]];
		if(!pos[xorr]){
			xorr^=a[i];
			continue;
		}
		pre[i]=pos[xorr];
		xorr^=a[i];
	}
	dp[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if(pre[i]!=-1) dp[i]=max(dp[i],dp[pre[i]-1]+1);
	}
	cout<<dp[n];
	return 0;
}
