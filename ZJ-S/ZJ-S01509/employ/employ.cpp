#include<bits/stdc++.h>
using namespace std;
const int maxn=5e2+5,mod=998244353;
int n,m,c[maxn],y,f[maxn],q[maxn],ans;
long long jc[maxn];
string s;
bool b[maxn];
void dfs(int d,int sum,int sy,int fa)
{
	/*if(sy+sum<m||n-d+sum<m||q[fa+1]+sum<m)
	  return;*/
	if(sum>=m)
	  {
	  	ans=ans+jc[n-d];
	  	return;
	  }
	if(d==n)
	  {
	  	if(sum>=m)
	  	  ans++;
	  	return;
	  }
	  for(int i=1;i<=n;i++)
	    if(b[i])
	    {
	    	b[i]=0;
	    	if(s[d]=='0')
	    	  dfs(d+1,sum,sy,fa+1);
	    	else
	    	  if(c[i]<=fa)
	    	    dfs(d+1,sum,sy-1,fa+1);
	    	  else
	    	    dfs(d+1,sum+1,sy-1,fa);
	    	b[i]=1;
		}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	jc[0]=1;
	for(int i=1;i<=5e2;i++)
	  jc[i]=(jc[i-1]*i)%mod;
	cin>>s;
	for(int i=0;i<n;i++)
	  if(s[i]=='1')
	    y++;
	for(int i=1;i<=n;i++)
	  scanf("%d",&c[i]),f[c[i]]++,b[i]=1;
	if(m==n)
	  {
	  	if((!f[0])&&y==n)
	  	  printf("%d",jc[n]);
	  	else
	  	  printf("0");      
	  	printf("0");
	  	return 0;
	  }
	dfs(0,0,y,0);
	printf("%d",ans);	
}