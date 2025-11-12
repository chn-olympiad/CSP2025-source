#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m,n,a,c,r,b,x,cj[10000];
	cin>>m;
	cin>>n;
	for(int i=1;i<=m*n;i++)
	{
		cin>>cj[i];
	}
	b=cj[1];
	for(int j=1;j<=n*m;j++)
	{
		for(int i=1;i<=n*m;i++)
		{
			if(cj[i]<=cj[i+1])
			{
				a=cj[i+1];
				cj[i+1]=cj[i];
				cj[i]=a;
			}	
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		cout<<cj[i]<<" ";
		if(cj[i]==b)
		{
			x=i;
			cout<<i<<endl;
			break;
		}
	}
	if(x%n==0)
	{
		c=x/n;
	}
	else
	{
		c=x/n+1;
	}
	if(c%2==0)
	{
		r=n-x%n+1;
	}
	if(c%2!=0)
	{
		r=x%n;
	}
	cout<<c<<" "<<r;
}

