#include<bits/stdc++.h>
using namespace std;
const int inf=1e5+1;
long long n,m,T,num[4],p[inf][4],mx=-1;
bool ren[inf];
void dfs(long long dep,long long v)
{
	if(dep>n)
	{
		mx=max(mx,v);
		return ;
	}
	for(int i=1;i<=3;i++)
	{
		if(num[i]+1<=m)
		{
			num[i]++;
			dfs(dep+1,v+p[dep][i]);
			num[i]--;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		memset(ren,false,sizeof(ren));
		memset(num,0,sizeof(num));
		memset(p,0,sizeof(p));
		mx=-1;
		cin>>n;
		m=n/2;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				scanf("%lld",&p[i][j]);
			}
		}
		dfs(1,0);
		cout<<mx<<endl;
	}
	
	return 0;
}

