#include<bits/stdc++.h>
using namespace std;
struct mc
{
	int x;int id;
};
int a[100005],b[100005],c[100005];
bool mark[100005];
int t;
int n,cnt;
long long ans;
void dfs(int x,long long sum,int ap,int bp,int cp)
{
	if(x>n)
	{
		ans=max(ans,sum);
		return;
	}
	if(ap+1<=n/2)
		dfs(x+1,sum+a[x],ap+1,bp,cp);
	if(bp+1<=n/2)
		dfs(x+1,sum+b[x],ap,bp+1,cp);
	if(cp+1<=n/2)
		dfs(x+1,sum+c[x],ap,bp,cp+1);
	return;
}
bool cmp(mc a,mc b)
{
	if(a.x!=b.x) return a.x>b.x;
	else return a.id<b.id;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int aper=0,bper=0,cper=0;
		ans=0;
		bool mark1=true,mark2=true,mark3=true;
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=0) mark1=false;
			if(b[i]!=0) mark2=false;
			if(c[i]!=0) mark3=false;
		}
		if(mark1&&mark2)
		{
			sort(a+1,a+n+1,greater<int>());
			for(int i=1;i<=n/2;i++) ans+=a[i];
			printf("%lld\n",ans);
			continue;
		}
		else if(mark1&&mark3)
		{
			sort(b+1,b+n+1,greater<int>());
			for(int i=1;i<=n/2;i++) ans+=b[i];
			printf("%lld\n",ans);
			continue;
		}
		else if(mark2&&mark3)
		{
			sort(c+1,c+n+1,greater<int>());
			for(int i=1;i<=n/2;i++) ans+=c[i];
			printf("%lld\n",ans);
			continue;
		}
		else if(n<=17)
		{
			dfs(1,0,0,0,0);
			printf("%lld",ans);
		}
		else
		{
			int ap=0,bp=0,cp=0;
			memset(mark,true,sizeof(mark));
			for(int i=1;i<=n;i++)
			{
				if(a[i]>=b[i]&&a[i]>=c[i]&&mark[i]&&ap<n/2) ap++,ans+=a[i],mark[i]=false;
				if(b[i]>=c[i]&&b[i]>=a[i]&&mark[i]&&bp<n/2) bp++,ans+=b[i],mark[i]=false;
				if(c[i]>=a[i]&&c[i]>=b[i]&&mark[i]&&cp<n/2) cp++,ans+=c[i],mark[i]=false;
				if(ap+bp+cp==n) break;
			}
			printf("%lld",ans);
		}
	}
}
