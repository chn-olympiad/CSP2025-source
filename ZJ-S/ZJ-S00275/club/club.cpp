#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define gc getchar()
#define pll pair<ll,ll>
#define pb push_back
#define id second
#define val first
#define mkp makepair
const ll maxn=2e5+1010,mod=998244353,INF=1e18+1010;
inline void read(ll &x)
{
	x=0;char ch=gc;
	while(ch<'0'||ch>'9')ch=gc;
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=gc;
}
priority_queue<ll,vector<ll>,greater<ll> > q[4];
ll t,n,f,s,ans;
pll tmp;
ll a[maxn][4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(t);
	while(t--)
	{
		ans=0;
		while(q[1].size())q[1].pop();
		while(q[2].size())q[2].pop();
		while(q[3].size())q[3].pop();
		read(n);
		for(int i=1;i<=n;i++)
		{
			read(a[i][1]);read(a[i][2]);read(a[i][3]);
			f=max(max(a[i][1],a[i][2]),a[i][3]);
			if(a[i][1]==f)
			{
				s=max(a[i][2],a[i][3]);
				if(q[1].size()>=n/2)
				{
					if(q[1].top()<f-s)
					{
						ans-=q[1].top();
						q[1].pop();
						q[1].push(f-s);
						ans+=f;
					}
					else ans+=s;
				}
				else
				{
					q[1].push(f-s);
					ans+=f;
				}
			}
			else if(a[i][2]==f)
			{
				s=max(a[i][1],a[i][3]);
				if(q[2].size()>=n/2)
				{
					if(q[2].top()<f-s)
					{
						ans-=q[2].top();
						q[2].pop();
						q[2].push(f-s);
						ans+=f;
					}
					else ans+=s;
				}
				else
				{
					q[2].push(f-s);
					ans+=f;
				}
			}
			else
			{
				s=max(a[i][1],a[i][2]);
				if(q[3].size()>=n/2)
				{
					if(q[3].top()<f-s)
					{
						ans-=q[3].top();
						q[3].pop();
						q[3].push(f-s);
						ans+=f;
					}
					else ans+=s;
				}
				else
				{
					q[3].push(f-s);
					ans+=f;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
