#include <bits/stdc++.h>
using namespace std;
#define int long long
int feiyong[1000010];
long long ans;
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,k,w1,w2;
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
	{
		cin>>w1>>w2>>feiyong[i];
		if(abs(w1-w2)>=n/2)
			ans+=feiyong[i];
	}
	cout<<ans;
	return 0;
}
