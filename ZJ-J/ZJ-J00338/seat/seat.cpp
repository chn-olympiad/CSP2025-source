#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+n+1,cmp);
	int cnt=0;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==x)
		{
			cnt=i;
		}
	}
	int a=cnt/n,b=cnt%n;
	if(b==0)
	{
		if(a%2==0)
		{
			cout<<a<<" "<<1;
		}
		else
		{
			cout<<a<<" "<<n;
		}
	}
	else
	{
		if(a%2==0)
		{
			cout<<a+1<<" "<<b;
		}
		else
		{
			cout<<a+1<<" "<<n-b+1;
		}
	}
}