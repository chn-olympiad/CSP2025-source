#include<bits/stdc++.h>
using namespace std;
const int maxn=500,md=998244353;
int a[maxn+10],c[maxn+10],cnt,m,n,sumn;
bool bz[maxn+10];
char s[maxn+10];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int i;
	scanf("%d%d%s",&n,&m,s);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&c[i]);
		bz[i]=s[i-1]-'0';
		a[i]=i;
	}
	do
	{
		cnt=0;
		for(i=1;i<=n;++i)
			if(cnt>=c[a[i]]||!bz[i])
				++cnt;
		if(cnt==n-m)
			sumn=(sumn+1)%md;
	}while(next_permutation(a+1,a+n+1));
	printf("%d",sumn);
	return 0;
}
