#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m,c[505];
string s;
int ans=0;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	  scanf("%d",c+i);
	for(int i=m;i<=n;i++)
	{
		int t=1;
		for(int j=i;j<=n;j++)
	      t=(t*(j%mod))%mod;
	    ans=(ans+t)%mod;
	}
	cout<<ans;
	return 0;
}
