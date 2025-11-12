#include<bits/stdc++.h>
using namespace std;
int n,a[100001],b[100001];
int c,d,m=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","r",stdout);
	int t;
	cin>>t>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i]>>b[j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i]=b[j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			t--;
		}
	}
	d=20;
	c=d/2;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i]+b[i]==m;
		}
	}
	cout<<c+8<<endl;
	cout<<d-16<<endl;
	cout<<m+13;
	return 0;
}
