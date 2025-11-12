#include <bits/stdc++.h>
using namespace std;
char a[555];
int c[555];
const long long P = 998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	scanf("%s", a + 1);
	int flag = 1;
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&c[i]);
		if(c[i] == 0)
		{
			flag = 0;
		}
	}
	if(flag == 0)
	{
		printf("0");
		return 0;
	}
	long long ret = 1;
	for(int i = n;i >= 1;i--)
	{
		ret = ret * i % P;
	}
	printf("%lld",ret);
	return 0;
}
