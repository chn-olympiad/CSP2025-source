#include<bits/stdc++.h>
using namespace std;
#define int long long
int maxn,ans;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[105];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(a[i],maxn);
		ans+=a[i];
	}
	if(maxn*2<ans)
	{
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}

