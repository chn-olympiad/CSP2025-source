#include <bits/stdc++.h>
using namespace std;
int a[105];
int n,m;
int xi=0;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	xi=a[1];
	sort(a+1,a+n*m+1,cmp);
	int f=0;
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		f^=1;
		if(f)
		{
			for(int j=1;j<=n;j++)
			{
				cnt++;
				if(a[cnt]==xi)
				{
					cout<<i<<' '<<j<<'\n';
					return 0;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				cnt++;
				if(a[cnt]==xi)
				{
					cout<<i<<' '<<j<<'\n';
					return 0;
				}
			}
		}
	}
	return 0;
}
