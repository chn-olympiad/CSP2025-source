#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int a[100005][10];
bool flag[100005];
struct node{int w,num,pos;}b[300005];;
bool cmp(node x,node y)
{
	return x.w>y.w;
}
int cnt[10];
long long ans;
int dfs(int step,long long q)
{
	if(step==n+1) ans=max(q,ans);
	for(int i=1;i<=3;i++)
	{
		if(cnt[i]>=n/2) continue;
		++cnt[i];
		dfs(step+1,q+a[step][i]);
		--cnt[i];
	}
	return -1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;	
		ans=0;
		memset(cnt,0,sizeof(cnt));
		memset(flag,0,sizeof(flag));
		if(n<=10)
		{
			memset(a,0,sizeof(a));
			for(int i=1;i<=n;i++)
				for(int j=1;j<=3;j++) cin>>a[i][j];
			dfs(1,0);
			cout<<ans<<"\n";
		}
		else
		{
			memset(b,0,sizeof(b));
			int t=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=3;j++)
				{
					cin>>b[++t].w;
					b[t].pos=i;
					b[t].num=j;
				}
			}
			sort(b+1,b+n*3+1,cmp);
			int tmp=0;
			for(int i=1;i<=3*n;i++)
			{
				if(cnt[b[i].num]>=n/2||flag[b[i].pos])continue;
				cnt[b[i].num]++;
				flag[b[i].pos]=1;
				ans+=b[i].w;
				tmp++;
				if(tmp==n) break;
			}
			cout<<ans<<"\n";
		}
	}
	
	return 0;
}