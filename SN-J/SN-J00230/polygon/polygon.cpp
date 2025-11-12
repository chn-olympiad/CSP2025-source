#include<bits/stdc++.h>
using namespace std;
int n,a[100005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3)
	{
		int maxn=0,sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			maxn=max(maxn,a[i]);
			sum+=a[i];
		}
		if(maxn*2<sum)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		cout<<0;
	}
}
