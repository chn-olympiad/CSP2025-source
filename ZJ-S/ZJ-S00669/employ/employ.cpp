#include <bits/stdc++.h>
using namespace std;
const int N=15;
int n,m,k[N],c[N],a[N],ans;
char s[N];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)k[i]=s[i]-'0';
	for (int i=1;i<=n;i++)scanf("%d",&c[i]),a[i]=i;
	do
	{
		int now=0,t=0;
		for (int i=1;i<=n;i++)
		{
			if (k[i] && now<c[a[i]])t++;
			else now++;
		}
		if (t>=m)ans++;
	}while (next_permutation(a+1,a+n+1));
	printf("%d",ans);
	return 0;
}
