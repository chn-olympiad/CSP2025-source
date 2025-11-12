#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=1e5+10;
int n;
pair<int,int>  a[N][4];
int x[N][3];
vector<int> b[4];
priority_queue<pair<int,int>,vector<pair<int,int> > ,greater<pair<int,int> > > q1;
priority_queue<pair<int,int> ,vector<pair<int,int> > ,less<pair<int,int> > > q2;
int cnt[4];
bool vst[N];
void init()
{
	for(int i=1;i<=n;i++)
		vst[i]=0,x[i][0]=x[i][1]=x[i][2]=0;
	for(int i=1;i<=3;i++)
		cnt[i]=0,b[i].clear();
	while(q1.size())
		q1.pop();
	while(q2.size())
		q2.pop();
}
void solve()
{
	init();
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
			cin>>a[i][j].first,a[i][j].second=j;
		sort(a[i]+1,a[i]+1+3,greater<pair<int,int> > ());
		for(int j=1;j<3;j++)
			x[i][j]=a[i][j].first-a[i][j+1].first;
		b[a[i][1].second].emplace_back(i);
	}
	int ans=0,id=0;
	for(int i=1;i<=3;i++)
	{
		if((signed)b[i].size()>=n/2)
		{
			id=i;
			break;
		}
	}
	if(id==0)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
			ans+=a[i][1].first;
		cout<<ans<<endl;
		return ;
	}
	sort(b[id].begin(),b[id].end(),[](const int &t1,const int &t2){return a[t1][1].first>a[t2][1].first;});
	for(int i=0;i<n/2;i++)
		q1.emplace(x[b[id][i]][1],b[id][i]),vst[b[id][i]]=1;
	for(int i=1;i<=n;i++)
	{
		if(vst[i])
			continue;
		if(a[i][1].second==id)
			q2.emplace(x[i][1],i);
	}
	while(q1.size()&&q2.size())
	{
		if(q1.top().first<q2.top().first)
		{
			vst[q1.top().second]=0;
			vst[q2.top().second]=1;
			q1.pop(),q2.pop();
		}
		else
			break;
	}
	for(int i=1;i<=n;i++)
	{
		if(vst[i])
		{
			for(int j=1;j<=3;j++)
			{
				if(a[i][j].second==id)
				{
					ans+=a[i][j].first;
					break;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!vst[i])
		{
			for(int j=1;j<=3;j++)
			{
				if(a[i][j].second==id)
					continue;
				ans+=a[i][j].first;
				break;
			}
		}
	}
	cout<<ans<<endl;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--)
		solve();
	return 0;
}