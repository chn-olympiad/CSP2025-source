#include<bits/stdc++.h>
using namespace std;
long long a[1005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,ma=1;
	scanf("%d%d%d",&n,&m,&a[1]);
	for(long long i=2;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>a[1])
			ma++;
	}
	long long b=((ma-1)/n)%2,c=(ma-1)%n+1;
	if(b==0)
		printf("%d %d",(((ma-1)/n)+1),c);
	else if(b==1)
	{
		printf("%d %d",(((ma-1)/n)+1),n-c+1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}