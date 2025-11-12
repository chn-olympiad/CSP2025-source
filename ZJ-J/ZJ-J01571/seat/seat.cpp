#include<bits/stdc++.h>
using namespace std;
int a[200];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a[1];
	int num=0;
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])num++;
	}
	int x=1,y=1,f=0;
	num=num-1;
	if(num==-1)
	{
		cout<<1<<" "<<1<<endl;
		return 0;
	}
	while(1)
	{
		num--;
		if(y==n&&f==0)x++,f=1;
		else if(y==1&&f==1)x++,f=0;
		else
		{
			if(f==0)y++;
			else y--;
		}
		if(num==-1)
		{
			cout<<x<<" "<<y;
			return 0;
		}
	}
	return 0;
}
