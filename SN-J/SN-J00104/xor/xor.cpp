#include<bits/stdc++.h>
const int MAXN=(5e5+5);
typedef long long LL;
int n,k,a[MAXN];
LL pre[MAXN],suf[MAXN];
struct Point
{
	int l,r;
	inline friend bool operator<(const Point x,const Point y)
	{
		if(x.r!=y.r) return x.r<y.r;
		else return x.l>y.l;
	}
};
Point s[MAXN<<1];
inline void solve()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=n;i>=1;i--)
		pre[i]=pre[i+1]^(1LL*a[i]);
	std::map<int,int> mp;
	int tot=0;
	for(int i=n;i>=1;i--)
	{
		int t=(pre[i]^k);
		if(a[i]==k)
		{
			s[++tot]={i,i};
			continue;
		}
		if(mp.count(t))
			s[++tot]={i,mp[t]-1};
		else if(pre[i]==k) s[++tot]={i,n};
		mp[pre[i]]=i;
	}
	for(int i=1;i<=n;i++)
		suf[i]=(suf[i-1]^(1LL*a[i]));
	mp.clear();
	for(int i=1;i<=n;i++)
	{
		int t=(suf[i]^k);
		if(a[i]==k)
			continue;
		if(mp.count(t))
			s[++tot]={mp[t]+1,i};
		else if(suf[i]==k) s[++tot]={1,i};
		mp[suf[i]]=i;
	}
	std::sort(s+1,s+tot+1);
	int ans=1,t=s[1].r;
	for(int i=2;i<=tot;i++)
	{
		if(s[i].l>t)
			ans++,t=s[i].r;
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int T=1;
	while(T--) solve();
	return 0;
}
