#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int val,id;
	bool operator < (const node & x)const
	{
		return this->val<x.val;
	}
}a[100100][3];
int b[100100][3];
struct NUM{
	int maxn,mid,minn;
	int maxn_id,mid_id,minn_id;
}num[100100];
int n,ans;
bool cmp(NUM x,NUM y)
{
	if(x.maxn==y.maxn)
	{
		if(x.mid==y.mid)
		{
			return x.minn>y.minn;
		}
		else
		{
			return x.mid>y.mid;
		}
	}
	else
	{
		return x.maxn>y.maxn;
	}
}
void dfs(int now,int cnt1,int cnt2,int cnt3,int num)
{
	if(now>n)
	{
		ans=max(ans,num);
		return ;
	}
	if(cnt1<n/2)dfs(now+1,cnt1+1,cnt2,cnt3,num+b[now][0]);
	if(cnt2<n/2)dfs(now+1,cnt1,cnt2+1,cnt3,num+b[now][1]);
	if(cnt3<n/2)dfs(now+1,cnt1,cnt2,cnt3+1,num+b[now][2]);
}
inline void testcase()
{
	ans=0;
	bool subA=1,subB=1;
	int cnt[3]={0,0,0};
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin>>a[i][j].val;
			a[i][j].id=j;
			b[i][j]=a[i][j].val;
		}
		if(a[i][1].val!=0||a[i][2].val!=0)subA=0;
		if(a[i][2].val!=0)subB=0;
		sort(a[i],a[i]+3);
		num[i].maxn=a[i][2].val;
		num[i].maxn_id=a[i][2].id;
		num[i].mid=a[i][1].val;
		num[i].mid_id=a[i][1].id;
		num[i].minn=a[i][0].val;
		num[i].minn_id=a[i][0].id;
	}
	if(n<=30)
	{
		dfs(1,0,0,0,0);
		cout<<ans<<'\n';
		return ;
	}
	if(subA)
	{
		vector<int>w;
		for(int i=1;i<=n;i++)
		{
			w.emplace_back(a[i][0].val);
		}
		sort(w.begin(),w.end());
		for(int i=0;i<n/2;i++)ans+=w[i];
		cout<<ans<<'\n';
		return ;
	}
//	if(subB)
//	{
//		
//	}
	sort(num+1,num+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(cnt[num[i].maxn_id]<n/2)
		{
			if(num[i].maxn==num[i].mid)
			{
				if(cnt[num[i].maxn_id]>=cnt[num[i].mid_id])
				{
					cnt[num[i].mid_id]++;
				}
				else
				{
					cnt[num[i].maxn_id]++;
				}
			}
			else
			{
				cnt[num[i].maxn_id]++;
			}
			ans+=num[i].maxn;
		}
		else
		{
			if(cnt[num[i].mid_id]<n/2)
			{
				if(num[i].minn==num[i].mid)
				{
					if(cnt[num[i].minn_id]>cnt[num[i].mid_id])
					{
						cnt[num[i].mid_id]++;
					}
					else
					{
						cnt[num[i].minn_id]++;
					}
				}
				else
				{
					cnt[num[i].mid_id]++;
				}
				ans+=num[i].mid;
			}
			else
			{
				cnt[num[i].minn_id]++;
				ans+=num[i].minn;
			}
		}
	}
	cout<<ans<<'\n';
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--)
	{
		testcase();
	}
	return 0;
}
