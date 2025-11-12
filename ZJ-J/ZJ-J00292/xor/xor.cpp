#include<bits/stdc++.h>
using namespace std;
#define int long long
 int n,m,mxx=0;
 int a[500010],sm[500010],dp[500010];
 int mx[500010],t[2500010];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sm[i]=(sm[i-1]^a[i]);
	}
	memset(t,-1,sizeof t);
	t[0]=0;
	for(int i=1;i<=n;i++){
		int x=(m^sm[i]);
		if(t[x]!=-1)dp[i]=mx[t[x]]+1;
		mx[i]=max(mx[i-1],dp[i]);
		t[sm[i]]=i;
		mxx=max(mxx,dp[i]);
	}
	cout<<mxx;
	return 0;
}
