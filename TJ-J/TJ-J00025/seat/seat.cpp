#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
long long n,m,xr,pm,h,l;
long long a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int len=n*m;
	for(int i=1;i<=len;i++)
	{
		cin>>a[i];
	}
	xr=a[1];
	sort(a+1,a+len+1,cmp);
	for(int i=1;i<=len;i++)
	{
		if(a[i]==xr)
		{
			pm=i;
			break;
		}
	}
	if(pm%n!=0)
	{
		l=pm/n+1;
	}
	else
	{
		l=pm/n;
	}
	if(l%2==0)
	{
		if(pm%n==0)
		{
			h=1;
		}
		else
		{
			h=n-pm%n+1;
		}
	}
	else
	{
		if(pm%n==0)
		{
			h=n;
		}
		else
		{
			h=pm%n;
		}
	}
	cout<<l<<" "<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

