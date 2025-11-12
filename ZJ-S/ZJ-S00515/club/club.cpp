#include <bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int N=1e5+5,inf=1e9;
int T,n;
ll a[N][4];
struct node
{
	int id,w;
	node(const int Id=0,const int W=0) : id(Id),w(W) {}
	bool operator<(const node &b) const {return this->w<b.w;}
};
priority_queue<node> s[4];
int p[N];
int iid[N][4];
void solve()
{
	ll ans=0;
	cin>>n;
	for(int i=1;i<=3;i++) while(!s[i].empty()) s[i].pop();
	for(int i=1;i<=n;i++)
	{
		ll mx=0;
		int pos=0;
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
			if(a[i][j]>mx)
				mx=a[i][j],pos=j;
			iid[i][j]=j;
		}
		for(int j=1;j<=3;j++)
			a[i][j]-=mx;
		sort(iid[i]+1,iid[i]+4,[i](const int &x,const int &y){return a[i][x]>a[i][y];});
//		cerr<<iid[i][1]<<' '<<iid[i][2]<<' '<<iid[i][3]<<'\n';
		sort(a[i]+1,a[i]+4,greater<int>());
		a[i][3]-=a[i][2];
//		cerr<<a[i][1]<<' '<<a[i][2]<<' '<<a[i][3]<<'\n';
//		cerr<<i<<' '<<mx<<' '<<pos<<'\n';
		ans+=mx;
		s[pos].emplace(i,a[i][2]);
		p[i]=1;
	}
//	cerr<<"ans: "<<ans<<'\n';
	for(int t=1;t<=3;t++)
		while((int)s[t].size()>(n>>1))
		{
			node tmp=s[t].top();
			s[t].pop();
			int id=tmp.id,w=tmp.w;
//			cerr<<id<<' '<<w<<'\n';
			ans+=w;
			if(p[id]<=2)
				s[iid[id][p[id]+1]].emplace(id,p[id]==2?-inf:a[id][p[id]+2]),p[id]++;
		}
	cout<<ans<<'\n';
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>T;
	while(T--)
		solve();
	return 0;
}
