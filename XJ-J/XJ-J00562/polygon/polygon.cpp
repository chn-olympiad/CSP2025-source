#include<bits/stdc++.h>
using namespace std;
int p(int x,int base)
{
	long long s=0;
	while(x>0)
	{
		s+=(x%2)*base;
		x/=2;
		base*=10;
	}
	return s;
}
int n,a[5005],ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=4;i<=pow(2,n);i++)
	{
		int h=0,zd=0,x=i,s;
		for(int j=n;j>=1;j--)
		{
			s=x%2;
			x/=2;
			if(s==1)
			{
				h+=a[j];
				if(zd==0)
					zd=a[j];
			}
		}
		if(zd*2<h)
			ans++;
	}
	cout<<ans;
	return 0;
}
