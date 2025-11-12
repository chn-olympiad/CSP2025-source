#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],x,q=1,t[25][25];
bool flag=0;
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	frepen("seat.in","r",stdin);
	frepen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=m;j++)
			{
				t[i][j]=a[q];
				if(a[q]==x)
				{
					cout<<i<<" "<<j;
					flag=1;
					break;
				}
				q++;
			}
		}
		else
		{
			for(int j=m;j>=1;j--)
			{
				t[i][j]=a[q];
				if(a[q]==x)
				{
					cout<<i<<" "<<j;
					flag=1;
					break;
				}
				q++;
			}
		}
		if(flag==1)
		{
			break;
		}
	}
	return 0;
}
