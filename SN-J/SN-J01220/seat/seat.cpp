//SN-J01220 龚西贝 西安建筑科技大学附属中学
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt=1,num;
	cin>>n>>m;//n行 m列 
	cin>>num;
	int x;
	for(int i=0;i<n*m-1;i++)
	{
		cin>>x;
		if(x>num)
		{
			cnt++;
		}
	}
	int c,r;
	if(cnt%n==0)
	{
		c=cnt/n;
	}
	else
	{
		c=cnt/n+1;
	}
	if(c%2==1)
	{
		if(cnt%n!=0)
		{
			r=cnt%n;
		}
		else
		{
			r=n;
		}
	}
	else if(c%2==0)
	{
		r=n-cnt%n+1;
	}
	cout<<c<<' '<<r;
	return 0;
}
