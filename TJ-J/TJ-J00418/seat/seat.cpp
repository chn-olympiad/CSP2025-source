#include<bits/stdc++.h>
using namespace std;

int n,m,a[1008],num;
bool cmp(int a,int b)
{
	return a>b;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	num=a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1,flag=1;;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==num)
		{
			cout<<y<<" "<<x;
			break;
		}
		if(flag)
		{
			x++;
			if(x==n+1)
			{
				x=n;
				y++;
				flag=0;
			}
		}
		else
		{
			x--;
			if(x==0)
			{
				x=1;
				y++;
				flag=1;
			}
		}
	}
	return 0;
}
