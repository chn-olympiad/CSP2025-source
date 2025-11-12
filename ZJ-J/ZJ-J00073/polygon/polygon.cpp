#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=5010,mod=998244353;
int n,a[maxn],ans;
bool F=true;
ll dfs(int x,int y,int z,int p)
{
	if(x>n)return ((z>y*2)&&(p>=3));
	return (dfs(x+1,max(y,a[x]),z+a[x],p+1)+dfs(x+1,y,z,p))%mod;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>=1)F=false;
	}
	if(F)
	{
		for(int i=3;i<=n;i++)
		{
			ll temp=1;
			for(int j=n;j>n-i;j--)
				temp*=j;
			for(int j=1;j<=i;j++)
				temp/=j;
			ans=temp%mod;
		}
	}
	else ans=dfs(1,0,0,0)%mod;
	printf("%d",ans);
	return 0;
}
