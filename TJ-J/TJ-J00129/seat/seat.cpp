#include<bits/stdc++.h>
using namespace std;
long long n,m,a[15][15],k;
long long  flag;

int main()
{
	
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(i==1&&j==1)
			{
				k=a[i][j];
			}
			if(a[i][j]>=k)
			{
				flag++;
			}
		}
	}
	int lie;
	if(flag%n!=0)
	{
		cout<<(flag/n)+1;
		lie=(flag/n)+1;
	}
	else
	{
		cout<<flag/n;
		lie=flag/n;
	}
	cout<<" ";
	if(lie%2==0)
	{
		if(flag%n!=0)
		{
			cout<<n-(flag%n)+1;
		}
		else
		{
			cout<<1;
		}
	}
	else
	{
		if(flag%n!=0)
		{
			cout<<(flag%n);
		}
		else
		{
			cout<<n;
		}
		
	}
	return 0;
 } 
 //do gei dian fen ba!!!
