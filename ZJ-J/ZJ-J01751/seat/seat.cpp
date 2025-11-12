#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[105][105],ans;
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]>=a[1][1])
				ans++;
		}
	int x=(ans+n-1)/n;
	cout<<x<<" ";
	if(x&1)
		cout<<ans-x*n+n;
	else
		cout<<x*n-ans+1;
	return 0;
}
