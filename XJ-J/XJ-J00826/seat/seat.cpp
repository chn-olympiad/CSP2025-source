#include <iostream>
using namespace std;
int a[1000000],n,m,s,l,c,r,sum,o[100];
int c,r;
int main()
{
	//freopen("seat","r",stdin);
	//freopen("seat","w",stdout);
	cin>>n;
	cin>>m;
	s=n*m;
	for(int i=1;i<=s;i++)
	{
		cin>>a[i];
	}
	for(int i=2;i<=s;i++)
	{
		if(a[i]>=a[i-1])
		{
			o[0]=a[i-1];
			a[i]=a[i-1];
			o[0]=a[i];
		}
	}
	for(int i=0;i<=s;i++)
	{
		if(a[0]>a[i])
		{
			o[0]=a[i];
			a[0]=a[i];
			o[0]=a[0];
			break;
		}
		sum++;
	}
	for(int i=0;i<=s;i++)
	{
		if(a[i]>a[i-1])
		{
			o[0]=a[i-1];
			a[i]=a[i-1];
			o[0]=a[i];
		}
	}
	if(sum%m==0)
	{
		c=sum/m;
	}
	else
	{
		c=sum/m+1;
	}
	if(k==0)
	{
		c=1;
	}
	r=sum%m;
	if(r==0)
	{
		r=4;
	}
	cout<<c<<" "<<r;
}
