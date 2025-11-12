#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],x,h,l;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;++i)
		scanf("%d",a+i);
	x=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;++i)
		if(a[i]==x)
		{
			x=n*m-i+1;
			break;
		}
	if(x%n==0)l=x/n;else l=x/n+1;
	h=x-(l-1)*n;
	if(l%2==0)
		h=n-h+1;
	printf("%d %d",l,h);
	return 0;
}
