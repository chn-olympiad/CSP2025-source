#include <bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
ll T, n;
pair <ll,ll> a[100005];
pair <ll,ll> b[100005];
pair <ll,ll> c[100005];
bool cmp(pair <ll,ll> a, pair <ll, ll> b)
{
   	return a.first>b.first;
}
class sch
{ 
    private:
    	ll ca=0, cb=0, cc=0;
    	ll cpeo[100005];
    public:
		ll solve()
		{
			ll ans=0;
			for (int i=1;i<=n;i++)
			{
				if ((a[i].first>b[i].first)&&(b[i].first>c[i].first)&&ca+1<=n/2&&cpeo[a[i].second]==0) 
				{
					ca++;
					ans+=a[i].first;
					cpeo[a[i].second]=1;
					continue;
				}
				else if(cb+1<=n/2&&cpeo[b[i].second]==0)
				{
					cb++;
					ans+=b[i].first;
					cpeo[b[i].second]=1;
					continue;
				}
				else if(cc+1<=n/2&&cpeo[c[i].second]==0)
				{
					cc++;
					ans+=c[i].first;
					cpeo[c[i].second]=1;
					continue;
				}
				if ((b[i].first>a[i].first)&&(a[i].first>c[i].first)&&cb+1<=n/2&&cpeo[b[i].second]==0) 
				{
					cb++;
					ans+=b[i].first;
					cpeo[b[i].second]=1;
					continue;
				}
				else if(ca+1<=n/2&&cpeo[a[i].second]==0)
				{
					ca++;
					ans+=a[i].first;
					cpeo[a[i].second]=1;
					continue;
				}
				else if(cc+1<=n/2&&cpeo[c[i].second]==0)
				{
					cc++;
					ans+=c[i].first;
					cpeo[c[i].second]=1;
					continue;
				}
				if ((c[i].first>b[i].first)&&(b[i].first>a[i].first)&&cc+1<=n/2&&cpeo[c[i].second]==0) 
				{
					cc++;
					ans+=c[i].first;
					cpeo[c[i].second]=1;
					continue;
				}
				else if(cb+1<=n/2&&cpeo[b[i].second]==0)
				{
					cb++;
					ans+=b[i].first;
					cpeo[b[i].second]=1;
					continue;
				}
				else if(ca+1<=n/2&&cpeo[a[i].second]==0)
				{
					ca++;
					ans+=a[i].first;
					cpeo[a[i].second]=1;
					continue;
				}
				if ((a[i].first>c[i].first)&&(c[i].first>b[i].first)&&ca+1<=n/2&&cpeo[a[i].second]==0) 
				{
					ca++;
					ans+=a[i].first;
					cpeo[a[i].second]=1;
					continue;
				}
				else if(cc+1<=n/2&&cpeo[c[i].second]==0)
				{
					cc++;
					ans+=c[i].first;
					cpeo[c[i].second]=1;
					continue;
				}
				else if(cb+1<=n/2&&cpeo[b[i].second]==0)
				{
					cb++;
					ans+=b[i].first;
					cpeo[b[i].second]=1;
					continue;
				}
				if ((b[i].first>c[i].first)&&(c[i].first>a[i].first)&&cb+1<=n/2&&cpeo[b[i].second]==0) 
				{
					cb++;
					ans+=b[i].first;
					cpeo[b[i].second]=1;
					continue;
				}
				else if(cc+1<=n/2&&cpeo[c[i].second]==0)
				{
					cc++;
					ans+=c[i].first;
					cpeo[c[i].second]=1;
					continue;
				}
				else if(ca+1<=n/2&&cpeo[a[i].second]==0)
				{
					ca++;
					ans+=a[i].first;
					cpeo[a[i].second]=1;
					continue;
				}
				if ((c[i].first>a[i].first)&&(a[i].first>b[i].first)&&cc+1<=n/2&&cpeo[c[i].second]==0) 
				{
					cc++;
					ans+=c[i].first;
					cpeo[c[i].second]=1;
					continue;
				}
				else if(ca+1<=n/2&&cpeo[a[i].second]==0)
				{
					ca++;
					ans+=a[i].first;
					cpeo[a[i].second]=1;
					continue;
				}
				else if(cb+1<=n/2&&cpeo[b[i].second]==0)
				{
					cb++;
					ans+=b[i].first;
					cpeo[b[i].second]=1;
					continue;
				}
			}
			return ans;
		}
};
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while (T--)
	{
		sch node;
		cin >> n;
		for (int i=1;i<=n;i++)
		{
			cin >> a[i].first >> b[i].first >> c[i].first;
			a[i].second=i, b[i].second=i, c[i].second=i;
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		cout << node.solve() << "\n";
	}
}
