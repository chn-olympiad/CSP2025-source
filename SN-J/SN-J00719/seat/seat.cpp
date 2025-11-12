#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	int ri;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			ri=i;
		}
	}
	int x;
	if(ri%m==0)
	{
		x=ri/m;
	}
	else
	{
		x=ri/m+1;
	}
	int y;
	if(x%2==1)
	{
		if(ri%m==0)
		{
			y=m;
		}
		else
		{
			y=ri%m;	
		}
		
	}
	else
	{
		y=m-ri%m;
	}
	cout<<x<<' '<<y;
	return 0;
}
