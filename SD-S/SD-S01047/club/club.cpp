#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> PII;
const int N=5e5+10;
int T,n,cnt;
int a[N],num[N],vis[N],st[N];
int home_cnt[N];
int b[N/5][5];
int j_cnt[5];
int pos[N];
int mx[N];
ll res;
map<PII,PII> mp;
vector<int> v[N];
void solve()
{
	sort(a+1,a+1+cnt,greater<int>());
	int k=n/2;
	ll ans=0;
	int m=0;
	memset(home_cnt,0,sizeof(home_cnt));
	memset(vis,0,sizeof(vis));
	memset(st,0,sizeof(st));
	for(int i=1;i<=cnt;i++)
	{
		st[a[i]]++;
		if(a[i]==0) break;
		if(vis[mp[{st[a[i]],a[i]}].first]) continue;
		vis[mp[{st[a[i]],a[i]}].first]=1;
		if(home_cnt[mp[{st[a[i]],a[i]}].second]<k)
		{
			home_cnt[mp[{st[a[i]],a[i]}].second]++;
			ans+=a[i];
			//printf("a[%d]=%d ",i,a[i]);
			m++;
		}
		if(m>=n) break;
	}
	printf("%lld\n",ans);
}
void solve_200()
{
	sort(a+1,a+1+cnt,greater<int>());
	int k=n/2;
	ll ans=0;
	int m=0;
	memset(home_cnt,0,sizeof(home_cnt));
	memset(vis,0,sizeof(vis));
	memset(st,0,sizeof(st));
	st[a[1]]++;
	int l=1,r=1;
	home_cnt[mp[{st[a[1]],a[1]}].second]++;
	vis[mp[{st[a[1]],a[1]}].first]=1;
	m++;
	ll res=0;
	while(l<=r && l<=cnt && r<=cnt)
	{
		while(m<n)
		{
			r++;
			st[a[r]]++;
			if(vis[mp[{st[a[r]],a[r]}].first]) continue;
			vis[mp[{st[a[r]],a[r]}].first]=1;
			res+=a[r];
			home_cnt[mp[{st[a[r]],a[r]}].second]++;
			m++;
		}
		ans=max(ans,res);
		st[a[l]]--;
		if(vis[mp[{st[a[l]],a[l]}].first])
		{
			vis[mp[{st[a[l]],a[l]}].first]=1;
		}
		res-=a[l];
		home_cnt[mp[{st[a[l]],a[l]}].second]--;
		m--;
		l++;
		r=l;
	}
	printf("%lld\n",ans);
}
void dfs(int now,ll sum)
{
	ll sum_gu=0;
	for(int i=now-1;i<=n;i++)
	{
		sum_gu+=mx[i];
	}
	if(sum+sum_gu<=res) return;
	if(now==n+1)
	{
		res=max(res,sum);
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(j_cnt[i]+1<=n/2)
		{
			j_cnt[i]++;
			dfs(now+1,sum+b[now][i]);
			j_cnt[i]--;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		cnt=0;
		res=0;
		int B=0;
		memset(num,0,sizeof(num));
		mp.clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			v[i].clear();
			for(int j=1;j<=3;j++)
			{
				int x;
				scanf("%d",&x);
				mx[i]=max(mx[i],x);
				b[i][j]=x;
				v[i].push_back(x);
				if((j==2 || j==3) && x!=0) B=1;
				a[++cnt]=x;
				mp[{++num[x],x}]={i,j};
			}
		}
		if(!B)
		{
			priority_queue<int,vector<int>,less<int> > q;
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<=2;j++)
				{
					q.push(v[i][j]);
				}
			}
			ll ans=0;
			int hh=q.size();
			while(q.size()>hh-n/2)
			{
				ans+=q.top();
				q.pop();
			}
			printf("%lld\n",ans);
		}
		else if(n<=15)
		{
			dfs(1,0ll);
			printf("%lld\n",res);
		}
		else if(n<=200)
		{
			solve_200();
		}
		else
		{
			solve();
		}
	}
	return 0;
}
/*
5*3e5*20
把每个数对应的 i 作为编号，排序，从大到小遍历 
反悔
需要直接查找房间 
Ren5Jie4Di4Ling5%
*/
