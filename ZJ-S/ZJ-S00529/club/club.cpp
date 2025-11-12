//45
#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005][3],ans,cnt[3],qzh[100005];
void dfs(int dep,int add)
{
	if(dep==n+1)
	{
		ans=max(ans,add);
		return;
	}
	if(qzh[n]-qzh[dep-1]+add<ans)
	{
		return;
	}
	if(cnt[0]<n/2)cnt[0]++,dfs(dep+1,add+a[dep][0]),cnt[0]--;
	if(cnt[1]<n/2)cnt[1]++,dfs(dep+1,add+a[dep][1]),cnt[1]--;
	if(cnt[2]<n/2)cnt[2]++,dfs(dep+1,add+a[dep][2]),cnt[2]--;
}
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		qzh[0]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			qzh[i]=qzh[i-1]+max(a[i][0],max(a[i][1],a[i][2]));
		}
		ans=0;
		if(n<=200)
		{
			memset(cnt,0,sizeof(cnt));
			dfs(1,0);
		}
		else
		{
			int t[100005],tl=0;
			for(int i=1;i<=n;i++)
			{
				t[++tl]=a[i][0];
			}	
			sort(t+1,t+tl+1,cmp);
			for(int i=1;i<=n/2;i++)
			{
				ans+=t[i];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

