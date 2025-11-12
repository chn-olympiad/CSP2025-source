//SN-J01113 陈梓言 曲江第一学校 
#include<bits/stdc++.h>
using namespace std;
int n,m;
int seat[12][12];
int a[105];
int sor[105];
int r;
int main()
{
	freopen("seat.in","r","stdin");
	freopen("seat.out","w","stdout");
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a,a+n*m+1);
	for (int i=m,v=1;i>=1;i--)
	{
		if(i&1)
		{
			for (int j=n;j>=1;j--)
			{
				seat[i][j]=a[v];
				if(a[v]==r)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				v++;
			}
		}
		else
		{
			for (int j=1;j<=n;j++)
			{
				seat[i][j]=a[v];
				if(a[v]==r)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				v++;
			}
		}
	}
}

