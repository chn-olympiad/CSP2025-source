#include<iostream>
#include<cstdio>
using namespace std;
int h[500005];
int xh[500005];
int dp[500005];//begin the i max is dp[i]
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>h[i];
		xh[i]=xh[i-1]^h[i];
		//cout<<xh[i]<<' ';
	}
	/*
	cout<<endl;
	for(int l=1;l<=n;++l){
		for(int r=l;r<=n;++r)
			cout<<(xh[r]^xh[l-1])<<' ';
		cout<<endl;
	}	
	*/
	for(int l=n;l>0;--l){
		for(int r=l;r<=n;++r)
			if((xh[r]^xh[l-1])==k)
				dp[l]=max(dp[l],dp[r+1]+1);
			else
				dp[l]=max(dp[l],dp[r+1]);
		//cout<<"dp "<<l<<" :"<<dp[l]<<endl;
	}
	int maxx=0;
	for(int i=1;i<=n;++i)
		maxx=max(maxx,dp[i]);
	cout<<maxx;
	return 0;
}
/*
4 0
2 1 0 3
*/
