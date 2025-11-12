#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
struct edge{
	int u,v,w;
}e[1550001],e2[1550001];
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
int fa[550001];
int getfa(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=getfa(fa[x]);
}
int c[15],v[15][10005];
vector<int>eb[15];
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int i,j;
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(i=1;i<=k;i++)
	{
		cin>>c[i];
		for(j=1;j<=n;j++)
		{
			cin>>v[i][j];
		}
	}
	int ans=0x3f3f3f3f3f3f3f;
	for(int p=0;p<(1<<k);p++)
	{
		int res=0,tot=m,cnt=n;
		for(i=1;i<=m;i++)
		{
			e2[i]=e[i];
		}
		for(i=1;i<=k;i++)
		{
			if((p&(1ll<<(i-1)))!=0)
			{
				for(j=1;j<=n;j++)
				{
					e2[++tot]={i+n,j,v[i][j]};
				}
				cnt++;
				res+=c[i];
			}
		}
		sort(e2+1,e2+tot+1,cmp);
		for(i=1;i<=n+k;i++)fa[i]=i;
		for(i=1;i<=tot;i++)
		{
			int a=e2[i].u,b=e2[i].v,c=e2[i].w;
			int af=getfa(a),bf=getfa(b);
			if(af==bf)continue;
			res+=c;
			fa[af]=bf;
			cnt--;
			if(cnt==1)break;
		}
//		cout<<res<<endl;
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
} 
/*


15:22 2^k*m*log(m)的最小生成树可以做，但是32pts

15:41 我不应该B题C题反复跳的，现在两题都没思路

15:48 先kls跑最小生成树再用村替换边如何

16:45 好了，该回来写图论了

17:25 还没思路，完蛋了 

17:45 写了个2^k*(m+k*n+mlogm)的，过了大样例，但是速度一言难尽

18:00 OK,能打的都打完了，在这道花了最多时间的题上算下总分吧：
T1 100
T2 32~48
T3 50
T4 30
总 212~228
好像还行，至少水平应该和去年一样
不说了，检查去，防止爆分 
18:21 T3突然跑不了大样例4了，怀疑是爆栈，但开栈指令我好像弄错了
没事，反正4的 条件我本来就不打算过
NOIP好好打，CSP晋级就行 
*/
