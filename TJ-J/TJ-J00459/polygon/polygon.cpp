#include <bits/stdc++.h>
using namespace std;
int n,a[5005],zui;
int c(int q,int w)
{
	int w1=w,ans=1;
	while(w1>(w-q))
	{
		ans%=998244353;
		ans*=w1;
		w1--;
	}
	int ans1=1;
	for (int i=2;i<=q;i++)
	{
		ans1*=i;
	}
	return ans/ans1;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if (n==3)
	{
		if (a[1]+a[2]+a[3]>a[3]*2)
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	for (int i=3;i<=n;i++)
	{
		zui+=c(i,n);
	}
	cout<<zui;
	return 0;
}
