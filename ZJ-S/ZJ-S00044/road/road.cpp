#include <bits/stdc++.h>
//long long!!!!!!!!!!!
//meitouchakankualu
using namespace std;
long long n,m,k,u,v,w,ans,cnt = 1,ans1 = 1e14;
bool vis[10005],fly[10005];
long long town[15],minc[10005];//0:jianshao
struct node
{
	int e = 666,f = 666;
};
vector <node> road[10005];
int csh[15][10005];
void dfs(int x,long long p)
{
	//return;
	////cout << "x" << x << "p" << p << "cnt" << cnt << endl;
	if (cnt == n)
	{
		//cout << "666";
		for (int i = 1;i <= k;i++)
		{
			if (csh[i][0] <= town[i])
			{
				p = p+csh[i][0]-town[i];
			}
		}
		ans1 = min(ans1,p);
		//cout << "ans" << ans1 << endl;
		return;
	}
	
	if (p > ans1 || p > minc[x]) return;
	//if (x == 2) cout << "666" << road[2].size() << minc[2];
	if (p < minc[x]) minc[x] = p;
	int num = road[x].size();
	
	for (int i = 0;i < num;i++)
	{
		//yaodao road[x][i].e
		////cout << "x zai" << x << "x qu" << road[x][i].e << "vis" << vis[road[x][i].e] << endl;
		fly[road[x][i].e] = 1;
		fly[road[x][i].e] = 1;
		int js = 1e9,name = 0;
		for (int j = 1;j <= k;j++)
		{
			if (road[x][i].f-csh[j][x]-csh[j][road[x][i].e] <= js)
			{
				js = road[x][i].f-csh[j][x]-csh[j][road[x][i].e];
				name = j;
			}
		}
		if (name == 0 || js <= 0)
		{
			if (vis[road[x][i].e] == 0)
			{
				vis[road[x][i].e] = 1;
				cnt++;
				dfs(road[x][i].e,p+road[x][i].f);
				cnt--;
				vis[road[x][i].e] = 0;
			}
		}
		else
		{
			if (vis[road[x][i].e] == 1) continue;
			////cout << "x zou town" << name << "js"<< js <<endl;
			int ku1 = csh[name][x];
			int ku2 = csh[name][road[x][i].e];
			csh[name][x] = 0;
			csh[name][road[x][i].e] = 0;
			town[name]+=(js);
			vis[road[x][i].e] = 1;
			cnt++;
			
			dfs(road[x][i].e,p+road[x][i].f);
			
			cnt--;
			vis[road[x][i].e] = 0;
			town[name]-=(js);
			csh[name][x] = ku1;
			csh[name][road[x][i].e] = ku2;
		}
	}
	for (int i = 1;i <= n;i++)
	{
		
		//road[x][i].f = (minc[x]-minc[i])
		if(i == x || fly[i] == 1) continue;
		if (x == 1)
		cout << i << "kankan" << endl;
		int js = 1e9,name = 0;
		for (int j = 1;j <= k;j++)
		{
			if ((minc[i]-minc[x])-csh[j][x]-csh[j][i] <= js)
			{
				js = (minc[i]-minc[x])-csh[j][x]-csh[j][i];
				name = j;
			}
		}
		if (name == 0 || js <= 0) continue;
		else
		{
			int ku1 = csh[name][x];
			int ku2 = csh[name][i];
			cout << "x zou town" << name << "js"<< js <<endl;
			csh[name][x] = 0;
			csh[name][i] = 0;
			town[name]+=(js);
			vis[i] = 1;
			cnt++;
			
			dfs(road[x][i].e,p+road[x][i].f);
			
			cnt--;
			vis[i] = 0;
			town[name]-=(js);
			csh[name][x] = ku1;
			csh[name][i] = ku2;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	memset(minc,0x3f3f3f3f,sizeof(minc));
	//cout << minc[1];
	cin>>n>>m>>k;
	for (int i = 1;i <= m;i++)
	{
		cin>>u>>v>>w;
		node cur;
		cur.e = v;
		cur.f = w;
		road[u].push_back(cur);
		cur.e = u;
		cur.f = w;
		road[v].push_back(cur);
	}
	for (int i = 1;i <= k;i++)
	{
		cin>>csh[i][0];
		for (int j = 1;j <= n;j++)
		{
			cin>>csh[i][j];
		}
	}
	
	vis[1] = 1;
	//dfs(zaina,feiyong,csh jianshao,csh zengjia)
	dfs(1,0);
	cout << ans1;
	/*
	//shuchusuoyulu
	for (int i = 1;i <= n;i++)
	{
		int len = road[i].size();
		for (int j = 0;j < len;j++)
		{
			cout << i << " " << road[i][j].e << " " << road[i][j].f << endl;
		}
		cout << len << endl;
	}*/
}
