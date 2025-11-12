#include<bits/stdc++.h>

using namespace std;

#define ll long long

struct node
{
	ll big;
	ll small;
};

ll n;
ll v[100010][4];
vector<node> a1,a2,a3;
ll ans=0;

void dfs(ll tot,ll k,ll t1,ll t2,ll t3)
{
	if(k==(n+1))
	{
		ans=max(ans,tot);
		return;
	}
	if(t1<(n/2))
	{
		dfs(tot+v[k][1],k+1,t1+1,t2,t3);
	}
	if(t2<(n/2))
	{
		dfs(tot+v[k][2],k+1,t1,t2+1,t3);
	}
	if(t3<(n/2))
	{
		dfs(tot+v[k][3],k+1,t1,t2,t3+1);
	}
	return;
}

void solve(void)
{
	scanf("%lld",&n);
	bool tf2=true,tf3=true;
	a1.clear();
	a2.clear();
	a3.clear();
	for(ll i=1;i<=n;++i)
	{
		scanf("%lld%lld%lld",&v[i][1],&v[i][2],&v[i][3]);
		if(v[i][2]!=0)
		{
			tf2=false;
		}
		if(v[i][3]!=0)
		{
			tf3=false;
		}
	}
	if(tf2==true&&tf3==true)
	{
		map<ll,ll> mp;
		mp.clear();
		for(ll i=1;i<=n;++i)
		{
			mp[v[i][1]]++;
		}
		ll tot=0;
		ll k=0;
		for(auto xixi:mp)
		{
			while(xixi.second--)
			{
				if(k>(n/2))
				{
					break;
				}
				++k;
				tot+=xixi.first;
			}
			if(k>(n/2))
			{
				break;
			}
		}
		printf("%lld\n",tot);
	}
	else if(tf3==true)
	{
		ll tot1=0,tot2=0;
		for(ll i=1;i<=n;++i)
		{
			if(v[i][1]>=v[i][2])
			{
				a1.push_back((node){v[i][1],v[i][2]});
				tot1+=v[i][1];
			}
			else
			{
				a2.push_back((node){v[i][2],v[i][1]});
				tot2+=v[i][2];
			}
		}
		if((a1.size()<=(n/2)&&a2.size()<=(n/2)))
		{
			printf("%lld\n",(tot1+tot2));
		}
		else
		{
			ans=0;
			dfs(0,1,0,0,0);
			printf("%lld\n",ans);
		}
	}
	else
	{
		ll tot1=0,tot2=0,tot3=0;
		for(ll i=1;i<=n;++i)
		{
			if((v[i][1]>=v[i][2])&&(v[i][1]>=v[i][3]))
			{
				a1.push_back((node){v[i][1],max(v[i][2],v[i][3])});
				tot1+=v[i][1];
			}
			else if((v[i][2]>=v[i][1])&&(v[i][2]>=v[i][3]))
			{
				a2.push_back((node){v[i][2],max(v[i][1],v[i][3])});
				tot2+=v[i][2];
			}
			else
			{
				a3.push_back((node){v[i][3],max(v[i][1],v[i][2])});
				tot3+=v[i][3];
			}
		}
		if((a1.size()<=(n/2))&&(a2.size()<=(n/2))&&(a3.size()<=(n/2)))
		{
			printf("%lld\n",(tot1+tot2+tot3));
		}
		else
		{
			ans=0;
			dfs(0,1,0,0,0);
			printf("%lld\n",ans);
		}
	}
	return;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t;
	cin>>t;
	while(t--) solve();
	return 0;
}