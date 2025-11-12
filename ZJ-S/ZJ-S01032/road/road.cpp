#include<bits/stdc++.h>
using namespace std;
const int N=1004,M=100006;
int n,m,k;
unsigned long long ans=2e9;
int mp[N][N];//记录第i座乡村与第j座城市修路的费用 
int c[M];//记录第i座乡村城市化改造的费用 
int p[M][N];//记录第i座乡村与第j座城市造新路的费用 
short b[M][N];//第记录i座城市与第j座城市造新路所连的乡村 
bool g[M][N];//记录第i座乡村与第j座城市造是否已经造过新路
bool vis[M];//记录第i座乡村是否已经改造过
bool con[N];//记录第i座城市是否已经连通 
void dfs(int st,int tr,unsigned long long pr)
//从第st座城市出发,已经连通了tr个城市,花了pr的钱
{
	if(tr==n)//已全连通
	{
//		cout<<"到第"<<st<<"座城市,终于修完了孩子们,花了"<<pr<<"的钱\n";
		ans=min(ans,pr);//取最小价格 
		return;
	} 
//	cout<<"从第"<<st<<"座城市出发,已经连通了"<<tr<<"个城市,花了"<<pr<<"的钱\n";
	//没连完 	
	for(int i=n;i>0;--i)
	{
		if(st==i)//连自己直接跳 
		{
			continue;
		}
		if(!con[i]&&mp[st][i]!=0)//第i座城市还未连通
		{
			if(b[st][i])//第st座城市到第i座城市需要连乡村
			{
				unsigned long long v=pr;//即将支付的价格 
				if(!vis[b[st][i]])//第b[st][i]座乡村没改造过
				{
					vis[b[st][i]]=true;//改
					v+=c[b[st][i]];//付钱 
				}	
				if(!g[b[st][i]][st])//第st->b[st][i]新路没有建
				{
					g[b[st][i]][st]=true;//建
					v+=p[b[st][i]][st];//付钱 
				}
				if(!g[b[st][i]][i])//第b[st][i]->i新路没有建
				{
					g[b[st][i]][i]=true;//建
					v+=p[b[st][i]][i];//付钱 
				}
				con[i]=true;//标记已连通第i座城市 
				dfs(i,tr+1,v);
				con[i]=false;//滚回来
			} 
			else//第st座城市到第i座城市需要修路
			{
				con[i]=true;//标记已连通第i座城市 
				dfs(i,tr+1,pr+mp[st][i]);
				con[i]=false;//滚回来
			}
		} 
	}
} 
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int a,e,d;
	for(int i=1;i<=n;++i)
	{
		cin>>a>>e>>d;
		mp[a][e]=mp[e][a]=d;
	}
	for(int i=1;i<=m;++i)
	{
		cin>>c[i];
		for(int j=1;j<=n;++j)
		{
			cin>>p[i][j];
		}
	}
	//输入 
	int temp;
	for(int i=1;i<=n;++i)//从第i座城市 
	{
		for(int j=i+1;j<=n;++j)//到第j座城市 
		{
			for(int u=1;u<=k;++u)//看第u座乡村  
			{
				temp=p[u][i]+p[u][j]+c[u];//造新路价格
				if(temp<=mp[i][j]||mp[i][j]==0)//比修路便宜/等价或老路不通 
				{
					mp[i][j]=mp[j][i]=temp;
					//改价格 
					b[i][j]=b[j][i]=u;
					//记录经过乡村 
				}
			}			
		}
	}
	//找更优道路(即找连乡村比修路更便宜的情况) 	
	memset(con+1,false,sizeof(con)); 
	con[1]=true;//出发标记 
	dfs(1,1,0);//go,go,go,出发喽!
	//从第i座城市出发
	cout<<ans;
	return 0;
}
