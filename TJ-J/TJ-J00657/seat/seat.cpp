#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m;
	int d;
	cin >> n >> m;
	int s[m];
	int sum =0;
	int a[n][m];
	for(int i=0;i<=n*m-1;i++)
	{
		cin >> s[i];
	}
	int c=s[0];
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<=n*m;j++)
		{
			if(s[j-1] < s[j])
			{
				sum=s[j];
				s[j]=s[j-1];
				s[j-1]=sum;
			}
		}
	}
	for(int i=0;i<=n*m-1;i++)
	{
		if(s[i] == c)
		{
			d=i;
		}
	}
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(d<n)
			{
				cout << 1 << " " << d+1;
				return 0;
			}
			else
			{
				cout << 3/n+1 << " " << 3%n;
				return 0;
				if(m%2==0)
				{
					cout << 3/n+1 << " " << 3%n;
				}
				if(m%2==1)
				{
					cout << 3/n+1 << " " << m-3%n+1;
				}
			}
		}
	}
	
	//cout <<  << " " << j;
	
	return 0;
}
