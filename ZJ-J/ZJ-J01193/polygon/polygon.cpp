#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long p[5005],s;
int a[5005],ma1;
int n,i,j,k;
void dfs(int x,int ma,int he,int p)
{
if(x>n)
  {
  	if(p>2&&he>ma*2)
  	  s=(s+1)%MOD;
  	return;
  }
int y=max(ma,a[x]);
dfs(x+1,y,he+a[x],p+1);
dfs(x+1,ma,he,p);
}
int main()
{
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
scanf("%d",&n);
for(i=1;i<=n;i++)
  {
    scanf("%lld",&a[i]);
  	ma1=max(ma1,a[i]);
  }
if(ma1==1)
  {
  	p[0]=1;
  	for(i=1;i<=n;i++)
  	  p[i]=p[i-1]*i%MOD;
  	for(i=3;i<=n;i++)
  	  s=s+(p[n]/((p[i]*p[n-i])%MOD))%MOD;
  	printf("%lld",s);
  	return 0;
  }
dfs(1,0,0,0);
printf("%lld",s);
return 0;
}
