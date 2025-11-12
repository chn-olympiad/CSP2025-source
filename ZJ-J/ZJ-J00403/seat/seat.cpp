#include <bits/stdc++.h>
using namespace std;
int n,m,sc,a[105],id,c,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	sc=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
		if(a[i]==sc)
		{
			id=i;
			break;
		}
	id=n*m-id;
	c=(id+n)/n;
	if(c%2)r=id%n+1;
	else r=n-id%n;
	printf("%d %d",c,r);
	return 0;
}