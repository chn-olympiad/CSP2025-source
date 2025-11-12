#include<bits/stdc++.h>
#define ll long long
#define ay array<ll,3>
using namespace std;
const ll N=1e5+5;
ll _,n,ans;
struct node{
	ll w,ip;
	bool friend operator<(node aa,node bb)
	{
		return aa.w>bb.w;
	}
}w[N][5];
priority_queue<ay,vector<ay>,greater<ay>>q[5];
ay aa;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>_;
	while(_--)
	{
		cin>>n;
		for(ll i=1;i<=3;i++)
		{
			while(!q[i].empty())q[i].pop();
		}
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=3;j++)
				cin>>w[i][j].w,w[i][j].ip=j;
		ll limit=n/2;
		for(ll i=1;i<=n;i++)
			stable_sort(w[i]+1,w[i]+4);
		ans=0;
		for(ll i=1;i<=n;i++)
		{
			if(q[w[i][1].ip].size()==limit)
			{
				aa=q[w[i][1].ip].top();
				if(aa[0]<w[i][1].w-w[i][2].w)
				{
					ans-=w[aa[2]][aa[1]].w;
					q[w[aa[2]][2].ip].push({w[aa[2]][2].w-w[aa[2]][3].w,2,aa[2]});
					ans+=w[aa[2]][2].w;
					q[w[i][1].ip].pop();
					ans+=w[i][1].w;
					q[w[i][1].ip].push({w[i][1].w-w[i][2].w,1,i});
				}
				else
				{
					q[w[i][2].ip].push({w[i][2].w-w[i][3].w,2,i});
					ans+=w[i][2].w;
				}
			}
			else
			{
				ans+=w[i][1].w;
				q[w[i][1].ip].push({w[i][1].w-w[i][2].w,1,i});
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}