#include<bits/stdc++.h>
using namespace std;

int a[300];
bool node(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,at,on=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	at=a[1];
	sort(a+1,a+1+n*m,node);
	int x=1,y=1,add=1;
	for(int i=1;i<=m;i++)
	{
		x=i;
		if(i%2==0)y=n,add=-1;
		else y=1,add=1;
		for(int j=1;j<=n;j++)
		{
			on++;
			if(a[on]==at)
			{
				cout<<y<<" "<<x;
				return 0;
			}
			else
			{
				y+=add;
				
			}
		}
	}
}