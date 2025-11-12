#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,t,a[100005],b[100005],c[100005],sy1,sy2,sy3,ans,st[100005],cnt;
signed main()
{
//	system("fc club5.ans club.out");
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cnt=sy1=sy2=sy3=ans=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
			if(a[i]>=b[i]&&a[i]>=c[i]) sy1++,ans+=a[i];
			else if(b[i]>=a[i]&&b[i]>=c[i]) sy2++,ans+=b[i];
			else if(c[i]>=b[i]&&c[i]>=a[i]) sy3++,ans+=c[i];
		}
		if(sy1>n/2)
		{
			for(int i=1;i<=n;i++)
				if(a[i]>=b[i]&&a[i]>=c[i])
					st[++cnt]=a[i]-max(b[i],c[i]);
			sort(st+1,st+cnt+1);
			for(int i=1;i<=sy1-n/2;i++)
				ans-=st[i];
		}
		if(sy2>n/2)
		{
			for(int i=1;i<=n;i++)
				if(a[i]>=b[i]&&a[i]>=c[i]);
				else if(b[i]>=a[i]&&b[i]>=c[i])
					st[++cnt]=b[i]-max(c[i],a[i]);
			sort(st+1,st+cnt+1);
			for(int i=1;i<=sy2-n/2;i++)
				ans-=st[i];
		}
		if(sy3>n/2)
		{
			for(int i=1;i<=n;i++)
				if(a[i]>=b[i]&&a[i]>=c[i]);
				else if(b[i]>=a[i]&&b[i]>=c[i]);
				else if(c[i]>=b[i]&&c[i]>=a[i])
					st[++cnt]=c[i]-max(b[i],a[i]);
			sort(st+1,st+cnt+1);
			for(int i=1;i<=sy3-n/2;i++)
				ans-=st[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
