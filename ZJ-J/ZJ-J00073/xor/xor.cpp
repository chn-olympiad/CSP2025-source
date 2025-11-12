#include<cstdio>
#define ll long long
using namespace std;
const int maxn=5e5+10;
int n,k,a_,a[maxn];
bool B=true;
ll ans,f[maxn];
ll max(ll max1,ll max2){if(max1>max2)return max1;return max2;}
ll dfs(int l,int r)
{
	ll res=((a[r]^a[l-1])==k);
	for(int i=l;i<r;i++)
	{
		res=max(dfs(l,i)+dfs(i+1,r),res);
	}
	printf("%d %d %d\n",l,r,res);
	return res;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a_);
		a[i]=a[i-1]^a_;
		if(a_>1)B=false;
	}
	if(n<=2000)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++)
			{
				if((a[i]^a[j-1])==k)
					f[i]=max(f[i],f[j-1]+1);
				else f[i]=max(f[i],f[j-1]);
			}
		ans=f[n];
	}
	else if(B)
	{
		ll res=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]^a[i-1])res++;
			if(k)ans=ans+(res-1>>1);
			else ans=ans+(res>>1);
		}
	}
	else ans=dfs(1,n);
	printf("%lld",ans);
	return 0;
}
