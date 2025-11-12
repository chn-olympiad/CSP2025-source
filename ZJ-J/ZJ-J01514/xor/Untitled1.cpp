#include<bits/stdc++.h>
using namespace std;
#define int long long
const int _=5*1e5+10;
int n,k,a[_],f[_],dp[_],l,r,s,mid,x,i,j;
vector<int> b[1050000];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	b[0].push_back(0);
	for(i=1;i<=n;i++){
		cin>>a[i],
		f[i]=(f[i-1] xor a[i]);
		b[f[i]].push_back(i);
	}
	for(i=1;i<=n;i++){
		x=(f[i] xor k);
//		cout<<x<<" ";
		int y=lower_bound(b[x].begin(),b[x].end(),i)
		  -b[x].begin()-1;
		if(y>b[x].size()||y<0) dp[i]=dp[i-1];
		else dp[i]=max(dp[i-1],dp[b[x][y]]+1);
	}
	cout<<dp[n];
}