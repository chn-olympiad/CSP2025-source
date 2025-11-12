#include <iostream>
using namespace std;
int s[100005],c,r,b=0;
int main()
{
	int n,m,x=0,p;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>s[i];
		p++;
	}
	int a1=s[0];
    for(int i=1;i<=p;i++)
	{
		if(s[i]>a1)
		{
			x++;
		}
	}
	int y=x+1;
	if(y<=n)
	{
		
		c=1;
		r=y;
	}
	
	if(y>n)
	{
		int z=y;
		if(y%n==0)
		{
			c=y/n;
		}
		else
		{
			c=(y/n)+1;
		}
		
		while(n<=z)
		{
			
			
			z-=n;
			
			b++;
			
		}
		b++;
		if(b%2==1)
		{
			r=z;
		}
		else
		{
			r=n-(z/n);
		}
	}
	cout<<c<<" "<<r;
	
	
	return 0;
}
