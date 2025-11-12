//fuck ccf
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n;
int a[maxn][4];
bool vis[maxn][4];
int ans;
void dfs(int idx,int sum)
{
	if(idx>n/2+1)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(!vis[idx+1][i])
		{
			vis[idx+1][i]=true;
			dfs(idx+1,sum+a[idx+1][i]);
			vis[idx+1][i]=false;
		}
	}
}
int main()
{
	//luogu 1938765
	//孩子们一定记得带笔
	//不然到时候有你哭的
	//这非常重要，请勿忘记
	 
	//15:16
	//我是飞舞吗 T1连暴力都不会打
	//现在还是没调出T1
	//算了去看看T2 
	//15:46
	//我怎么连最简单的dfs都不会了
	//我的原神uid:785311691
	//cnmd傻逼米哈游你妈死了
	//不知道自己写的傻逼游戏多么肝
	//新号没外挂根本没法玩累死了
	//凭啥封老子号 
	//16:00
	//完了这下真的要爆0了
	//16:29
	//全完了 
	//16:49
	//...
	//16:52
	//比起代码，我还是更关心我的原神账号 
	//17:00
	//很慌，很累
	//想回家
	//这一考场基本都很强 
	//我真的不会啊我真的不会啊我真的不会啊
	//17:36
	//还有一个小时就可以回家了，好耶 
	//17:51
	//压力有点大钢雷 
	//18:18
	//再见 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(0,0);
		cout<<ans<<'\n';
		ans=-1;
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
	}
	#define whk 0
	return whk;
}
