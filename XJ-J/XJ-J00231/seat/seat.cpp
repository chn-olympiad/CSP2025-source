#include<bits/stdc++.h>
using namespace std;
int n,m,R,t,s=0,x=1,y=1,f=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>R;
	for(int i=2;i<=n*m;i++)
	{
		cin>>t;
		if(t>R)
		{
			s++;
		}
	}
	while(s--)
	{
		if(f==1)
		{
			x++;
		}
		if(f==0)
		{
			x--;
		}
		if(f==2)
		{
			y++;
			if(x==n)
			{
				f=0;
			}
			if(x==1)
			{
				f=1;
			}
		}
		else
		{
			if(x==n)
			{
				f=2;
			}
			if(x==1)
			{
				f=2;
			}	
		}
	}
	cout<<y<<" "<<x;
	return 0;
}
