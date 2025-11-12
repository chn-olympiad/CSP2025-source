#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	int n,m,i,j,l,num,s;
	cin>>n>>m;
	cin>>l;
	a[1]=l;
	for(i=1;i<n*m;i++)
	{
		cin>>a[i+1];
	}
	for(i=1;i<=n*m;i++)
	{
		for(j=1;j<=n*m;j++)
		{
			int t;
			if(a[j]<a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	for(i=1;i<=n*m;i++)
	{
		if(a[i]==l)
		{
			s=i;
			break;
		}
	}
	int x=1,y=1;
	for(i=1;i<s;i++)
	{
		if(x%2!=0)
		{
			y++;
		}
		else
		{
			y--;
		}
		if(y>n)
		{
			x++;
			y=n;
		}
		if(y<1)
		{
			x++;
			y=1;
		}
	}
	cout<<x<<" "<<y;
	return 0;
} 
