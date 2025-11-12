#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b,c,cnt;
bool cmp(int x,int y)
{
	if(x>y)
		return 1;
	else
		return 0;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cnt=n*m;
	for(int i=1;i<=cnt;i++)
	{
		cin>>a[i];
	}
	b=a[1];//小R的分数 
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		if(a[i]==b)
		{
			c=i;//小R的排名 
		}
	}
	for(int i=1;i<=cnt;i++)
	{
		
		if(c%m==0)
		{
			if(c/m%m==1)
			{
				cout<<c/m<<" ";
				cout<<m;
				return 0;
			}
			else
			{
				cout<<c/m<<" ";
				cout<<1;
				return 0;
			}
		}
		else
		{
			if((c/m+1)%2==1)
			{
				cout<<c/m+1<<" ";
				cout<<c%3;
				return 0;
			}
			else
			{
				cout<<c/m+1<<" ";
				cout<<m-c%m+1;
				return 0;
			}
		}
	}
	return 0;
}
