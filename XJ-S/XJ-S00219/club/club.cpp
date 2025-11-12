#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N=1e5+100;
int a[N][5];
int flag[N];
struct node
{
	int w,id,num,val;
}v[N];
bool cmp(node a,node b)
{
	return a.w>b.w;
}
int cnt[5];
int n,idx,ans,have;
priority_queue<int> q[5];
bool cmp2(int a,int b)
{
	return a>b;
}
vector<int> v1,v2;
void solve1()
{
	sort(v1.begin(),v1.end(),cmp2);
	for (int i=0;i<n/2;i++)
	{
		if (v1[i]>0) ans+=v1[i];
	}
	cout<<ans<<endl;
	return ;
}
vector<pair<int,int> > vv;
void solve()
{
	while (q[2].size()) q[2].pop();
	while (q[3].size()) q[3].pop();
	memset(cnt,0,sizeof cnt);
	idx=0,ans=0,have=0;
	int flag1=1,flag2=1;
	cin>>n;
	v1.clear();
	v2.clear();
	for (int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		v1.push_back(a[i][1]);
		v2.push_back(a[i][2]);
		vv.push_back({-a[i][1],i});vv.push_back({-a[i][2],i});
		if (a[3]!=0) flag1=0;
		if (a[2]!=0) flag2=0;
		flag[i]=0;
	}
	if (flag1 && flag2)
	{
		solve1();
		return ;
	}
	for (int i=1;i<=n;i++)
	{
		int x=a[i][2]-a[i][1];
		int y=a[i][3]-a[i][1];
		idx++;
		v[idx]={x,3,i,y-x};
		idx++;
		v[idx]={y,2,i,x-y};
	}
	sort(v+1,v+1+idx,cmp);
	for (int i=1;i<=idx;i++)
	{
		int val=v[i].val;
		int w=v[i].w;
		int id=v[i].id;
		int num=v[i].num;
		if (flag[num]==2) continue;
		int now=a[num][1];
		if (flag[num]==0 && w<0 && have>=n/2)
		{
			ans+=now;
			flag[num]=2;
			continue;
		}
		if (cnt[id]<n/2) cnt[id]++,ans+=now+w,have++,q[id].push(val),flag[num]=2;
		else
		{
			flag[num]++;
			if (flag[num]==2)
			{
				int t=q[id].top();
				q[id].pop();
				if (val-t>0)
				{
					q[id].push(-val);
					ans+=now+w+val-t;
				}
				else ans+=now,q[id].push(t);
				have++;
			}
		}
	}
	cout<<ans<<endl;
	return ;
}
signed main ()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while (T--) solve();
	return 0;
}
/*
1
10
0 1 2
0 1 4
0 1 1
0 2 1
0 1 1
0 1 5
0 1 1
0 1 1
0 1 1
0 1 1
 * */
