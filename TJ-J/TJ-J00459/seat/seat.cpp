#include <bits/stdc++.h>
using namespace std;
int a[105],n,m;
int cmp(int a,int b)
{
	if (a>=b)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int zong=n*m;
	for (int i=1;i<=zong;i++)
	{
		cin>>a[i];
	}
	int rscore=a[1];
	sort(a+1,a+1+zong,cmp);
	int rpai=0;
	for (int i=1;i<=zong;i++)
	{
		if (a[i]==rscore)
		{
			rpai=i;
			break;
		}
	}
	int c=0,r=0;
	if ((rpai%n)!=0)
	{
		c=rpai/n+1;
		if (c%2==0)
		{
			r=n-(rpai%n)+1;
		}
		else
		{
			r=rpai%n;
		}
	}
	else
	{
		c=rpai/n;
		if (c%2==0)
		{
			r=1;
		}
		else
		{
			r=n;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}

