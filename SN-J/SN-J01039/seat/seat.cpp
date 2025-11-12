#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node
{
	int id,cj;
}a[110];
bool cmp(node x,node y)
{
	return x.cj>y.cj;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].cj;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1,t=0;
	for(int i=2;i<=n*m;i++)
	{
		if(t==0)
		{
			if(i%n==1)
			{
				y++;
				t=1;
			}
			else
			{
				x++;
			}
		}
		else
		{
			if(i%n==1)
			{
				y++;
				t=0;
			}
			else
			{
				x--;
			}
		}
		if(a[i].id==1)
		{
			cout<<y<<" "<<x<<"\n";
			return 0;
		}
		//cout<<i<<"  "<<x<<" "<<y<<"\n";
	}
	return 0;
}
