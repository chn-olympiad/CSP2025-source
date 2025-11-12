#include <bits/stdc++.h>;
using namespace std;
int n,m,r,rh;
int x(int g)
{
	if(g%n==0)
	{
		return g/n; 
	}
	else
	{
		return g/n+1; 
	}
}
bool f()
{
	if(x(rh)%2==1)
	{
		return true; 
	}
	else
	{
		return false; 
	}
}

int y(int j)
{
	if(j%n==0)
	{
		return n; 
	}
	else
	{
		if(f())
			return j-(x(rh)-1)*n; 
		else
			return n-(rh-(x(rh)-1)*n)+1;
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	cin>>n>>m;
	int s=n*m;
	int a[n*m];
	for(int i=0;i<=s-1;i++)
	{
		cin>>a[i];
	}
	r=a[0];
	rh=1;
	int temp;
	for(int j=0;j<=s;j++)
	{
		for(int k=0;k<=s-2;k++)
		{
			if(a[k]<a[k+1])
			{
				if(a[k]==r)
				{
					rh+=1;
				}
				 else if(a[k+1]==r)
				{
					rh-=1;
				}
				temp=a[k];
				a[k]=a[k+1];
				a[k+1]=temp;
			}
		}
	}
	int c=x(rh),r=y(rh);
	freopen("seat.out","w",stdout);
	cout<<c<<" "<<r;
	return 0; 
}
