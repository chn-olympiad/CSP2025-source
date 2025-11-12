#include<bits/stdc++.h>
using namespace std;
const int N=105;
struct node
{
	int w,id;
}a[N];
bool cmp(node a,node b)
{
	return a.w>b.w;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].w;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1,x=1,y=1;i<=n*m;i++)
	{
		if(a[i].id==1)
		{
			cout<<x<<" "<<y;
			return 0;
		}
		if(x&1)
		{
			y++;
			if(y==n+1)
			{
				y--;
				x++;
			}
		}
		else
		{
			y--;
			if(y==0)
			{
				y++;
				x++;
			}
		}
	}
	return 0;
}

