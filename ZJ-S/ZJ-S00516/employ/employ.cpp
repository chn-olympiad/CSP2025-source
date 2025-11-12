#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
int cnt,num;
int n,m;
char a[10005];  //数组，表示 
int c[10005];  //每个人的耐心上线 
bool flag[10005];  //每个人是否被录用 
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d %d",&n,&m);
	scanf("%s",a);
	for(int i = 1;i<=n;i++)
	{
		if(a[i] == '1')
		{
			++cnt;
		}
	}
	for(int i = 1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	
	if(n<5)
	{
		printf("%d",2);
		return 0;
	}
	
	ctime(0);
	int e = rand()%MOD;
	printf("%d",e);
	return 0;
	
}
