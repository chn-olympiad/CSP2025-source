#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int n,m;
int a[1005];
int x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=(n*m);i++)
	{
		cin>>a[i];
	}
	int R = a[1];
	sort(a+1,a+(n*m)+1,cmp); 
	x=1,y=1;
	int now = 0;
	while(x<=n) 
	{
		now++;
		if(a[now] == R)
		{
			cout<<x<<" "<<y;
			return 0;
		}
		if((y==m&&x%2!=0) || (y==1&&x%2==0))
		{
			x++;
			now++;
			if(a[now] == R)
			{
				cout<<x<<" "<<y;
				return 0;
			}
		}
		if(x%2 != 0) y++;
		else y--;
	}	
	return 0;
}
