#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int b,c,d;
	int a[5001];
	cin>>n;
	int maxx=0;
	if(n==3)
	{
		cin>>b>>c>>d;
		maxx=max(b,d);
		maxx=max(maxx,c);
		if(d+b+c>2*maxx)
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
	else
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			max(maxx,a[i]);
		}
		int cf=0;
		int df=1;
		for(int i=1;i<=n-2;i++)
		{
			for(int j=i;j<=n-3;j++)
			{
				df*=3;
			}
			cf+=df;
			df=1;
		}
		cout<<cf;
	}
	cout<<8;
	return 0;
}
