#include<iostream>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin); 
	freopen("seat.out","w",stdout);
	int n,m,i,j,k,l,s,x,y;
	int a[105]={0};
	cin>>n>>m;
	l=n*m;
	for(i=1;i<=l;i++)
	{
		cin>>a[i];
	}
	s=1;
	for(i=2;i<=l;i++)
	{
		if(a[i]>a[1])
		{
			s++;
		}
	}
	if(s%n==0)
	{
		x=s/n;
	}
	else
	{
		x=s/n+1;
	}
	if(x%2==0)
	{
		if(s%n==0)
		{
			y=1;
		}
		else
		{
			y=n-s%n+1;
		}
		
	}
	else
	{
		if(s%n==0)
		{
			y=n;
		}
		else
		{
			y=s%n;
		}
	}
	cout<<x<<' '<<y;
	return 0;
}
