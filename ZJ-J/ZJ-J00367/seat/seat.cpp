#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio();
	int n,m;
	cin>>n>>m;
	int f=n*m,r,ri;
	for(int i=1;i<=f;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	for(int i=1;i<=f;i++)
	{
		for(int j=i+1;j<=f;j++)
		{
			if(a[i]<a[j])
			{
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=1;i<=f;i++)
	{
		if(a[i]==r)
		{
			ri=i;
		}
	}
	if(ri%n!=0)
	{
		cout<<ri/n+1;
	}
	else
	{
		cout<<ri/n;
	}
	cout<<" ";
	if(ri%(2*n)>n)
	{
		if(ri%n==0)
		{
			cout<<1;
		}
		else
		{
			cout<<n+1-ri%n;
		}
	}
	else
	{
		if(ri%n==0)
		{
			cout<<n;
		}
		else
		{
			cout<<ri%n;
		}
	}
	return 0;
}
