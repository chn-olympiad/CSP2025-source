#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005]={};
int x[500005]={};			//每一个下标对应最近的这个数字的位置 
int qzh[2000000]={};		
int dp[500005]={};
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		qzh[i]=a[i]^qzh[i-1];
	}
	for(int i=0;i<=500000;i++){
		x[i]=-1;
		dp[i]=0;
	}
	x[0]=0;
	for(int i=1;i<=n;i++){
		int fnum=qzh[i]^k;
		if(x[fnum]!=-1){
			dp[i]=dp[x[fnum]]+1;
//			cout<<x[fnum]+1<<"~"<<i<<endl;
		}
		dp[i]=max(dp[i],dp[i-1]);
		x[qzh[i]]=i;
	}
	cout<<dp[n]<<endl;
	return 0;
}
