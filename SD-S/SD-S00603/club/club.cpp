#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+7;
struct bm{
	ll a,num;
}w[N][4];
ll cnt[4];
struct bh{
	ll dab,dbc,id;
}d[N];
bool cmp(bm x,bm y)
{
	return x.a>y.a;
}
bool cmp1(bh x,bh y)
{
	if(x.dab==y.dab)
		return x.dbc>y.dbc;
	return x.dab>y.dab;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll T;
	cin>>T;
	while(T--)
	{
		memset(cnt,0,sizeof(cnt));
		ll n,ans=0;
		cin>>n;
		ll m=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>w[i][1].a>>w[i][2].a>>w[i][3].a;
			w[i][1].num=1;
			w[i][2].num=2;
			w[i][3].num=3;
			sort(w[i]+1,w[i]+4,cmp);
			d[i].dab=w[i][1].a-w[i][2].a;
			d[i].dbc=w[i][2].a-w[i][3].a;
			d[i].id=i;
		}
		sort(d+1,d+n+1,cmp1);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				if(cnt[w[d[i].id][j].num]>=m)
				{
					continue;
				}
				cnt[w[d[i].id][j].num]++;
				ans+=w[d[i].id][j].a;
				break;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

