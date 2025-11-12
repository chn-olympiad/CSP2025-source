#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5500;
const int mod=998244353;
int a[N],dp[N];
int cnt,maxn,sum,ans;
int n,m,x;
void dfs(int x,int sum,int maxnn){
	if(x==n+1){
		if(sum>maxnn*2)
		  cnt++;
		return;
	}
	int y=max(maxnn,a[x]);
	dfs(x+1,sum+a[x],y);
	dfs(x+1,sum,maxnn);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(maxn==1){
		for(int i=1;i<=n;i++){
			int sum1=1,sum2=1;
			for(int j=n;j>=n-i;j--){
				sum1*=j;
				sum1%=mod;
			}
			for(int j=1;j<=i+1;j++){
				sum2*=j;
				sum2%=mod;
			}
			sum=sum+sum1/sum2;
		}
		cout<<sum<<"\n";
		return 0;
	}
	dfs(1,0,0);
	cout<<cnt<<"\n";
	return 0;
}
/*

*/
