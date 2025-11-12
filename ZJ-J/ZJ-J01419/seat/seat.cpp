#include<bits/stdc++.h>
using namespace std;
struct node{
	int cj,id;
}a[255];
int n,m,x,y,c,zw[15][15];
bool cmp(node a,node b)
{
	return a.cj>b.cj;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)
	{
		cin>>a[i].cj;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	x=1;
	y=1;
	while(c!=n*m+1)
	{
		zw[x][y]=a[c+1].id;
		if(x==n)
		{
			if(y%2==1)
			  ++y;
			else
			  --x;
			++c;
			continue;
		}
		if(x==1)
		{
			if(y%2==1)
			  ++x;
			else
			  ++y;
			++c;
			continue;
		}
		if(y%2==1)
		  ++x;
		else
		  --x;
		++c;
	}
	for(int i=1;i<=n;++i)
	  for(int j=1;j<=m;++j)
	    if(zw[i][j]==1)
	    {
	    	cout<<j<<' '<<i;
	    	break;
		}
	return 0;
}
