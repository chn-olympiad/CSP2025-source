#include<bits/stdc++.h>
//#include<windows.h>
#define LL long long
using namespace std;
struct node
{
	int num;
	bool fl;
}a[110];
bool cmp(node a,node b)
{
	return a.num>b.num;
}
int x=1,y=1,n,m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].num;
		if(i==1)
		{
			a[i].fl=1;
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].fl)
		{
			cout<<y<<" "<<x;
			return 0;
		}
		if(y%2==0)
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
		else
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
	}
	return 0;
}
