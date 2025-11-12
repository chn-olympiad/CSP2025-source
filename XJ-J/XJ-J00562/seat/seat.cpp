#include<bits/stdc++.h>
using namespace std;
int n,m,xm,s,a[105],mp[15][15];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	xm=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;)
	{
		for(int j=1;j<=n;j++)
		{
			s++;
			if(a[s]==xm)
			{
				cout<<i<<' '<<j;
				return 0;
			}
		}
		i++;
		for(int j=n;j>=1;j--)
		{
			s++;
			if(a[s]==xm)
			{
				cout<<i<<' '<<j;
				return 0;
			}
		}
		i++;
	}
	return 0;
}
