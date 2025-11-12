#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll N = 1e4 + 7;
constexpr ll M = 1e6 + 7;
struct node
{
	ll u,v,w;
	bool operator <(const node &x)const
	{
		return w < x.w;
	}
};
vector <node> A;
ll zu[N];
ll n,m,k;
void init()
{
	for (ll i = 1; i <= n; i ++) zu[i] = i;
	return ;
}
ll find(ll x)
{
	if (zu[x] == x) return x;
	return zu[x] = find(zu[x]);
}
bool merge(ll a,ll b)
{
	ll t1 = find(a);
	ll t2 = find(b);
	if (t1 == t2) return true;
	zu[t1] = t2;
	return false; 
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for (ll i = 1; i <= m; i ++)
	{
		ll u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		A.push_back((node){u,v,w});
	}
	ll sum = 0;
	for (ll i = 1; i <= k; i ++)
	{
		ll c;
		scanf("%lld",&c);
		sum += c;
		for (ll j = 1; j <= n; j ++)
		{
			ll w;
			scanf("%lld",&w);
			sum += w;
		}
	}
	if (k != 0 && sum == 0)
	{
		printf("0");
		return 0;
	}
	sum = 0;
	sort(A.begin(),A.end());
	init();
	for (node i : A)
	{
		if (!merge(i.u,i.v))
		{
			sum += i.w;
		}
	}
	printf("%lld\n",sum);
	return 0;
} 
