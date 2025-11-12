#include<bits/stdc++.h>
using namespace std;
int a[20][20],b[110];
int cmp(int x,int y)
{
	return x>y;
}
int main ()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
long long n,m,q=0,x;
cin>>n>>m;
for(int i=1;i<=m*n;i++)
{
	cin>>b[i];
}
x=b[1];
sort(b+1,b+n*m+1,cmp);
for(int i=1;i<=n;i++)
{
	if(i%2==1)
	{
		for(int j=1;j<=m;j++)
		{
		q++;
		a[i][j]=b[q];
			if(a[i][j]==x)
			{
			cout<<i<<" "<<j;
		}

	}
	}
	else if(i%2==0)
	{
		for(int j=m;j>=1;j--)
		{
			q++;
		a[i][j]=b[q];
		if(a[i][j]==x)
			{
			cout<<i<<" "<<j;
			}
		}
	}
}

	return 0;
}