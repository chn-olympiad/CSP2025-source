//根本不会，干脆打暴力
#include <bits/stdc++.h>
using namespace std;
const int N=555,M=998244353;
int n,m,c[N],p[N];
char s[N];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
		p[i]=i;
	}
	int ct=0;
	do
	{
		int nu=0,fl=0;
		for(int i=1;i<=n;i++)
		{
			if(fl>=c[p[i]]||s[i]=='0')
			{
				fl++;
			}
			else
			{
				nu++;
			}
		}
		if(nu>=m)
		{
			ct++;
			ct%=M;
		}
	}
	while(next_permutation(p+1,p+n+1));
	printf("%d\n",ct);
	return 0;
}