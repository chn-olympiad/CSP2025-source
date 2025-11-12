#include<bits/stdc++.h>
using namespace std;
struct node
{
	int value;
	bool r;
};
bool cmp(node a,node b)
{
	return a.value>b.value;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,j,sum=0;
	node a[101]={};
	cin>>n>>m>>a[1].value;
	a[1].r=true;
	for(i=2;i<=n*m;i++)
	{
		cin>>a[i].value;
		a[i].r=false;
	}
	sort(a+1,a+1+n*m,cmp);
	for(i=1;i<=m;i++)
		if(i&1)
			for(j=1;j<=n;j++)
			{
				sum++;
				if(a[sum].r)
				{
					cout<<i<<' '<<j;
					return 0;
				}
			}
		else
			for(j=n;j>0;j--)
			{
				sum++;
				if(a[sum].r)
				{
					cout<<i<<' '<<j;
					return 0;
				}
			}
	return 0;
}
