#include<bits/stdc++.h>
using namespace std;
struct node
{
	int p,id;
};
node a[105];
int n,m;
bool cmp(node x,node y)
{
	return x.p>y.p;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		int x;
		cin>>x;
		a[i].p=x,a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int tmp=0;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].id==1)
		{
			tmp=i;
			break;
		}
	}
	int x,y;
	int k=tmp/n;
	if(k*n==tmp)
	{
		x=k;
		y=n;
	}
	else
	{
		x=k+1;
		if(x%2==1)
    	{
    		y=tmp%n;
    	}
    	else
    	{
	    	y=(n-(tmp%n))+1;
    	}
	}
	cout<<x<<' '<<y;
	return 0;
}
