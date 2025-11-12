#include<iostream>
using namespace std;
int main()
{
	int n,m,i,c[1005],t,j,x=1,y=1,t2;
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>c[i];
	}
	for(i=1;i<=n*m;i++)
	{
		t=0;
		for(j=1;j<=n*m;j++)
		{
			if(t<c[j])
			{
				t=c[j];
				t2=j;
			}
		}
		if(t!=c[1])
		{
			if(x%2==1&&y+1<=n)
			{
				y++;
			}
			else if(x%2==0&&y-1>=1)
			{
				y--;
			}
			else if(y+1>n||y-1<1)
			{
				x++;
			}
		}
		else if(t==c[1])
		{
			cout<<x<<" "<<y;
			return 0;
		}
		c[t2]=-1;
	}
	return 0;
}
