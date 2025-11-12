#include<bits/stdc++.h>
using namespace std;
int n,m,x,a[105];
int main()
{
	freopen("seat.in","r",stdin);
//	freopen("seat3.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",a+i);
	x=a[1];
	sort(a+1,a+n*m+1);
	x=lower_bound(a+1,a+n*m+1,x)-a;
	x=n*m-x+1;
//	printf("%d\n",x);
	printf("%d %d",(x+n-1)/n,(x+n-1)/n&1?x%n+(x%n?0:n):n-x%n-(x%n?0:n)+1);
	return 0;
}
