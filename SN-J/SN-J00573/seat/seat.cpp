#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int a1;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	a1=a[1];
	sort(a+1,a+1+n*m,cmp);
	int x=1,y=1;
	int d=1;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==a1)
		{
			cout<<x<<' '<<y;
			return 0;
		}
		if((y==1 && d==-1) || (y==n && d==1))
		{
			if(d==-1)
			{
				d=1;
				x++;
			}
			else if(d==1)
			{
				d=-1;
				x++;
			}
		}
		else
		{
			y+=d;
		}
	}
	return 0;
}

