#include<bits/stdc++.h>
using namespace std;
int m,n,a[105],ch,r,jl;
int main()
{
  	freopen("seat.in","r",stdin);
  	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	for(int i=2;i<=m*n;i++)
	{
		for(int j=2;j<=m*n;j++)
		{
			if(a[j]>a[j-1])
			{
				ch=a[j];
				a[j]=a[j-1];
				a[j-1]=ch;
			}
		}
	}
	for(int i=1;i<=m*n;i++)	
	{
		if(a[i]==r)
		{
			jl=i;
			
		}
	}
	if((jl/n)==0&&jl!=n)
	{
		cout<<1<<' '<<jl;
	} 
	else if((jl/n)%2==1)
	{
		if(jl%n==0)
		{
			cout<<jl/n<<' '<<n;
		}
		else 
		{
			cout<<jl/n+1<<' '<<n-jl%n+1;
		}
	}
	else if((jl/n)%2==0)
	{
		if(jl%n==0)
		{
			cout<<jl/n<<' '<<1;
		}
		else 
		{
			cout<<jl/n+1<<' '<<jl%n;
		}
	}
	
	return 0;
}
