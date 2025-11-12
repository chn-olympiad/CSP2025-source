#include<cstdio>
using namespace std;
int n,m,a1,a,cnt,x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	scanf("%d",&a1);
	for(int i=2;i<=n*m;i++)
	{
		scanf("%d",&a);
		if(a>a1)cnt++;
	}
	cnt++;
	while(cnt>n*2)
	{
		cnt=cnt-n*2;
		x=x+2;
	}
	if(cnt<=n)
	{
		x=x+1;
		y=cnt;
	}
	else
	{
		x=x+2;
		y=n*2-cnt+1;
	}
	printf("%d %d",x,y);
	return 0;
}
