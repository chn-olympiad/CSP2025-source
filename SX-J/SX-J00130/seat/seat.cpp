#include<bits/stdc++.h>
using namespace std;
int a[110],b[20][20];
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,k,w=0,h;
	cin>>n>>m;
	k=n*m;
	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
	}
	h=a[1];
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				w++;
				b[i][j]=a[w];
			}

		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				w++;
				b[i][j]=a[w];
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(b[i][j]==h)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}




	return 0;
}