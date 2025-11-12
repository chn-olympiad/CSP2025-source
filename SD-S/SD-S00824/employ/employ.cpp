#include <bits/stdc++.h>
#define LL long long
using namespace std;
int n,m;
char s[600];
int c[600],p[600];
LL ans,mod=998244353;
bool pd1()
{
	for(int i=1;i<=n;i++) if(s[i]=='0') return 0;
	return 1;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	if(pd1())
	{
		ans=1;int cnt=0;
		for(int i=1;i<=n;i++) 
		{
			if(c[i]!=0) cnt++; 
		}
		for(int i=1;i<=cnt;i++) ans=ans*i%mod;
		if(cnt<m) printf("0");
		else printf("%lld",ans);
		return 0;
	}
	for(int i=1;i<=n;i++) p[i]=i;
	do
	{
		int cnt=0,sum=0;
		for(int i=1;i<=n;i++)
		{
			if(cnt>=c[p[i]]) cnt++;
			else if(s[i]=='0') cnt++; 
			else sum++;
		}
		if(sum>=m) ans++; 
	}while(next_permutation(p+1,p+1+n));
	printf("%lld",ans);
	return 0;
}
