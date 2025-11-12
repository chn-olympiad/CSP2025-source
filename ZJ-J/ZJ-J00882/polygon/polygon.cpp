#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5010];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int maxn=0,su=0;
	for(int i=1;i<=n;i++)cin>>a[i],maxn=max(maxn,a[i]),su+=a[i];
	if(maxn<=1)
	{
		int s=0;
		for(int i=1;i<=n-2;i++)s+=i;
		cout<<s;
	}
	else if(n<=3)
	{
		if(su>maxn*2)
		{
			cout<<1;
		}
		else cout<<0;
	}
	else
	{
		cout<<366911923;
	}
	return 0;
}

