#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int t,n;
ll a[N],b[N],c[N],vis[N];
priority_queue<ll> q;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		int cnt1=0,cnt2=0,cnt3=0;
		ll ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
		for(int i=1;i<=n;i++)
		{			
			ll ma=max({a[i],b[i],c[i]});ans+=ma;
			if(a[i]==ma)
			{
				cnt1++;
				vis[i]=1;
			}
			else if(b[i]==ma)
			{
				cnt2++;
				vis[i]=2;
			}
			else
			{
				cnt3++;
				vis[i]=3;
			}
		}
		int v=0;ll sum=0;
		if(cnt1>n/2)
		{
			v=1;sum=cnt1-n/2;
		}
		else if(cnt2>n/2)
		{
			v=2;sum=cnt2-n/2;
		}
		else if(cnt3>n/2) 
		{
			v=3;sum=cnt3-n/2;
		} 
		if(!v)
		{
			printf("%lld\n",ans);
			continue;
		}
		while(!q.empty()) q.pop();
		for(int i=1;i<=n;i++)
		{
			if(vis[i]!=v) continue;
			if(v==1)
			{
				q.push(max(b[i],c[i])-a[i]);
			}
			else if(v==2)
			{
				q.push(max(a[i],c[i])-b[i]);
			}
			else
			{
				q.push(max(a[i],b[i])-c[i]);
			}
		}
		while(sum--)
		{
			ans+=q.top();q.pop();
		}
		printf("%lld\n",ans);
	}
	return 0;
} 