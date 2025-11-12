#include <bits/stdc++.h>
using namespace std;
int T;
int n;
int w[100010][4],ans=0,rs[4],cp[100010],cp1[100010];
struct node{
	int r1=0,r2=0,r3=0,w=0;
}f[100010][4],ls[4];
bool cmp(node x,node y)
{
	return x.w>y.w;
}
void dfs(int k,int wt,int sx)
{
	if(k==n+1)
	{
		ans=max(ans,wt);
		return ;
	}if(rs[1]<sx)
		{
			rs[1]++;
			dfs(k+1,wt+w[k][1],sx);
			rs[1]--;
		}
		if(rs[2]<sx)
		{
			rs[2]++;
			dfs(k+1,wt+w[k][2],sx);
			rs[2]--;
		}
		if(rs[3]<sx)
		{
			rs[3]++;
			dfs(k+1,wt+w[k][3],sx);
			rs[3]--;
		}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)
	{
		bool p3=0,p2=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>w[i][1]>>w[i][2]>>w[i][3];
			p3=p3|((bool)(w[i][3]!=0));
			p2=p2|((bool)(w[i][2]!=0));
			f[i][1].r1=f[i][1].r2=f[i][1].r3=f[i][1].w=0;
			f[i][2].r1=f[i][2].r2=f[i][2].r3=f[i][2].w=0;
			f[i][3].r1=f[i][3].r2=f[i][3].r3=f[i][3].w=0;
		}
		if(p3==false&&p2==false)
		{
			for(int i=1;i<=n;i++)
			{
				cp[i]=w[i][2];
			}
			sort(cp+1,cp+1+n);
			int sx=n/2,ans=0;
			for(int i=n;sx>=0;i--)
			{
				ans+=cp[i];
				sx--;
			}
			cout<<ans;
			continue;
		}
		memset(rs,0,sizeof(rs));
		ans=-1;
		dfs(1,0,(int)n/2);
		cout<<ans<<'\n';
	}
	//you will know you're reborn tonight
	//3 2 2 1 1 5 1 7 1 
}

