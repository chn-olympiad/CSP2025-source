#include<bits/stdc++.h>
using namespace std;
int a[10001];
int b[109][109];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>m>>n;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int p=a[1];
	sort(a+1,a+n*m+1,cmp);
	int c=0,r=0;
	for(int i=1;i<=n;i++)
	{
		if(i%2==0)
		{
			int k=i*m-m+1;
			for(int j=m;j>=1;j--)
			{
				b[j][i]=a[k];
				k++;
			}
		}
		else
		{
			int k=i*m-m+1;
			for(int j=1;j<=m;j++)
			{
				b[j][i]=a[k];
				k++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(b[i][j]==p)
			{
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
