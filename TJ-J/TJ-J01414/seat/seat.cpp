#include <bits/stdc++.h>
using namespace std;
int a[15][15],b[500];
bool cmp(int b1,int b2)
{
	return b1>b2;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>b[i];
	}
	int c=b[0];
	sort(b,b+n*m,cmp);
	int flag=0;
	for(int i=1;i<=m;i++)
	{
		if(i%2!=0)
		{
			for(int j=1;j<=n;j++)
			{
				a[j][i]=b[flag];
				flag++;
				if(a[j][i]==c)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				a[j][i]=b[flag];
				flag++;
				if(a[j][i]==c)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
 } 
