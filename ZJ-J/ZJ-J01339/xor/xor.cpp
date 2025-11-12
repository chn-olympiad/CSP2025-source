#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int n,m,lst,ans,a[500010],s[500010],b[4000010];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]),s[i] = s[i - 1] ^ a[i];
	for (int i = 1;i <= 4000000;i++) b[i] = -1;
	for (int i = 1;i <= n;i++)
	{
		if (b[s[i] ^ m] >= lst) lst = i,ans++;
		b[s[i]] = i;
	}
	printf("%d\n",ans);
	return 0;
} 
