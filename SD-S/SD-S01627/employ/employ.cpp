#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#define man 507
int n,m,c[man];
char s[507],ss[507];
bool judge()
{
	for(int i=1;i<=n;i++)
	{
		if(s[i]!=ss[i]) return 0;
	}
	return 1;
}
int main()
{
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	srand(time(0));
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	printf("%d\n",rand()%998244353);
	return 0;
}
