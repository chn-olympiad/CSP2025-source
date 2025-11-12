#include<bits/stdc++.h>
using namespace std;

struct point
{
	int x;
	int y;
};
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,a[10005];
	map<int,point> ma;
	cin >> n >> m;
	for(int i=1;i<=m;i+=2)
	{
		for(int j=1;j<=n;j++)
		{
			int num=(i-1)*n+j;
			ma[num]={i,j};
		}
	}
	for(int i=2;i<=m;i+=2)
	{
		for(int j=1;j<=n;j++)
		{
			int num=i*n-j+1;
			ma[num]={i,j};
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		cin >> a[i];
	}
	int sc=a[1],tp;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==sc)
		{
			tp=i;
			break;
		}
	}
	point p=ma[tp];
	cout << p.x << ' ' << p.y;
	return 0;
}