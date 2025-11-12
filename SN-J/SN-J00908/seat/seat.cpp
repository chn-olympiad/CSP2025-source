#include <bits/stdc++.h>
using namespace std;
int n,m;
struct node
{
    int bj,point;	
}a[101];
bool cmp(node x,node y)
{
	return x.point>y.point;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].point;
		a[i].bj=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int c=1,r=1;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].bj==1)
		{
			cout<<c<<" "<<r;
			break;
		}
		if((c%2==1&&r==n)||(c%2==0&&r==1))
		{
			c++;
		}
		else if(c%2==1)
		{
			r++;
		}
		else if(c%2==0)
		{
			r--;
		}
	}
	return 0;
}
