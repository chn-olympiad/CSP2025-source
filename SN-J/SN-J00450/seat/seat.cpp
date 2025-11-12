#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int a[N];
int n,m;
int p = 0;
void dfs(int x,int y,int step,int op)
{
//	cout<<x<<" "<<y<<"\n";
	if(step==p)//找到了第p个 
	{
		cout<<y<<" "<<x<<"\n";
		return ;
	}
	if(op==1)//向下走 
	{
		if(x+1<=n)//有空 
		{
			dfs(x+1,y,step+1,1);//下去 
		}
		else 
		{
			dfs(x,y+1,step+1,0);//往右走，走完向上转 
		}
	}
	else//向上走
	{
		if(x-1>0)//有空 
		{
			dfs(x-1,y,step+1,0);//上去 
		}
		else 
		{
			dfs(x,y+1,step+1,1);//往右走，走完向上转 
		}
	 } 
}
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int hua = a[1];
	sort(a+1,a+n*m+1,cmp);
//	for(int i = 1;i<=n*m;i++) 
//	{
//		cout<<a[i]<<" ";
//	}
	for(int i = 1;i<=n*m;i++)
	{
		if(a[i]==hua)
		{
			p=i;
			break;
		}
	}
//	cout<<p<<"\n"; 
	dfs(1,1,1,1/*0上1下*/);
	return 0;
 } 
