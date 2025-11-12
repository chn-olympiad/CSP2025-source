//SN-S00727  menkeming xi'anfulunzhongxue
#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,a[100010][4],w[100010];
multiset<int>in[100010];
multiset<pair<int,int>>q[4];
void work()
{
	cin>>n;
	int xx[4]={0};
	for(int i=1;i<=n;i++)
		in[i].clear();
	q[1].clear();
	q[2].clear();
	q[3].clear();
	
	for(int i=1;i<=n;i++){
		w[i]=0;
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		int maxx=0,maxid=-1;
		for(int j=1;j<=3;j++)
		{
			if(maxx<a[i][j])
				maxid=j;
			maxx=max(maxx,a[i][j]);
		}
		w[i]=maxid;
		xx[maxid]++;
		if(maxid!=1) q[maxid].insert({abs(maxx-a[i][1]),i}),in[i].insert(abs(maxx-a[i][1]));
		if(maxid!=2) q[maxid].insert({abs(maxx-a[i][2]),i}),in[i].insert(abs(maxx-a[i][2]));
		if(maxid!=3) q[maxid].insert({abs(maxx-a[i][3]),i}),in[i].insert(abs(maxx-a[i][3]));
		while(xx[maxid]>n/2)
		{
			int u=(*q[maxid].begin()).first,v=(*q[maxid].begin()).second;
			q[maxid].erase(q[maxid].begin());
			in[v].erase(u);
			q[maxid].erase({*in[v].begin(),v});
			in[u].clear();
			if(w[v]!=1&&abs(a[v][w[v]]-a[v][1])==u&&xx[1]<n/2)
			{
				xx[maxid]--;
				w[v]=1;
				xx[1]++;
				q[1].insert({abs(a[v][1]-a[v][2]),v}),in[v].insert(abs(a[v][1]-a[v][2]));
				q[1].insert({abs(a[v][1]-a[v][3]),v}),in[v].insert(abs(a[v][1]-a[v][3]));
			}
			else if(w[v]!=2&&abs(a[v][w[v]]-a[v][2])==u&&xx[2]<n/2)
			{
				xx[maxid]--;
				w[v]=2;
				xx[2]++;
				q[2].insert({abs(a[v][2]-a[v][1]),v}),in[v].insert(abs(a[v][2]-a[v][1]));
				q[2].insert({abs(a[v][2]-a[v][3]),v}),in[v].insert(abs(a[v][2]-a[v][3]));
			}
			else if(w[v]!=3&&abs(a[v][w[v]]-a[v][3])==u&&xx[3]<n/2)
			{
				xx[maxid]--;
				w[v]=3;
				xx[3]++;
				q[3].insert({abs(a[v][3]-a[v][1]),v}),in[v].insert(abs(a[v][3]-a[v][1]));
				q[3].insert({abs(a[v][3]-a[v][2]),v}),in[v].insert(abs(a[v][3]-a[v][2]));
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		ans+=a[i][w[i]];
	cout<<ans<<'\n';
	return;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
		work();
	return 0;
}
