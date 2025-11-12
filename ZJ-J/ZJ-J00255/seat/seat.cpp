#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int a[1005],R,n,m;
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
	{
		cin>>a[i];
	}
	R=a[1];
	int p=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==R)
		{
			p=i;
			break;
		}
	}
	int st=0;
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=m;j++)
			{
				st++;
				if(st==p)
				{
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}
		else
		{
			for(int j=m;j>=1;j--)
			{
				st++;
				if(st==p)
				{
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
}