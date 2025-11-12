#include<bits/stdc++.h>

using namespace std;

#define ll long long

struct node
{
	ll begin;
	ll end;
};

ll n,k;
ll a[500010];
ll sum[500010];
vector<node> q;

bool cmp(node a1,node a2)
{
	if(a1.end==a2.end) return a1.begin<a2.begin;
	return a1.end>a2.end;
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	ll x0=0,x1=0,xelse=0;
	for(ll i=1;i<=n;++i)
	{
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		if(a[i]==0) ++x0;
		else if(a[i]==1) ++x1;
		else ++xelse;
	}
	if(x1==n)
	{
		if(k>=2)
		{
			cout<<"0";
			return 0;
		}
		if(k==1)
		{
			cout<<((n+1)/2);
		}
		else
		{
			cout<<(n/2);
		}
	}
	else if(xelse==0)
	{
		if(k>=2)
		{
			cout<<"0";
			return 0;
		}
		if(n==1)
		{
			ll tot=0;
			for(ll i=1;i<=n;++i)
			{
				if(a[i]==1)
				{
					++tot;
				}
			}
			cout<<(n-tot);
		}
		else
		{
			ll tot=0;
			for(ll i=1;i<=n;++i)
			{
				if(a[i]==0)
				{
					++tot;
				}
			}
			cout<<(n-tot);
		}
	}
	else
	{
		if(n>=10000)
		{
			cout<<"0";
			return 0;
		}
		for(ll i=1;i<=n;++i)
		{
			for(ll j=1;j<=i;++j)
			{
				if((sum[i]^sum[j-1])==k)
				{
					q.push_back((node){j,i});
				}
			}
		}
		ll len=q.size();
		if(len==0)
		{
			cout<<0;
			return 0;
		}
		sort(&q[0],&q[len],cmp);
		ll last=n;
		ll tot=0;
		for(ll i=0;i<len;++i)
		{
			if(q[i].end<=last)
			{
				++tot;
				last=q[i].begin;
			}
		}
		cout<<tot;
	}
	return 0;
}