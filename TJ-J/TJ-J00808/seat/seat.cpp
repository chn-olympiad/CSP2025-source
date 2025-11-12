#include<bits/stdc++.h>
using namespace std;
int n,m;
bool c(int x,int y)
{
	return x>y;
}
int f(int x,int y,char c,int s)
{
	if(s==1) cout<<x<<" "<<y;
	else
	{
		if(c=='y')
		{
			if((x+1)<=m)
			{
				y++;
				if((y-1)>0) c='u';
				else c='d';
			}
		}
		if(c=='d')
		{
			if((y+1)<=n)
			{
				y++;
			}
			else f(x,y,'y',s);
		}
		if(c=='u')
		{
			if((y-1)>0)
			{
				y--;
			}
			else f(x,y,'y',s);
		}
		s--;
	}
	
}
int main()
{
	cin>>n>>m;
	int a[101];
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int ai=a[1];
	sort(a+1,a+1+n*m,c);
	int s=1;
	for(s;s<=n*m;s++) if(a[s]==ai) break;
	int x=1,y=1;
	f(x,y,'d',s);
} 
