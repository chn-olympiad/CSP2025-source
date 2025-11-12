#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int a[110],b[20][20];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	int k;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		k=a[1];
	}
	sort(a+1,a+n*m+1,cmp);
	if(m%2==0)
	{
		int p=1,ans=1;
		while(p<=m){
		
			for(int i=1;i<=n;i++)
			{
				b[i][p]=a[ans];
				ans++;
			}
			p++;
			for(int i=n;i>=1;i--)
			{
				b[i][p]=a[ans];
				ans++;
			}
			p++;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(b[i][j]==k)
				{
					cout <<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	else
	{
		int p=1,ans=1;
		while(p<m)
		{
			for(int i=1;i<=n;i++)
			{
				b[i][p]=a[ans];
				ans++;
			}
			p++;
			for(int i=n;i>=1;i--)
			{
				b[i][p]=a[ans];
				ans++;
			}
			if(p==m-1)
			{
				break;
			}
			p++;
		}
		for(int i=1;i<=n;i++)
		{
			b[i][m]=a[ans];
			ans++;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(k==b[i][j])
				{
					cout <<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	return 0;
}
