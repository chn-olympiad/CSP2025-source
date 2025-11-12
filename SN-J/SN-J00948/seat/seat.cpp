//SN-J00948 蔡铭禹 西安高新第一中学 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[110];

bool cmp(int x,int y)
{
	return x>y;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int tp=a[1];
	sort(a+1,a+1+n*m,cmp);
	int x=1,y=1,tot=1;
	while(x<=n && y<=m)
	{
		if(a[tot]==tp)
		{
			cout<<y<<' '<<x;
			return 0;
		}
		tot++;
		if(y%2==1)
		{
			if(x==n)
			{
				y++;
			}
			else
			{
				x++;
			}
		}
		else
		{
			if(x==1)
			{
				y++;
			}
			else
			{
				x--;
			}
		}
	}
	return 0;
}
