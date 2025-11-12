#include<bits/stdc++.h>
using namespace std;
int a[106],b[15][15];
int n,m,s;
bool ass(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1,ass);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==s)
		{
			s=i;
			break;
		}
	}
	int ans=0,x=0,y=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			ans++;
			if(ans==s)
			{
				x=i;
				y=j;
				break;
			}
		}
	}
	if(x%2==1)
	{
		cout<<x<<' '<<y;
	}
	else
	{
		cout<<x<<' '<<n-y+1;
	}
	return 0;
}
