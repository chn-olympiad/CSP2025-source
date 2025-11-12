//SN-J01129 陶泽玉 安康市高新中学 
#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],mn[15][15],id;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int q=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==q)
		{
			id=i;
			break;
		}
	}
	int sum=0;
	for(int j=1;j<=m;j++)
	{
		if(j%2==1)
		{
			for(int i=1;i<=n;i++)
			{
				sum++;
				if(sum==id)
				{
					cout<<j<<" "<<i;
				}
			}
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				sum++;
				if(sum==id)
				{
					cout<<j<<" "<<i;
				}
			}
		}
	}
	
	return 0;
} 
