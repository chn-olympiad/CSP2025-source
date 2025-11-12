#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
struct node{
	int a,id;
}a[N];
int n,m,x=1,y=1,wa=1;
bool cmp(node x,node y)
{
	return x.a>y.a;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i].a);
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].id==1)
		{
			printf("%d %d",x,y);
		}
		int xx=x,yy=y+wa;
		if(yy<1)
		{
			yy=1;
			xx++;
			wa=1;
		}
		if(yy>m)
		{
			yy=m;
			xx++;
			wa=-1;
		}
		x=xx;
		y=yy;
	}
	return 0;
}
