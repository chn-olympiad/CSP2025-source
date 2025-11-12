#include<bits/stdc++.h>
using namespace std;
int n,m,x=1,y=1,a[10000],p;
int main() 
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",a+i);
	p=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--)
	{
		if(p==a[i]) break;
		if(y&1==1)
			if(x==n) y++;
			else x++;
		else
			if(x==1) y++;
			else x--;
	}
	printf("%d %d",y,x);
	return 0;
}