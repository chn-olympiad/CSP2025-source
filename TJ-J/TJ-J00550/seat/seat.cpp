#include<bits/stdc++.h>
using namespace std;
long long a[110],b[15][15],flag;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,l,p=0;
	cin>>n>>m;
	cin>>a[1];
	l=a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n*m);
	for(int i=1;i<=m;i++)
	{
		if(flag==0)
		{
			for(int j=1;j<=n;j++,p++)
			{
				b[i][j]=a[n*m-p];
			}
			flag++;
		}
		else
		{
			for(int j=n;j>0;j--,p++)
			{
				b[i][j]=a[n*m-p];
			}
			flag=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(b[i][j]==l)
			{
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
 } 
