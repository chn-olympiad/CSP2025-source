#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int a[105];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1;
	bool shun=true;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			cout<<y<<" "<<x;
			break;
		}
		else if(shun)	x++;
		else x--;
		if(x==n+1)
		{
			x=n;
			shun=!shun;
			y++;
		}
		else if(x==0)
		{
			x=1;
			shun=!shun;
			y++;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}