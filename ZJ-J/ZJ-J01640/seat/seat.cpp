#include<bits/stdc++.h>
using namespace std;
int n,m,x,y=1;
struct Node{
	int n,id;
}a[110];
bool cmp(Node aa,Node bb)
{
	return aa.n>bb.n;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].n;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(y%2==1)
		{
			x++;
			if(x>n)
			{
				x=n;
				y++;
			}
		}
		else
		{
			x--;
			if(x<=0)
			{
				x=1;
				y++;
			}
		}
		if(a[i].id==1)
		{
			cout<<y<<' '<<x;
			return 0; 
		}
	}
	return 0;
}
