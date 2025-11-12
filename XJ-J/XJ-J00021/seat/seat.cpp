#include<iostream>
using namespace std;
int main()
{
	frepen("seat.in","r",stdin);
	frepen("seat.out","w",stdout);
	int n,m,j,i,a,x=0,t;
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
			cin>>a;
			if(i==1)
			{
				t=a;
			}
			if(a>t)
			{
				x++;
			}
	}
	for(j=1;j<=m;j++)
	{
		for(i=1;i<=n;i++)
		{
			if(x==0)
			{
				cout<<j<<" "<<i;
			}
			x--;
		}
	}
	return 0;
} 
