#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],xx;
void dfs(int x,int y,int num)
{
	if(num==xx) 
	{
		cout<<x<<" "<<y;
		return;
	}
	if(x%2==0&&y==1||x%2==1&&y==m)
	{
		dfs(x+1,y,num+1);
		return;
	}
	if(x%2==0)
	{
		dfs(x,y-1,num+1);
		return;		
	}
	if(x%2==1)
	{
		dfs(x,y+1,num+1);
		return;		
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	swap(n,m);
	for(int i=1;i<=n*m;i++) cin>>a[i];
	xx=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(xx==a[i])
		{
			xx=n*m-i+1;
			dfs(1,1,1);
			return 0;
		}
	}
	return 0;
}
