#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int r=a[1],cnt=0,k=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2==0)
		{
			for(int j=n;j>=1;j--)
			{
				if(a[++k]==r)
				{
					cout<<j<<" "<<i;
					return 0;
				}
				cnt++;
			}
		}
		else
		{
			for(int j=1;j<=n;j++)
			{
				if(a[++k]==r)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
			cnt++;
		}
	}
	return 0;
}
