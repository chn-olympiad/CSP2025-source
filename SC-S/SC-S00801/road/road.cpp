#include<bits/stdc++.h>
#define int long long
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define dow(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
const int N=500,p=998244353;
int n,m,k;
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int ans=0;
	rep(i,1,m)
	{
		int j;
		cin>>j;
		cin>>j;
		cin>>j;
		ans+=j;
	}
	cout<<ans;
	return 0;
}