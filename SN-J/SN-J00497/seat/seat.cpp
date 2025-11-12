//SN-J00497 李中易 西安辅轮中学
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,m;
int a[110],ans,x,y;

bool cmp(int c,int d)  { return c>d; }

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)  cin>>a[i];
	ans=a[1];
	sort(a+1,a+1+(n*m),cmp);
	x=1,y=1;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==ans)
		{
			cout<<x<<" "<<y;
			break;
		}
		if(x%2==1)
		{
			if(y==n)  x++;
			else  y++;
		}
		else
		{
			if(y==1)  x++;
			else  y--;
		}
	}
	return 0;
} 
